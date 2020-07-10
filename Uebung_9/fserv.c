/*
TI3: 9. Übungsblatt, 2. Aufgabe
Bearbeiter: Leander Tolksdorf, Simon Franke, Firas Drass
Tutor: Leon Dirmeier
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define BACKLOG 1
#define BUFSIZE 64

int inet_aton(const char *cp, struct in_addr *addr);

void connInstance(int connFd) {
    int recvBytes, readBytes, requestFd;
    
    char msgBuf[BUFSIZE]; // Buffer for receiving file name.
    char fileBuf[BUFSIZE]; // Buffer for file contents.

    memset(msgBuf, 0, BUFSIZE);
    recvBytes = recv(connFd, msgBuf, BUFSIZE, 0);

    if (recvBytes == -1) {
        printf("Error receiving msg.\n");
    } else if (recvBytes > 0) {

        if(strcmp(msgBuf, "QUIT\n") == 0) {
            printf("Closed connection.\n");
            close(connFd);
            return;
        }
        
        // Open file.
        requestFd = open(msgBuf, O_RDONLY);

        // Check if existing.
        if (requestFd == -1) {
            printf("File not found.\n");
        } else {

            printf("File sent.\n");
            // Send file contents.
            while((readBytes = read(requestFd, fileBuf, BUFSIZE)) > 0) {
                send(connFd, fileBuf, readBytes, 0);
                memset(fileBuf, 0, BUFSIZE);
            }
            send(connFd, "\n", 2, 0);
        }
        // Close connection.
        close(connFd);
        printf("Closed connection.\n");
        return;
    }
}
int main(int argc, char* argv[]) {
    pid_t childPid;
    struct in_addr addr;
    int socketFd, connFd, port;
    struct sockaddr_in socketAddr;

    if(argc < 3) {
        printf("Please enter ./fserv <ip> <port>\n");
        exit(EXIT_FAILURE);
    } else {

        // Adresse und Port konvertieren.
        inet_aton(argv[1], &addr);
        port = atoi(argv[2]);
    }

    // Socket erstellen
    if((socketFd = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
        printf("Server socket created.\n");
    } else {
        printf("Server socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = addr.s_addr;
    socketAddr.sin_port = htons(port);

    if((bind(socketFd, (struct sockaddr*)&socketAddr, sizeof(socketAddr))) != -1) {
        printf("Bound socket.\n");
    } else {
        printf("Sockeif ()t binding failed.\n");
        exit(EXIT_FAILURE);
    }

    if(listen(socketFd, BACKLOG) == -1) {
        printf("Error listening.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Listening on Port %d\n", port);
    }

    while(1) {
        if((connFd = accept(socketFd, NULL, NULL)) == -1) {
            perror("Error accepting connection.\n");
            exit(EXIT_FAILURE);
        } else {
            printf("Connection accepted.\n");
        }
        if((childPid = fork()) == 0) {
            // Make connection instance.
            connInstance(connFd);
        }   
    }
}
