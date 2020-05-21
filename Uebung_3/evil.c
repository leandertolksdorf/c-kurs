#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

//#define _POSIX_C_SOURCE 199309L

/*
To do
- Convert handler prints to write calls.

*/

// Define handlers for SIGINT and SIGTERM

void sigIntHandler(int sigNum) {
    (void) sigNum;
    printf("sigIntHandler: Böse Nachricht\n");
}

void sigTermHandler(int sigNum) {
    (void) sigNum;
    printf("sigTermHandler: Böse Nachricht\n");
}

int main()
{
    // Define structs for SIGINT- and SIGTERM-handling.
    struct sigaction sigInt;
    struct sigaction sigTerm;
    struct timespec sleep;

    // Set sa_handler to corresponding handler-functions.
    sigInt.sa_handler = &sigIntHandler;
    sigTerm.sa_handler = &sigTermHandler;

    // Set sleep time to 2 seconds.
    sleep.tv_sec = 2;
    sleep.tv_nsec = 0;

    // Declare procedure on SIGINT and SIGTERM-signals.
    sigaction(SIGINT, &sigInt, NULL);
    sigaction(SIGTERM, &sigTerm, NULL);

    int pid = getpid();
    printf("Hallo");

    // Print PID continually.
    while(1){
        
        //write(STDOUT_FILENO, pid, sizeof(pid));
        write(STDOUT_FILENO, "Endlosschleife\n", 15);
        nanosleep(&sleep, (struct timespec *)NULL);
    }

    write(STDOUT_FILENO, "Endlosschleife\n", 15);

    return 0;
}
