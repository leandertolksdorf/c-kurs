#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define _POSIX_C_SOURCE 199309L

// Define handlers for SIGINT and SIGTERM

void sigIntHandler(int sigNum) {
    printf("sigIntHandler: Böse Nachricht\n");
}

void sigTermHandler(int sigNum) {
    printf("sigTermHandler: Böse Nachricht\n");
}

int main(int argc, char const *argv[])
{
    int pid = getpid();

    // Define structs for SIGINT- and SIGTERM-handling.
    struct sigaction sigInt;
    struct sigaction sigTerm;
    struct timespec sleep;

    // Set sa_handler to corresponding handler-functions.
    sigInt.sa_handler = &sigIntHandler;
    sigTerm.sa_handler = &sigTermHandler;

    // Set sleep time to 2 seconds.
    sleep.tv_sec = 2;

    // Declare procedure on SIGINT and SIGTERM-signals.
    sigaction(SIGINT, &sigInt, NULL);
    sigaction(SIGTERM, &sigTerm, NULL);

    // Print PID continually.
    while(1){
        printf("Endlosschleife | PID: %d\n", pid);
        nanosleep(&sleep, NULL);
    }

    return 0;
}
