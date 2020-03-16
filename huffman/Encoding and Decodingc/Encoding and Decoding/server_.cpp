#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "decode.h"
char c[] = "EOF";

int main(){
  int s_socket,cli;
  char buf[10000]=" hello client";
  s_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in other,server;
  server.sin_family=AF_INET;
  server.sin_port=htons(3030);
  server.sin_addr.s_addr=INADDR_ANY;
  if(bind(s_socket,(struct sockaddr*)&server,sizeof(server))==-1){
    printf("bind error");
    exit(1);
  }
  listen(s_socket,5);
  socklen_t add;
  add=sizeof(other);
   FILE *fp;
  fp=fopen("server_inp.txt","w");
  cli=accept(s_socket,(struct sockaddr*)&other,&add);
  read(cli,buf,sizeof(buf));
  fprintf(fp,"%s\n",buf);

  while(strcmp(c,buf)){

      read(cli,buf,sizeof(buf));
      if(strcmp(buf,c)!=0)
        fprintf(fp,"%s\n",buf);
  

  }
  
 
  
  fclose(fp);
  close(s_socket);
  decodefinal();
  return 0;
}