#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    char copybuff[MAX];
    int n; 
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("\nEnter the packet : "); 
        n = 0; 

        while ((buff[n++] = getchar()) != '\n');
        strcpy(copybuff,buff);
        h:
        write(sockfd, copybuff, sizeof(copybuff)); 
        bzero(buff, sizeof(buff)); 

        printf("\nWaiting for ACK...\n");
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff);
        if ((strncmp(buff, "yes", 3)) == 0) { 
            printf("\nAcknowledged ... sending another bit\n");
            bzero(copybuff, sizeof(copybuff)) ;
        }
        else
        {
            printf("sending bits again...\n");
            goto h;
        }
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 