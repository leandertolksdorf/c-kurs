#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in serveraddr;

  // socket create and varification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully created..\n");
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
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(PORT);
  }

  // connect the client socket to server socket
  if (connect(sockfd, (SA*)&serveraddr, sizeof(serveraddr)) != 0) {
    printf("connection with the server failed...\n");
    exit(0);
  }
  else
    printf("connected to the server..\n");

  // function for chat
  char buff[MAX];
  int ret;
  while (1) {
    memset(buff, 0, sizeof(buff)+1);
    printf("User Input : ");
    scanf("%s", buff);
    buff[sizeof(buff)] = 0;
    // Send input entered by user to server
    ret = write(sockfd, buff, sizeof(buff));
    if (ret == -1) {
      perror("write");
      break;
    }
    if (strcmp(buff, "QUIT") == 0){
      printf("%s\n", buff);
      close(sockfd);
      exit(0);
    }
    // wait for ok from server
    while (1){
      ret = read(sockfd, buff, sizeof(buff));
      buff[sizeof(buff)] = 0;
      if (strcmp(buff, "OK") == 0){
        printf("%s\n", buff);
        break;
      }
      else {
        perror("ERROR FROM SERVER");
        break;
      }
    }

  }

  close(sockfd);
}
