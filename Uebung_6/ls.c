/*
TI3: 6. Übungsblatt
Bearbeiter: Leander Tolksdorf, Simon Franke
Tutor: Leon Dirmeier
*/

#define _POSIX_C_SOURCE 200809L
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

int filterHidden(const struct dirent *dir) {
    // Returns 1 if file not hidden.
    return (dir -> d_name[0] != '.');
}

void printStats(struct stat stats) {
    // Prints size and last modified time.
    char* lastModified = ctime((const time_t*) (&stats.st_mtim));
    printf("Size: %ld | Last modified: %s", stats.st_size, lastModified);
}

int main(int argc, char *argv[]) {
    // struct for filenames
    struct dirent **namelist;
    // struct for file stats
    struct stat statbuf;
    // dirStream for getting path fd.
    DIR *dirStream;
    int c, option, dirFd;
    // path to list
    const char* path;
    // Default functions for scandir cmp and sort.
    int (*showAll)(const struct dirent *) = filterHidden;
    int (*sort)(const struct dirent **, const struct dirent **) = NULL;
    bool lFlag = false;

    // Parse options
    while((option = getopt(argc, argv, "al")) != -1) {
        switch(option) {
            case 'a':
                showAll = NULL;
                break;
            case 'l':
                sort = alphasort;
                lFlag = true;
                break;
        }
    }
    // Parse path. If none -> default: "."
    path = argv[optind];
    if(!path) {
        path = ".";
    }

    // If error while scandir -> Print that error.
    if((c = scandir(path, &namelist, showAll, sort)) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return errno;
    }
    
    // Get fd of directory for stats
    if (c >= 0) {
        for (int i = 0; i < c; i++) {
            //filename = namelist[i] -> d_name;
            printf("%s ", namelist[i] -> d_name);
            // If l-flag set: print also metadata:
            if(lFlag) {
                // Get directory stream for path
                dirStream = opendir(path);
                // Get directory fd from dirStream.
                dirFd = dirfd(dirStream);
                // Write stats to statbuf and print.
                if (fstatat(dirFd, namelist[i] -> d_name, &statbuf, O_RDONLY) == 0) {
                    printStats(statbuf);
                }
            }
            free(namelist[i]);
        }
        free(namelist);
    }
    return 0;
}