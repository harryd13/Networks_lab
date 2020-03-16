#include<stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
  
 
void func(int sockfd) 
{ 
    char buff1[MAX]; 
    char buff2[MAX];
    char buff3[MAX];
    int n; 
    
    for (;;) { 
        bzero(buff1, MAX); 
        bzero(buff2, MAX); 
        bzero(buff3, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff1,sizeof(buff1)); 
        printf("\nFrom host recieved bit1: %s", buff1); 
        bzero(buff1, MAX);

        read(sockfd, buff2,sizeof(buff2)); 
        printf("\nFrom host recieved bit2: %s", buff2); 
        bzero(buff2, MAX);

        read(sockfd, buff3,sizeof(buff3)); 
         printf("\nFrom host recieved bit3: %s", buff3); 
        bzero(buff3, MAX);
        // print buffer which contains the client contents 
        

        

       
        n = 0; 
        // copy server message in the buffer 
        printf("\nwrite yes to acknowledge: ");
        while ((buff1[n++] = getchar()) != '\n') 
            ; 
        n =0;
        printf("\nwrite yes to acknowledge: ");
        while ((buff2[n++] = getchar()) != '\n') 
            ; 
        n = 0;
        printf("\nwrite yes to acknowledge: ");
        while ((buff3[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff1, sizeof(buff1));
        write(sockfd, buff2, sizeof(buff2)); 
        write(sockfd, buff3, sizeof(buff3));
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff1, 4) == 0) { 
            printf("Exiting Server...\n"); 
            break; 
        } 
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 
