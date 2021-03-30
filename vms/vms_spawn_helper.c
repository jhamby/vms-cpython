#include "vms_spawn_helper.h"
#include <string.h>
#include <builtins.h>

#define MAX_SPAWN 256
unsigned int    _vms_spawn_pid[MAX_SPAWN];
int             _vms_spawn_status[MAX_SPAWN];
unsigned int    _vms_spawn_finished[MAX_SPAWN];

static unsigned long _finished = 1;
static unsigned long _table_init = 0;   // 0 - uninitialized, 1 - initialization, 2 - initializes

static int _init_pos(int pos, unsigned int **pppid, int **ppstatus, unsigned int **ppfinished) {
    _vms_spawn_pid[pos] = -1;
    _vms_spawn_status[pos] = -1;
    _vms_spawn_finished[pos] = 0;
    *pppid = _vms_spawn_pid + pos;
    *ppstatus = _vms_spawn_status + pos;
    *ppfinished = _vms_spawn_finished + pos;
    return 0;
}

int vms_spawn_alloc(unsigned int **pppid, int **ppstatus, unsigned int **ppfinished) {
    // init table
    if (__CMP_SWAP_LONG(&_table_init, 0, 1)) {
        memset(_vms_spawn_pid, 0, sizeof(_vms_spawn_pid));
        memset(_vms_spawn_status, -1, sizeof(_vms_spawn_status));
        memset(_vms_spawn_finished, 0, sizeof(_vms_spawn_finished));
        ++_table_init;
    } else {
        while(_table_init == 1) {
            ;
        }
    }
    // find empty pid
    while(1) {
        int pos = -1;
        unsigned int oldest = 0xffffffff;
        for(int i = 0; i < MAX_SPAWN; ++i) {
            if (__CMP_SWAP_LONG(_vms_spawn_pid + i, 0, -1)) {
                // found an empty position
                return _init_pos(i, pppid, ppstatus, ppfinished);
            }
            if (_vms_spawn_finished[i] == 0) {
                // pid is set, process is not finished
                continue;
            }
            // pid is set, process is finished, so find the oldest
            if (_vms_spawn_finished[i] < oldest) {
                pos = i;
                oldest = _vms_spawn_finished[pos];
            }
        }
        if (pos == -1) {
            // no free positions, no finished process, do another try
            continue;
        }
        // found the oldest finished process, which retcode is not poped, so overwrite it
        if (__CMP_SWAP_LONG(_vms_spawn_finished + pos, oldest, 0)) {
            return _init_pos(pos, pppid, ppstatus, ppfinished);
        }
        // someone beat us here, do another try
    }
    return 1;
}

int vms_spawn_finish(unsigned int *pfinished) {
    if (pfinished >= _vms_spawn_finished && pfinished < _vms_spawn_finished + MAX_SPAWN) {
        *pfinished = __ATOMIC_INCREMENT_LONG(&_finished);
        if (*pfinished == 0) {
            // regenerate generations, from 1 to MAX
            for(int i = 0; i < MAX_SPAWN; ++i) {
                _vms_spawn_finished[i] = __ATOMIC_INCREMENT_LONG(&_finished);
            }
            // set current as latest
            *pfinished = __ATOMIC_INCREMENT_LONG(&_finished);
        }
        return 0;
    }
    return 1;
}

/* Returns 0 if PID is found
*/
int vms_spawn_status(unsigned int pid, int *pstatus, int free) {
    for(int i = 0; i < MAX_SPAWN; ++i) {
        if (_vms_spawn_pid[i] == pid) {
            if (pstatus) {
                *pstatus = _vms_spawn_status[i];
            }
            if (free) {
                _vms_spawn_finished[i] = 0;
                _vms_spawn_pid[i] = 0;
            }
            return 0;
        }
    }
    return 1;
}
