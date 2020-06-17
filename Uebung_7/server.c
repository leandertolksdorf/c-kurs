#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <string.h>
#define BUFSIZE 16
// Create socket and store fd

#define SERVER_PATH "/tmp/server"

int main(int argc, char const *argv[])
{
    int socketFd, c, recvBytes;
    char* path = argv[1];


    // Initialize socket.
    if ((socketFd = socket(AF_UNIX, SOCK_STREAM, 0)) > 0) {
        printf("Server socket initialized.\n");
    } else {
        perror("Error initializing socket.\n");
        exit(EXIT_FAILURE);
    }

    socklen_t socksize;
    struct sockaddr* sockPtr;
    struct sockaddr* clientPtr;

    struct sockaddr_un server;
    memset(&server, 0, sizeof(server));
    server.sun_family = AF_UNIX;
    strncpy(server.sun_path, path, sizeof(server.sun_path) - 1);
    sockPtr = (struct sockaddr*)&server;
    
    if (bind(socketFd, sockPtr, sizeof(struct sockaddr)) == 0) {
        printf("Bound socket.\n");
    } else {
        perror("Error binding socket.\n");
    }

    listen(socketFd, 1);
    int connFd = accept(socketFd, clientPtr, &socksize);
    printf("Connected\n");

    // Lies connFd und wenn input -> Print to Stdout

    char buf[BUFSIZE];
    while(1) {
        
        do {
            memset(buf, 0, BUFSIZE);
            if ((recvBytes = recv(connFd, buf, BUFSIZE, 0)) < 0) {
                printf("Error");
                break;
            } else {
                printf("Received: %s\n", buf);
            }
        } while (recvBytes > 0);
    }

}
