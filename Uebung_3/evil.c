#define _POSIX_C_SOURCE 199309L

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Define handlers for SIGINT and SIGTERM

void sigIntHandler(int sigNum) {
    (void) sigNum;
    char* msg = "sigIntHandler: Böse Nachricht\n";
    write(STDOUT_FILENO, msg, strlen(msg));
}

void sigTermHandler(int sigNum) {
    (void) sigNum;
    char* msg = "sigTermHandler: Böse Nachricht\n";
    write(STDOUT_FILENO, msg, strlen(msg));
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

    // Print PID continually.
    while(1){
        printf("PID: %d | Endlosschleife\n", getpid());
        nanosleep(&sleep, (struct timespec *)NULL);
    }

    return 0;
}
