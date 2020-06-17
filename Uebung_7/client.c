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

#define BUFSIZE 16

int main(int argc, char *argv[]) {
    int socketFd, connFd, readBytes;
    struct sockaddr *addr;
    struct sockaddr_un server;
    struct sockaddr_un client;
    char *path = argv[1];

    int socketfd, socklen;
    
    if ((socketFd = socket(AF_UNIX, SOCK_STREAM, 0)) > 0) {
        printf("Client socket initialized.\n");
    } else {
        perror("Error initializing socket.\n");
        exit(EXIT_FAILURE);
    }

    socklen_t socksize;
    struct sockaddr* sockPtr;
    struct sockaddr* clientPtr;

    memset(&client, 0, sizeof(client));

    client.sun_family = AF_UNIX;
    strncpy(client.sun_path, path, sizeof(client.sun_path) - 1);
    sockPtr = (struct sockaddr*)&server;

    if (connFd = connect(socketFd, (struct sockaddr *) &client, sizeof(struct sockaddr)) < 0) { 
        printf("Connection failed.\n"); 
        exit(EXIT_FAILURE); 
    } 
    else {
        printf("Connected to server using fd %d\n", connFd);
    }

    char* buf = malloc(BUFSIZE);
    // Schreibe nach connFd.
    while(1) {
        do {
            readBytes = read(0, buf, BUFSIZE);
            if ((send(socketFd, buf, readBytes, NULL)) < 0) {
                perror("Error");
            } else {
                printf("Sent %d bytes.\n",readBytes);
            }
        } while (readBytes > 0);
    }
}

int sendMsg(int socket, void *buffer, size_t length) {
    char* ptr = (char*) buffer;
    while(length > 0) {
        int sendBytes = send(socket, ptr, length, NULL);
        ptr += sendBytes;
        length -= sendBytes;
    }
    return 1;
}