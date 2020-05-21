/*
TI3: 3. Übungsblatt - Aufgabe 2
Bearbeiter: Simon Franke, Leander Tolksdorf
Tutor: Leon Dirmeier
*/

#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    // Set index of first PID and sigNum to default.
    int first = 1;
    int sigNum = 15;
    pid_t pid;

    // Get first argument as int.
    int firstArg = atoi(argv[1]);

    // If first argument negative (-> sigNum given), increment first-index and convert firstArg for the kill-function.
    if(firstArg < 0) {
        sigNum = firstArg * (-1);
        first = 2;
    }

    // Iterate through PIDs and send desired signal.
    for(int i = first; i < argc; i++) {
        pid = atoi(argv[i]);
        kill(pid, sigNum);
    }


    return 0;
}
