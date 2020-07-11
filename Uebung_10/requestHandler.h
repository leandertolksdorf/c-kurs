struct response {
    char* status;
    char* contentType;
    char* connection;
    char* contentLength;
    char* content;
};

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
    struct response resp;
    
    resp.status = "Status: 200 OK\r\n";

    resp.connection = "Connection: close\r\n";

    // Get Content-Type

    char* mime;
    char* ext = strchr(path, 46); // Get file extension. (Search ".")
    if(strcmp(ext, ".html") == 0) {
        mime = "Content-Type: text/html\r\n";
    } else if (strcmp(ext, ".png") == 0) {
        mime = "Content-Type: image/png\r\n";
    }
    resp.contentType = mime;
    
    // Get Content-Length
    struct stat fileStats;
    fstat(fileFd, &fileStats);
    sprintf(resp.contentLength, "%d", (int)fileStats.st_size);

    // Get file content
    resp.content = "\r\nHallo";
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
}