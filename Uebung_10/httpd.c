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

#define BACKLOG 1
#define BUFSIZE 64
#define REQUESTSIZE 2048

/*
FUNCTIONS FOR HANDLING HTTP REQUESTS
*/

char* getRequestPath(char* buf) {
    // Takes a raw HTTP-request.

    // Address of first "/". +1 to exclude the "/"
    char* start = strchr(buf, 47) + 1;
    char* end = strchr(start, 32); // Address of first " "
    // Length of request path.
    size_t len = end - start;
    // Allocate space for path string.
    char* requestPath = (char*) malloc(sizeof(char)*(len + 1));
    // Copy requestpath.buf
    strncpy(requestPath, start, len);
    return requestPath;
}

void sendError(int connFd) {
    char error[] = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: 20\r\nConnection: close\r\n\r\n404: File not found.";
    send(connFd, error, sizeof(error), 0);
}

void sendFile(int connFd, int fileFd, char* path) {
    int readBytes;
    char header[128];

    // Get Content-Type

    char* mime;
    char* ext = strchr(path, 46); // Get file extension. (Search ".")
    if(strcmp(ext, ".html") == 0 || strcmp(ext, ".htm")) {
        mime = "text/html; charset=utf-8";
    } else if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
        mime = "image/jpg";
    } else if (strcmp(ext, ".png") == 0) {
        mime = "image/png";
    } else if (strcmp(ext, ".ico") == 0) {
        mime = "image/ico";
    } else {
        mime = NULL;
    }
    
    // Get Content-Length from file stats.
    struct stat fileStats;
    fstat(fileFd, &fileStats);

    sprintf(header,
            "HTTP/1.0 200 OK\r\n"
            "Content-Type: %s\r\n"
            "Connection: close\r\n"
            "Content-Length: %ld\r\n\r\n",
            mime, fileStats.st_size);
    // Send header.
    send(connFd, header, strlen(header), 0);
    //send(connFd, "Hallo\r\n", 8, 0);

    // Send file.
    char fileBuf[64];
    while((readBytes = read(fileFd, fileBuf, 64)) > 0) {
        send(connFd, fileBuf, readBytes, 0);
        memset(fileBuf, 0, 64);
    }
    close(fileFd);
    send(connFd, "\r\n", 3, 0);
}

void handleRequest(int connFd, char* path) {
    int fd;

    if((fd = open(path, 0, O_RDONLY)) < 0) {
            perror("Error 404: File not found.\n");
            fd = open("404.html", 0, O_RDONLY);
            sendFile(connFd, fd, "404.html");
    } else {
        printf("Found file.\n");
        sendFile(connFd, fd, path);
    }
    close(connFd);
}

/*
FUNCTIONS FOR INITIALIZING SERVER AND CREATING CONNECTION INSTANCES
*/

int inet_aton(const char *cp, struct in_addr *addr);

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

    if((recvBytes = recv(connFd, requestBuf, REQUESTSIZE, 0)) < 0) {
        perror("Error receiving request.\n");
        exit(EXIT_FAILURE);
    } else if (recvBytes > 0) {
        printf("---RECEIVED REQUEST---\n%s\n---END OF REQUEST---\n", requestBuf);

        char* requestPath = getRequestPath(requestBuf);
        if(strcmp(requestPath, "") == 0) {
            requestPath = "index.html";
        }
        printf("Requested path: %s\n", requestPath);

        // Try to open file.
        handleRequest(connFd, requestPath);
    }

    close(connFd);
    printf("Connection closed.\n");
    return;
}

int serverRoutine(int socketFd) {

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
    
    serverRoutine(socketFd);
}