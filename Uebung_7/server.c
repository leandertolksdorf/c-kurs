#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <string.h>
#define BUFSIZE 64
// Create socket and store fd

#define SERVER_PATH "/tmp/server"
#define ERROR_ROUTINE(str) perror(str); exit(EXIT_FAILURE);


int main(int argc, char *argv[])
{
    (void) argc;
    // Vars for socket, path and const msgs.
    int socketFd, connFd, recvBytes;
    char* path = argv[1];
    char* quitCommand = "QUIT\n";
    char* msgConfirm = "OK\n";


    // Initialize socket.
    if ((socketFd = socket(AF_UNIX, SOCK_STREAM, 0)) > 0) {
        printf("Server socket initialized.\n");
    } else {
        ERROR_ROUTINE("SocketInit")
    }

    // Pointers to sockaddr structs.
    socklen_t socksize;
    struct sockaddr* sockPtr;
    struct sockaddr* clientPtr;
    struct sockaddr_un server;
    struct sockaddr_un client;

    // Settings for server socket.
    memset(&server, 0, sizeof(server));
    server.sun_family = AF_UNIX;
    strncpy(server.sun_path, path, sizeof(server.sun_path) - 1);
    sockPtr = (struct sockaddr*)&server;
    clientPtr = (struct sockaddr*)&client;
    
    // Bind socket.
    if (bind(socketFd, sockPtr, sizeof(struct sockaddr)) == 0) {
        printf("Bound socket.\n");
    } else {
        ERROR_ROUTINE("SocketBind");
    }

    // Listen for incoming connections.
    listen(socketFd, 1);
    // Accept connection and save fd.
    if((connFd = accept(socketFd, clientPtr, &socksize)) > 0) {
        printf("Connection established.\n");
    } else {
        ERROR_ROUTINE("Connection failed");
    }

    // Buffer for receiving messages.
    char buf[BUFSIZE];
    // Server loop
    while(1) {
        
        do {
            // Null buffer everytime to remove already-printed characters.
            memset(buf, 0, BUFSIZE);
            if ((recvBytes = recv(connFd, buf, BUFSIZE, 0)) < 0) {
                ERROR_ROUTINE("recv");
            } else {
                // When message received -> send "OK".
                send(connFd, msgConfirm, sizeof(msgConfirm), 0);
                
                // If "QUIT" received -> close connection and listen again for a new one.
                if(strcmp(buf, quitCommand) == 0) {
                    memset(buf, 0, BUFSIZE);
                    close(connFd);
                    printf("Closed connection. Waiting for new one.\n");
                    listen(socketFd, 1);
                    connFd = accept(socketFd, clientPtr, &socksize);
                    break;
                }
                // Print received string from buffer.
                printf("%s", buf);
            }
        } while (recvBytes > 0);
    }
}
