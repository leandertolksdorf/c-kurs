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
#define ERROR_ROUTINE(str) perror(str); exit(EXIT_FAILURE);


int main(int argc, char const *argv[])
{
    int socketFd, connFd, c, recvBytes;
    char* path = argv[1];
    char* quitCommand = "QUIT\n";
    char* msgConfirm = "OK\n";


    // Initialize socket.
    if ((socketFd = socket(AF_UNIX, SOCK_STREAM, 0)) > 0) {
        printf("Server socket initialized.\n");
    } else {
        ERROR_ROUTINE("SocketInit")
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
        ERROR_ROUTINE("SocketBind");
    }

    listen(socketFd, 1);
    if((connFd = accept(socketFd, clientPtr, &socksize)) > 0) {
        printf("Connection established.\n");
    } else {
        ERROR_ROUTINE("Connection failed");
    }

    // Lies connFd und wenn input -> Print to Stdout

    char buf[BUFSIZE];
    while(1) {
        
        do {
            memset(buf, 0, BUFSIZE);
            if ((recvBytes = recv(connFd, buf, BUFSIZE, 0)) < 0) {
                ERROR_ROUTINE("recv");
            } else {
                //send(connFd, msgConfirm, sizeof(msgConfirm), MSG_CONFIRM);
                
                if(strcmp(buf, quitCommand) == 0) {
                    memset(buf, 0, BUFSIZE);
                    close(connFd);
                    printf("Closed connection. Waiting for new one.\n");
                    listen(socketFd, 1);
                    connFd = accept(socketFd, clientPtr, &socksize);
                    break;
                }
                printf("Received: %s\n", buf);
            }
        } while (recvBytes > 0);
    }
}
