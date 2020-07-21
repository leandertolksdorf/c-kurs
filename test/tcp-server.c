//Some information is used from https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <zconf.h>
#define SA struct sockaddr
#define PORT 8080


int main(int argc, char *argv[])
{
    int socketfd, connectionfd;
    int ret;
    socklen_t len;
    struct sockaddr_in serveraddr, client;


    // socket create and verification
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    memset(&serveraddr, 0, sizeof(serveraddr));

    // assign IP, PORT
    serveraddr.sin_family = AF_INET;
    if (argc == 2) {
      // store this IP address in sa:
      inet_pton(AF_INET, argv[1], &(serveraddr.sin_addr));
      serveraddr.sin_port = htons(PORT);
    }
    else if (argc == 3){
      // store this IP address in sa:
      inet_pton(AF_INET, argv[1], &(serveraddr.sin_addr));
      serveraddr.sin_port = htons((unsigned short)strtoul(argv[2], NULL, 10));
    }
    else {
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(PORT);
    }

    // Binding newly created socket to given IP and verification
    if ((bind(socketfd, (SA*)&serveraddr, sizeof(serveraddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    // Now server is ready to listen and verification
    if ((listen(socketfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Waiting for client..\n");
    len = sizeof(client);

    while (1) { // Handle multiple clients using multiprocessing
      // Accept the data packet from client and verification

      connectionfd = accept(socketfd, (SA *)&client, &len);
      if (connectionfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
      }

      pid_t pid = fork();
      if (pid == 0) {
        char buff[sizeof(INET_ADDRSTRLEN)];
        // infinite loop for chat
        while (1) {
          memset(buff, 0, sizeof(buff)+1);
          // read the message from client and copy it in buffer
          ret = read(connectionfd, buff, sizeof(buff));
          buff[sizeof(buff)] = 0;
          if (ret == -1){
            perror("read");
            exit(EXIT_FAILURE);
          }
          write(1, buff , sizeof(buff));

          if (strcmp(buff, "QUIT") == 0){
            close(connectionfd);
            close(socketfd);
            exit(0);
          }
          ret = write(connectionfd, "OK", sizeof("OK"));

          // if msg contains "Exit" then server exit and chat ended.
          if (ret == -1) {
            perror("write");
            exit(EXIT_FAILURE);
          }
        }
      }
      else {
        continue;
      }

    }
}
