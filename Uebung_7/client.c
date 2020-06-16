#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int socketFd, connFd;
    struct sockaddr *addr;
    struct sockaddr_un server;
    struct sockaddr_un client;
    char *path = argv[1];
    char *input;

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

    // Schreibe nach connFd.
    while(1) {
        printf("Waiting for input\n");
        scanf("%s", &input);
        printf("%s", input);
    }
}
