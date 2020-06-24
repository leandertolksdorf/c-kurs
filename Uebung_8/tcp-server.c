#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 1
#define BUFSIZE 64

int main(int argc, char* argv[]) {
    in_addr_t addr;
    int socketFd, connFd, recvBytes, port;
    struct sockaddr_in socketAddr, clientAddr;

    if(argc < 3) {
        printf("Please enter ./tcp-server <ip> <port>\n");
        exit(EXIT_FAILURE);
    } else {
        inet_aton(argv[1], &addr);
        port = atoi(argv[2]);
    }

    // Create socket
    if((socketFd = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
        printf("Server socket created.\n");
    } else {
        printf("Server socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = addr;
    socketAddr.sin_port = htons(port);

    if((bind(socketFd, (struct sockaddr*)&socketAddr, sizeof(socketAddr))) != -1) {
        printf("Bound socket.\n");
    } else {
        printf("Socket binding failed.\n");
        exit(EXIT_FAILURE);
    }

    if(listen(socketFd, BACKLOG) == -1) {
        printf("Error listening.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Listening on Port %d\n", port);
    }

    int clientSize = sizeof(clientAddr);
    if((connFd = accept(socketFd, (struct sockaddr*)&clientAddr, &clientSize)) == -1) {
        perror("Error accepting connection.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Connection accepted.\n");
    }

    char buf[BUFSIZE];
    while(1) {
        do {
            memset(buf, 0, BUFSIZE);
            if ((recvBytes = recv(connFd, buf, BUFSIZE, 0)) < 0) {
                printf("Error receiving.\n");
                exit(EXIT_FAILURE);
            } else {
                send(connFd, "OK\n", 4, 0);

                if(strcmp(buf, "QUIT\n") == 0) {
                    memset(buf, 0, BUFSIZE);
                    close(connFd);
                    printf("Closed connection.\n");
                    return 0;
                }

                printf("%s", buf);
            }
        } while (recvBytes > 0);
    }
    
}