#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 16 // Define size of buffer.
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char const *argv[]) {

    // Define vars for file descriptor, for-counter, for-end and new-line.
    int fd, i;
    const int size = argc;
    const char nl = '\n';
    const char* file_error = "File not found.\n";
    ssize_t readBytes;

    // Allocate memory for buffer.
    char *buf = malloc(BUFFERSIZE);
    // If filenames given, read files. Else read from STDIN.

    if(argc != 1) {
        // Iterate over Arguments (files).
        for(i=1; i < size; i++) {
            // Save file descriptor of i-th file to fd.
            fd = open(argv[i], O_RDONLY);
            // If file doesn't exist:  return error.
            if (fd == -1) {
                write(STDERR, file_error, 16);
                return -1;
            }
            
            do {
                // Read from fd to buffer. Save number of read bytes.
                readBytes = read(fd, buf, BUFFERSIZE);
                // Write read bytes to file-descriptor 1 (stdout).
                write(STDOUT, buf, readBytes);
                // Repeat until end of file.
            } while (readBytes != 0);
            // New line after file.
            write(STDOUT, &nl, 1);
        }
    } else {
        do {
            readBytes = read(STDIN, buf, BUFFERSIZE);
            write(STDOUT, buf, readBytes);
        } while (readBytes != 0);
    }

    return 0;
}