#include <sys/socket.h>
#include<sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include<arpa/inet.h>
int main(int argc, char *argv[])
{
   if (argc <3){
      printf("Socketname needed \n");
      exit(0);
    }
    else if (argc>3){
      printf("Too many arguments \n");
      exit(0);
    }
    int clientsckt ;
    clientsckt=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in srv_socket; 
    char buffer[1024];
    char buff[1024];
    memset(&srv_socket, '\0', sizeof(srv_socket)); 

    srv_socket.sin_family = AF_INET;
    srv_socket.sin_port = htons(atoi(argv[2])); 
    srv_socket.sin_addr.s_addr=inet_addr(argv[1]);


    int cnt=connect(clientsckt,(struct sockaddr*)&srv_socket,sizeof(srv_socket));//connect socket
    if (cnt==-1){
        printf("problem Connecting \n");
        exit(0);
    }
    printf("Connected To server \n");
    while(1){
         printf("User Input:  \n");
         scanf("%s",&buff[0]);//get the message from Terminal
         send(clientsckt,buff,strlen(buff),0);//send it to sever
         if (strcmp(buff, "QUIT")==0){//check for QUIT
           close(clientsckt);
           printf("Disconnected from server\n");
           exit(0);
         }
         sleep(1);//to make it fel more real
         printf("Data sent \n");

         if (recv(clientsckt,buffer,1024,0)<0){
           printf("error in Receiving Data. \n");
         }
         else{
           sleep(1);
           printf("Status: %s \n",buffer);
        }
}
return 0;
}
   