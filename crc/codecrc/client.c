#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <netdb.h>
#include<ctype.h>

int main(int argc,char *argv[]){
    int c_sock;
    char buf[100];
    c_sock = socket(AF_INET, SOCK_STREAM,0);
    struct hostent *server;
    struct sockaddr_in client;
    // client.sin_family = AF_INET;
    // client.sin_port = htons(9000);
    // client.sin_addr.s_addr = INADDR_ANY;
    // if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    // {
    //     printf("connection error");
    //     exit(1);
    // }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &client, sizeof(client));
    client.sin_family = AF_INET;
    bcopy((char *)server->h_addr,  (char *)&client.sin_addr.s_addr,  server->h_length);
    client.sin_port = htons(9002);
    if (connect(c_sock,(struct sockaddr *) &client,sizeof(client)) < 0)
        printf("ERROR connecting");




    FILE *fp;
    fp = fopen("text.txt", "r");
    //client is scanning
    // fscanf(fp, "%s",buf);
    // while (fgets(buf,50,fp))
    // {
    //     /* code */
    //      printf(" \ncode %s",buf);
    // }
    fgets(buf,50,fp);
    // printf(" \ncode %s",buf);
    int lenght1 = strlen(buf);
    buf[lenght1-1] = '\0'; 
    int flag1 = 0;
    int tmep1;
    printf("Length = %d\n",lenght1 );
    for (size_t i = 0; i < lenght1; i++)
    {
        printf("show %c \n ",buf[i]);
        tmep1 = buf[i];
        if (tmep1<48 || tmep1>57)
        {
          flag1++;
          printf("flag here %d\n",flag1 );
        }
        if (flag1>1)
        {
          break;
        }
    }

    write(c_sock, buf, sizeof(buf));
    printf("\nfile send succesfully");
    fclose(fp);
    close(c_sock);
    return(0);
}
