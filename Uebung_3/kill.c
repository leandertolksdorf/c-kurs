#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    int first = 1;
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
