#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 16 // Define size of buffer.

int main(int argc, char const *argv[]) {

    // Define vars for file descriptor, for-counter, for-end and new-line.
    int fd, i;
    const int size = argc;
    char nl = '\n';
    ssize_t readBytes;

    // Allocate memory for buffer.
    char *buf = malloc(BUFFERSIZE);

    // Iterate over Arguments (files).
    for(i=1; i < size; i++) {
        // Save file descriptor of i-th file to fd.
        fd = open(argv[i], O_RDONLY);
        
        do {
            // Read from fd to buffer. Save number of read bytes.
            readBytes = read(fd, buf, BUFFERSIZE);
            // Write read bytes to file-descriptor 1 (stdout).
            write(1, buf, readBytes);
            // Repeat until end of file.
        } while(readBytes != 0);
        // New line after file.
        write(1, &nl, 1);
    }

    return 0;
}