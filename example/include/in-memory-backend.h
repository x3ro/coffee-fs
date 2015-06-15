#ifndef IN_MEMORY_BACKEND_H
#define IN_MEMORY_BACKEND_H

void xmem_pwrite(char* buf, int size, int offset);
void xmem_pread(char* buf, int size, int offset);
void xmem_erase(int size, int offset);

#endif
