#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int chk_error1(char input[],char key[]);
int chk_error2(char input[],char key[]);

// int chk_error(char input[],char key[])
// {
//     int i,j,keylen,msglen;
//     	char temp[30],quot[100],rem[30],key1[30];
    	
//     	keylen=strlen(key);
//     	msglen=strlen(input);
//     	strcpy(key1,key);
//     	for (i=0;i<keylen-1;i++) {
//     		input[msglen+i]='0';
//     	}
//     	for (i=0;i<keylen;i++)
//     	 temp[i]=input[i];
//     	for (i=0;i<msglen;i++) {
//     		quot[i]=temp[0];

//     		if(quot[i]=='0')
//              for (j=0;j<keylen;j++)
//     		 key[j]='0'; 
             
//             else
//     		 for (j=0;j<keylen;j++)
//     		 key[j]=key1[j];

//     		for (j=keylen-1;j>0;j--) 
//             {
//     			if(temp[j]==key[j])
//     			 rem[j-1]='0';
//                 else
//     			 rem[j-1]='1';
//     		}
//     		rem[keylen-1]=input[i+keylen];
//     		strcpy(temp,rem);
//     	}
//     	strcpy(rem,temp);
//     	// printf("\nQuotient is ");
//     	// for (i=0;i<msglen;i++)
//     	//  printf("%c",quot[i]);
//     	// printf("\nRemainder is ");
//     	// for (i=0;i<keylen-1;i++)
//     	//  printf("%c",rem[i]);
//     	printf("\nFinal data is: ");
//     	for (i=0;i<msglen;i++)
//     	 printf("%c",input[i]);
//     	for (i=0;i<keylen-1;i++)
//     	 printf("%c",rem[i]);
// }

int chk_error(char input[],char key[])
{
    

   	int i,j,keylen,msglen;
    	char temp[30],quot[100],rem[30],key1[30],key2[30];
    	// clrscr();
    	// printf("Enter Data: ");
    	// gets(input);
    	// printf("Enter Key: ");
    	// gets(key);
   printf("\nget  divsor = %s , ",input);
        printf("\nget key  =  %s ,",key);
    	keylen=strlen(key);
    	msglen=strlen(input);
    	strcpy(key1,key);
        strcpy(key2,key);
    	for (i=0;i<keylen-1;i++) {
    		input[msglen+i]='0';
    	}
    	for (i=0;i<keylen;i++)
    	 temp[i]=input[i];
    	for (i=0;i<msglen;i++) {
    		quot[i]=temp[0];
    		if(quot[i]=='0')
    		 for (j=0;j<keylen;j++)
    		 key[j]='0'; else
    		 for (j=0;j<keylen;j++)
    		 key[j]=key1[j];
    		for (j=keylen-1;j>0;j--) {
    			if(temp[j]==key[j])
    			 rem[j-1]='0'; else
    			 rem[j-1]='1';
    		}
    		rem[keylen-1]=input[i+keylen];
    		strcpy(temp,rem);
    	}
    	strcpy(rem,temp);
    	printf("\nQuotient is ");
    	for (i=0;i<msglen;i++)
    	 printf("%c",quot[i]);
    	printf("\nRemainder is ");
    	for (i=0;i<keylen-1;i++)
    	 printf("%c",rem[i]);

         
         int flag = msglen+keylen-1;
         char finalans[flag];
        flag = 0;
    	printf("\nFinal data is: ");
    	for (i=0;i<msglen;i++)
        {
           
                finalans[i] = input[i];
                printf("%c \n",finalans[i]);
                flag++;
            
            
    	 
        //  printf("%c",input[i]);
         
        //  printf("%c ",finalans[i]);
        }
         printf("final ans  before remainder= %s \n",finalans);
        // flag = msglen;
        // finalans[flag] = ' ';
        for (i=0;i<keylen-1;i++)
    	{
             
            
            
                // finalans[i] = input[i];


             finalans[flag] = rem[i];flag++;
             printf("%c \n",finalans[i]);
            
            if (i==keylen-2)
            {
                break;
            }
            //  printf("%c",rem[i]);
            //  printf("%c  ",finalans[flag]);
        }
        // cfinalans;
        printf("\n");
        printf("input %s \n",input);
        printf("remainder %s \n",rem);
        flag = keylen-1+msglen;
        printf("\nfinal ans  after remainder= %s \n",finalans);
        printf("finalans last digit = %c\n",finalans[flag]);
        printf("finalans digit 0 = %c\n",finalans[0]);
        printf("finalans digit 1 = %c\n",finalans[1]);
        printf("finalans digit 2 = %c\n",finalans[2]);
        printf("finalans digit 3 = %c\n",finalans[3]);
        printf("finalans digit 4 = %c\n",finalans[4]);
        printf("finalans digit 5 = %c\n",finalans[5]);
        printf("finalans digit 6 = %c\n",finalans[6]);
        printf("finalans digit 7 = %c\n",finalans[7]);
        printf("finalans digit 8 = %c\n",finalans[8]);
        printf("finalans digit 9 = %c\n",finalans[9]);
        printf("finalans digit 10 = %c\n",finalans[10]);
        printf("finalans digit 11 = %c\n",finalans[11]);
        printf("finalans digit 12 = %c\n",finalans[12]);
        printf("finalans digit 13 = %c\n",finalans[13]);
        printf("finalans digit 14 = %c\n",finalans[14]);
        printf("finalans digit 15 = %c\n",finalans[15]);

        printf("remainder= %s ",rem);
        printf("final ans string= %s \n",finalans);
        int lengthfina_l = 0;i=0;
        flag = keylen-1+msglen;
        printf("flag = %d\n",flag);
        char finalans2[flag];
        for (size_t i = 0; i < flag; i++)
        {
            finalans2[i]= finalans[i];
        }
        

        printf("\nFinal ans2 %s",finalans2);

        printf("\nFinal2 ans again \n");
        for (size_t i = 0; i < flag; i++)
        {
            printf("%c",finalans2[i]);
        }
        
        printf("\n");
        printf(" i = %d,flag = %d ",i,flag);
        printf("key %s \n",key2);
        // strcat(input,rem);
        // printf("input %s \n",input);
        printf("WHATS");
        chk_error2(finalans,key2);
        



}


