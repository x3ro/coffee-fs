#include <stdlib.h>
#include <string.h>

#include "cfs-coffee-arch.h"
#include "in-memory-backend.h"


static char memory[COFFEE_SIZE];

void xmem_pwrite(char* buf, int size, int offset) {
    memcpy(memory+offset, buf, size);
}

void xmem_pread(char* buf, int size, int offset) {
    memcpy(buf, memory+offset, size);
}

void xmem_erase(int size, int offset) {
    memset(memory+offset, 0xff, size);
}
