#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cfs/cfs.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Please provide a value to test with as the only argument.\n");
        exit(1);
    }

    unsigned long input_length = strlen(argv[1]);

    int fd = cfs_open("foobar", CFS_READ | CFS_WRITE);
    printf("fd: %d\n", fd);

    char buf[128];
    int bytes;
    bytes = cfs_write(fd, argv[1], input_length);
    printf("bytes written: %d\n", bytes);

    int pos = cfs_seek(fd, 0, CFS_SEEK_SET);
    printf("new position: %d\n", pos);

    bytes = cfs_read(fd, buf, input_length);
    printf("bytes read: %d\n", bytes);

    buf[input_length] = '\0';

    printf("buffer after reading: '%s'\n", buf);
    printf("%s\n", buf);

    return 0;
}