int chk_error2(char input[],char key[])
{
  
   	int i,j,keylen,msglen;
    	char temp[30],quot[100],rem[30],key1[30],key2[30],finalans[100];
        int flag = 0;
    	// clrscr();
    	// printf("Enter Data: ");
    	// gets(input);
    	// printf("Enter Key: ");
    	// gets(key);
        printf("\nget  divsor = %s , ",input);
        printf("\nget key  =  %s ,",key);
    	keylen=strlen(key);
    	msglen=strlen(input);
    	strcpy(key1,key);
        strcpy(key2,key);
    	for (i=0;i<keylen-1;i++) {
    		input[msglen+i]='0';
    	}
    	for (i=0;i<keylen;i++)
    	 temp[i]=input[i];
    	for (i=0;i<msglen;i++) {
    		quot[i]=temp[0];
    		if(quot[i]=='0')
    		 for (j=0;j<keylen;j++)
    		 key[j]='0'; else
    		 for (j=0;j<keylen;j++)
    		 key[j]=key1[j];
    		for (j=keylen-1;j>0;j--) {
    			if(temp[j]==key[j])
    			 rem[j-1]='0'; else
    			 rem[j-1]='1';
    		}
    		rem[keylen-1]=input[i+keylen];
    		strcpy(temp,rem);
    	}
    	strcpy(rem,temp);
    	printf("\nQuotient is ");
    	for (i=0;i<msglen;i++)
    	 printf("%c",quot[i]);
    	printf("\nRemainder is ");
    	for (i=0;i<keylen-1;i++)
    	 printf("%c",rem[i]);
    	printf("\nFinal data is: ");
    	for (i=0;i<msglen;i++)
        {
    	//  finalans[i] = input[i];
         printf("%c",input[i]);flag++;
        }
        
        for (i=0;i<keylen-1;i++)
    	 {
            //  finalans[flag] = rem[i];flag++;
             printf("%c",rem[i]);
        }
        // cfinalans;
        printf("\n");
        // printf("input %s \n",input);
        // printf("finalsns = %s",finalans);
        printf("\n");
        // printf("key %s \n",key2);
        // strcat(input,rem);
        // printf("input %s \n",input);
        // chk_error2(input,key2);


        



}







int main(){
    int s_sock,cli;
    char buf[100],buf1[100];
    s_sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in server,other;
    server.sin_family = AF_INET;
    server.sin_port = htons(9001);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(s_sock, (struct sockaddr*) &server, sizeof(server))==-1 )
    {
        printf("bind error");
        exit(1);
    }
    listen(s_sock,5);
    socklen_t len;
    len = sizeof(other);
    // printf("Reached %s",buf);
    cli = accept(s_sock, (struct sockaddr*)&other, &len);
    read(cli,buf,sizeof(buf));
    
    // int lenght1 = strlen(buf);
    FILE*fp;
    fp = fopen("add.txt","w");
    
    fprintf(fp,"%s", buf);
    // int lenght1 = strlen(buf);

    
    // for (size_t i = 0; i < lenght1; i++)
    // {
    //     printf("show %c \n ",buf[i]);
    // }
    printf("\nFile Recieved Succefully");
    printf("\ndata copied in add.txt file");
    fclose(fp);
    FILE *fp1;
    fp1 = fopen("add.txt", "r");
    fgets(buf1,50,fp1);
    int lenght1 = strlen(buf1);
    char data[100],divisor[100];
    int flag = 0;
    // for (size_t i = 0; i < lenght1; i++)
    // {
        
    //     if (buf1[i]==' ')
    //     {
    //         flag = 1;i++;
    //     }
    //     if (flag==0)
    //     {
    //         data[i] = buf1[i];
            
    //     }
        
    //     else
    //     {

    //         divisor[flag-1] = buf1[i];
    //     }
        
        
    // }
    int i1 =0;
    while (i1<lenght1 && buf1[i1]!= ' ')
    {
        /* code */

        data[i1] = buf1[i1];
        flag++;i1++;
    }
    i1=0;
    while (flag<lenght1)

    {
        divisor[i1] = buf1[flag+1];
        i1++;flag++;
    }
    
    
     chk_error(data,divisor);
    //  chk_error2(data,divisor);
    // printf("\n %s  ,",data2);
    fclose(fp1);
    close(s_sock);
    return 0;
}
