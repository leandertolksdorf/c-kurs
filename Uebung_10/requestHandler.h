char* getRequestPath(char* buf) {
    // Takes a raw HTTP-request.

    // Address of first "/". +1 to exclude the "/"
    char* requestPathStart = strchr(buf, 47) + 1;
    char* requestPathEnd = strchr(requestPathStart, 32); // Address of first " "
    // Length of request path.
    size_t requestPathLen = requestPathEnd - requestPathStart;
    // Allocate space for path string.
    char* requestPath = (char*) malloc(sizeof(char)*(requestPathLen + 1));
    // Copy requestpath.buf
    strncpy(requestPath, requestPathStart, requestPathLen);
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
        mime = "text/html";
    } else if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
        mime = "image/jpg";
    } else if (strcmp(ext, ".png") == 0) {
        mime = "image/png";
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
            sendError(connFd);
    } else {
        printf("Found file.\n");
        sendFile(connFd, fd, path);
    }
    close(connFd);
}