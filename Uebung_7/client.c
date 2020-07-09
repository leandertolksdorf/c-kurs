#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFSIZE 64

int main(int argc, char *argv[]) {
    // Vars for socket, connection, confirmation message etc.
    (void) argc;
    int socketFd, connFd, readBytes;
    struct sockaddr_un client;
    char* path = argv[1];
    char msgConfirm[4];
    
    // Try to init. socket.
    if ((socketFd = socket(AF_UNIX, SOCK_STREAM, 0)) > 0) {
        printf("Client socket initialized.\n");
    } else {
        perror("Error initializing socket.\n");
        exit(EXIT_FAILURE);
    }

    // Settings for client sockaddr struct.
    memset(&client, 0, sizeof(client));
    client.sun_family = AF_UNIX;
    strncpy(client.sun_path, path, sizeof(client.sun_path) - 1);

    // Try to connect to socket.
    if ((connFd = connect(socketFd, (struct sockaddr *) &client, sizeof(struct sockaddr))) < 0) { 
        printf("Connection failed.\n"); 
        exit(EXIT_FAILURE); 
    } 
    else {
        printf("Connected to server using fd %d\n", connFd);
    }

    // Buffer for received messages.
    char* buf = malloc(BUFSIZE);
    // Client connection loop
    while(1) {
        do {
            // Read from stdin
            readBytes = read(0, buf, BUFSIZE);
            // Send message to socket and wait for confirmation msg from server.
            if ((send(socketFd, buf, readBytes, 0)) < 0) {
                perror("Error");
            } else {
                recv(socketFd, msgConfirm, BUFSIZE, 0);
                printf("%s", msgConfirm);
                memset(msgConfirm, 0, sizeof(msgConfirm));
            }
        } while (readBytes > 0);
    }
}