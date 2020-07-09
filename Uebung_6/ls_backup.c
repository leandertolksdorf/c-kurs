#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int c, n;
    bool aFlag = false;
    bool lFlag = false;
    char* path, filename;
    struct dirent **namelist;
    void* sort = 0;
    void* hidden = 0; 
    
    // Parse options
    while((c = getopt(argc, argv, "al")) != -1) {
        switch(c) {
            case 'a':
                aFlag = true;
                break;
            case 'l':
                lFlag = true;
                break;
        }
    }
    // Was, wenn die Optionen nicht an erster Stelle stehen?
    // Parse non-option arguments (-> path)
    path = argv[optind];
    // If no path -> set to default ".".
    if (!path) {
        path = ".";
    }
    printf("> Path: %s\n", path);
    if (aFlag) {
        printf("> aFlag set.\n");
    }
    if (lFlag) {
        printf("> lFlag set.\n");
        sort = alphasort;
    }

    n = scandir(path, &namelist, NULL, alphasort);
    if (n < 0) {
        perror("Scandir");
    } else {
        for (int i = 0; i < n; i++) {
            filename = namelist[i] -> d_name;
            printf("%s\n", filename);
            free(namelist[i]);
        }
    }
    free(namelist);
    
    return 0;
}