#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>



//error function call to terminate the session
void error (const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc , char *argv[])//file name and port number
{
    if(argc < 2)
    {
        fprintf(stderr , "port no not provided.program terminated\n");
        exit(1);
    }
    int sockfd , newsockfd ,portno , n;
    char buffer[255];

    struct sockaddr_in serv_addr ,cli_addr;
    socklen_t clilen;//32 bit datatype in socket.h

    sockfd = socket(AF_INET , SOCK_STREAM,0);
    if(sockfd < 0)
    {
        error("Socket function failed");

    }
    bzero((char *) &serv_addr , sizeof(serv_addr));//clears data

    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd ,(struct sockaddr *) &serv_addr , sizeof(serv_addr)) < 0)
        error("Binding Failed.");
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd , (struct sockaddr *)  &cli_addr , &clilen);

    if(newsockfd < 0)
    error("error on Accept");

   int num1,num2,answer,choice;
  S :  n = write(newsockfd,"Enter number 1: ",strlen("Enter number 1"));
   if(n<0) error("Error writing to socket");
   read(newsockfd, &num1 , sizeof(int));
   printf("client number-1 = : %d",num1);

   n = write(newsockfd,"Enter number 2: ",strlen("Enter number 2"));
   if(n<0) error("Error writing to socket");
   read(newsockfd, &num2 , sizeof(int));
   printf("client number-2 = : %d",num2);

   n = write(newsockfd,"Enter your choice :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.exit\n",strlen("Enter your choice :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.exit\n"));
   if(n < 0) error("Error Writion to the socket");
   read(newsockfd,&choice,sizeof(int));
   printf("client - choice is : %d\n", choice);

   switch(choice)
   {
       case 1:
       answer = num1 + num2;
       break;

       case 2:
       answer = num1 - num2;
       break;

       case 3:
       answer = num1 * num2;
       break;


       case 4:
       answer = num1 / num2;
       break;

       case 5:
       goto Q;
       break;
   }

   write(newsockfd , &answer ,sizeof(int));
   if(choice != 5)
   goto S;

  Q :   close(newsockfd);
    close(sockfd);
    return 0;
    
}