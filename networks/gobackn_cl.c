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
    char buff1[MAX]; 
    char buff2[MAX]; 
    char buff3[MAX]; 
    char copybuff1[MAX];
    char copybuff2[MAX];
    char copybuff3[MAX];
    int n; 
    for (;;) { 
        bzero(buff1, sizeof(buff1)); 
        bzero(buff2, sizeof(buff2)); 
        bzero(buff3, sizeof(buff3)); 
        printf("\nEnter the packet 1: "); 
        n = 0; 

        while ((buff1[n++] = getchar()) != '\n');
        strcpy(copybuff1,buff1);
        printf("\nEnter the packet 2: ");
        n = 0;
        while ((buff1[n++] = getchar()) != '\n');
        strcpy(copybuff2,buff2);

        printf("\nEnter the packet 3: ");
        n = 0;
        while ((buff1[n++] = getchar()) != '\n');
        strcpy(copybuff3,buff3);

        h1:
        write(sockfd, copybuff1, sizeof(copybuff1)); 
        bzero(buff1, sizeof(buff1));
        write(sockfd, copybuff2, sizeof(copybuff2)); 
        bzero(buff2, sizeof(buff2)); 
        write(sockfd, copybuff3, sizeof(copybuff3)); 
        bzero(buff3, sizeof(buff3));

        printf("\nWaiting for ACKp[1]...\n");
        read(sockfd, buff1, sizeof(buff1)); 
        printf("From Server : %s", buff1);
        if ((strncmp(buff1, "yes", 3)) == 0) { 
            printf("\nAcknowledged p[1] ... sending another bit\n");
            bzero(copybuff1, sizeof(copybuff1)) ;
        }
        else
        {
            printf("sending bits again...\n");
            goto h1;
        }
        printf("\nWaiting for ACK p[2]...\n");
        read(sockfd, buff2, sizeof(buff2)); 
        printf("From Server : %s", buff2);
        if ((strncmp(buff2, "yes", 3)) == 0) { 
            printf("\nAcknowledged ... sending another bit\n");
            bzero(copybuff2, sizeof(copybuff2)) ;
        }
        else
        {
            printf("sending bits again...\n");
            goto h1;
        }
        printf("\nWaiting for ACKp[3]...\n");
        read(sockfd, buff3, sizeof(buff3)); 
        printf("From Server : %s", buff3);
        if ((strncmp(buff3, "yes", 3)) == 0) { 
            printf("\nAcknowledged ... sending another bit\n");
            bzero(copybuff3, sizeof(copybuff3)) ;
        }
        else
        {
            printf("sending bits again...\n");
            goto h1;
        }
        if ((strncmp(buff1, "exit", 4)) == 0) { 
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