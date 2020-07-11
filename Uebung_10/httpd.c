/*
TI3: 10. Übungsblatt, 2. Aufgabe
Bearbeiter: Leander Tolksdorf, Simon Franke, Firas Drass
Tutor: Leon Dirmeier
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <signal.h>
#include "requestHandler.h"

#define BACKLOG 1
#define BUFSIZE 64
#define REQUESTSIZE 2048

int inet_aton(const char *cp, struct in_addr *addr);

/*
Methoden:

main() {
    - Addresse und Port aus CL parsen.
    socketFd = socketInit(address, port)
    connFd = listenForConnection(socketFd)
    while(1) {
        if (childPid = fork() == 0) {
            connInstance(connFd);
        }
    }
}

socketInit(adress, port) {
    - Server socket erstellen.
    - Server socket binden.
    return socketFd
}

listenForConnection(socketFd) {
    - Listen auf socketFd.
    - Wenn Verbindung angefordert: Accepten
    return connFd
}

connInstance(connFd) {
    - Dateinamen aus Anfrage parsen.
    - Datei vorhanden?
        - DateiFD getten.
        - sendFile(DateiFD)
    - Datei nicht vorhanden?
        - sendError(404)
}

handleRequest(requestBuf) {
    - erstes "/" finden
    
}

sendSuccess(int fd) {
    - Metadaten holen
        - Content-Type (stat???)
        - Content-Length (stat.)
        - Status = 200
        - Connection: Close
    - Metadaten senden
    - Eigentliche Datei (CONTENT) senden -> sendFile(fd);
    - Connection closen
}

sendFile(int fd) {
    - Buffer initialisieren
    while readBytes > 0:
        - read()
        - send()
        - buffer nullen
}

sendError(int error) {
    - Error-Header generieren
    - und senden.
    - Connection closen.
}
*/

void termHandler(int connFd) {
    close(connFd);
    printf("Closed connection\n");
}

int initSocket(struct in_addr address, int port) {
    struct sockaddr_in socketAddr;
    int socketFd;

    // Save settings to sockaddr struct.
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr = address;
    socketAddr.sin_port = htons(port);

    // Create socket.
    if((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Bind to socketFd.
    if((bind(socketFd, (struct sockaddr *)&socketAddr, sizeof(socketAddr))) < 0) {
        perror("Socket binding failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Bound socket to socket-fd: %d\n", socketFd);

    return socketFd;
}

void connInstance(int connFd) {
    int recvBytes;
    char requestBuf[REQUESTSIZE];
    //char helloWorld[] = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\nConnection: close\r\n\r\nHello, world!\n";

    if((recvBytes = recv(connFd, requestBuf, REQUESTSIZE, 0)) < 0) {
        perror("Error receiving request.\n");
        exit(EXIT_FAILURE);
    } else if (recvBytes > 0) {
        printf("---RECEIVED REQUEST---\n%s\n---END OF REQUEST---\n", requestBuf);

        char* requestPath = getRequestPath(requestBuf);
        memset(requestBuf, 0, REQUESTSIZE);
        printf("Requested path: %s\n", requestPath);

        // Try to open file.
        handleRequest(connFd, requestPath);
    }

    close(connFd);
    printf("Connection closed.\n");
    return;
}

int listenForConnections(int socketFd) {

    int connFd;
    
    // Listen for incoming connection on socketFd.
    if((listen(socketFd, BACKLOG)) < 0) {
        perror("Error listening for connection.\n");
        exit(EXIT_FAILURE);
    }

    printf("Listening.\n");

    // Accept incoming connection.
    while(1) {
        if((connFd = accept(socketFd, NULL, NULL)) < 0) {
            perror("Error accepting connection.\n");
            exit(EXIT_FAILURE);
        }

        signal(SIGINT, termHandler);

        printf("Connection accepted.\n");

        if(fork() == 0) {
            connInstance(connFd);
        }
    }
}


int main(int argc, char* argv[]) {

    // Check arguments
    if (argc < 3) {
        printf("Please enter ./httpd <ip> <port>\n");
        exit(EXIT_FAILURE);
    }

    struct in_addr addr; // for parsing address.

    inet_aton(argv[1], &addr); // Convert argument ip and save to addr. struct
    int port = atoi(argv[2]);  // Convert argument port to int.

    int socketFd = initSocket(addr, port);
    
    listenForConnections(socketFd);
}