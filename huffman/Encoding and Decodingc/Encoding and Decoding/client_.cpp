#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "huffman.h"
#include <unistd.h>
int xptr;

int main(){
  int c_socket;
  char buf[10000]=" hello server";
  c_socket=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in client;
  memset(&client,0,sizeof(client));
  client.sin_family=AF_INET;
  client.sin_port=htons(3030);
  client.sin_addr.s_addr=INADDR_ANY;
  if (connect(c_socket,(struct sockaddr*)&client,sizeof(client))==-1) {
    printf("Connection issue\n");
    exit(1);
  }
  //
  string g= "fromharmantotarun";
  string encoded=encoder(g);
  //
  FILE *fp;
  fp=fopen("encinfo.txt","r");
  xptr=fscanf(fp,"%s",buf);
  while(xptr!=EOF)
  {
  write(c_socket,buf,sizeof(buf));
  xptr=fscanf(fp,"%s",buf);
  }
  strcpy(buf,"EOF");
  if(xptr==EOF)
    {
        write(c_socket,buf,sizeof(buf));
    }
  fclose(fp);
  close(c_socket);
  return 0;
}