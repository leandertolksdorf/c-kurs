#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#define _POSIX_C_SOURCE 199309L
/*
To do
- Handling cmd line option as signal number if given. (-> getops()?)
*/


int main(int argc, char const *argv[]) {
    //int sigNum = 15; // Default signal if no options given.
    int first = 1; // First PID (either 1 or if sigNum gíven -> 2)
    int sigNum = 15;
    pid_t pid;

    int firstArg = atoi(argv[1]);

    if(firstArg < 0) {
        sigNum = firstArg * (-1);
        first = 2;
    }

    //printf("%d", sigNum);
    // Iterate through PIDs.
    for(int i = first; i < argc; i++) {
        pid = atoi(argv[i]);
        kill(pid, sigNum);
    }


    return 0;
}
