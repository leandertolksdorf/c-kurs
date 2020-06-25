#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>

#define BUFSIZE 64

int inet_aton(const char *cp, struct in_addr *addr);

int main(int argc, char* argv[]) {
    struct in_addr addr;
    int socketFd, connFd, readBytes, port;
    struct sockaddr_in client;

    if(argc < 3) {
        printf("Please enter ./tcp-server <ip> <port>\n");
        exit(EXIT_FAILURE);
    } else {
        inet_aton(argv[1], &addr);
        port = atoi(argv[2]);
    }

    // Create socket
    if((socketFd = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
        printf("Client socket created.\n");
    } else {
        printf("Client socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = addr.s_addr;
    client.sin_port = htons(port);

    if((connFd = connect(socketFd, (struct sockaddr *) &client, sizeof(struct sockaddr))) < 0) {
        printf("Connection failed.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Connected to server.\n");
    }

    char sendBuf[BUFSIZE];
    char recvBuf[BUFSIZE];

    while(1) {
        do {
            readBytes = read(0, sendBuf, BUFSIZE);

            if((send(socketFd, sendBuf, readBytes, 0)) < 0) {
                printf("Error sending message.");
            } else {
                if(strcmp(sendBuf, "QUIT\n") == 0) {
                    close(socketFd);
                    exit(0);
                }
                recv(socketFd, recvBuf, BUFSIZE, 0);
                printf("%s", recvBuf);
                memset(recvBuf, 0, sizeof(recvBuf));
            }
        } while (readBytes > 0);
    }


    
}