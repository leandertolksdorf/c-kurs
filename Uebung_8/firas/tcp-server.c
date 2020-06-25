#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    if (argc <3){ 
      printf("Port and address needed \n");
      exit(0);
    }
    else if (argc>3){
      printf("Too many arguments \n");
      exit(0);
    }
    int sckt ;
    int ClientSocket;
    struct sockaddr_in srv_socket; 
    struct sockaddr_in newAddr;
    pid_t childpid;
    char buff[1024];
    int n;
    socklen_t addr_size;
    sckt = socket(AF_INET, SOCK_STREAM, 0);//creating new socket for server
    memset(&srv_socket, '\0', sizeof(srv_socket));
    
    srv_socket.sin_family = AF_INET;
    srv_socket.sin_port = htons(atoi(argv[2])); 
    srv_socket.sin_addr.s_addr=inet_addr(argv[1]);
  
    bind(sckt, (struct sockaddr*)&srv_socket, sizeof(srv_socket)); 
    
    listen(sckt, 10);
    printf("waiting for User....\n");
    while(1){
    
    ClientSocket = accept(sckt, (struct sockaddr*)&newAddr, &addr_size);//clientsocket 
    printf("Connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
    if ((childpid=fork())==0){
     while(1){
       recv(ClientSocket,buff,1024,0);//receive message
       if (strcmp(buff,"QUIT")==0){//disconnect wenn QUIT is entered
         printf("Disconnected from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
         close(ClientSocket);
         break;
       }else{
         printf("Data recieved from user(%d) : %s\n",ntohs(newAddr.sin_port),buff);//print received data
         send(ClientSocket,"Ok",strlen("OK"),0);//send Ok
         bzero(buff,sizeof(buff));
       }
     }
    } 
    } 

return 0;
}