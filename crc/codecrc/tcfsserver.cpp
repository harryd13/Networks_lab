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
      printf("\nget  divsorlength = %d , ",msglen);
           printf("\nget keylength  =  %d ,",keylen);
    	strcpy(key1,key);
        strcpy(key2,key);
        // strcpy(key1,key);
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
         printf("%c",input[i]);
        for (i=0;i<keylen-1;i++)
         printf("%c",rem[i]);


         int flag = msglen+keylen-1;
         char finalans[flag];


      printf("\nrem = %s",rem);
    	printf("\nFinal data is: \n");
    	// for (i=0;i<msglen;i++)
        // {

        //         finalans[i] = input[i];
        //         printf("%c",input[i]);
        //         flag++;
        // }
        // for (size_t i = 0; i < keylen-1; i++)
        // {
        //     printf("%c",rem[i]);
        // }

        for (int i = 0; i < flag; i++)
        {
            if (i<msglen)
            {
                finalans[i] = input[i];
            }
            else{
                finalans[i] = rem[i-msglen];
            }
             printf("%c",finalans[i]);
             if (i==flag-1)
             {
                 finalans[i+1] = '\0';
                 break;
             }
        }
        printf("\nfinal ans = %s",finalans);
        finalans[2]= 1;






        chk_error2(finalans,key2);




}


int chk_error2(char input[],char key[])
{

   	int i,j,keylen,msglen;
    	char temp[30],quot[100],rem[30],key1[30],key2[30],finalans[100];
        // int flag = 0;
    	// clrscr();
    	// printf("Enter Data: ");
    	// gets(input);
    	// printf("Enter Key: ");
    	// gets(key);
        printf("\n_____getting divsor = %s , ",input);
        printf("\n_____getting key  =  %s ,",key);
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
    	printf("\n_____Quotient is ");
    	for (i=0;i<msglen;i++)
    	 printf("%c",quot[i]);
    	printf("\n_____Remainder is ");
    	// for (i=0;i<keylen-1;i++)
    	//  printf("%c",rem[i]);
    	// printf("\nFinal data is: ");
         int flag = 0;
    	// for (i=0;i<msglen;i++)
        // {
    	// //  finalans[i] = input[i];
        //  printf("%c",input[i]);//flag++;
        // }

        for (i=0;i<keylen-1;i++)
    	 {
            //  finalans[flag] = rem[i];flag++;
             printf("%c",rem[i]);
             if (rem[i]!='0')
             {
                 flag = 1;
             }
        }
        // cfinalans;
        printf("\n");
        // printf("input %s \n",input);
        // printf("finalsns = %s",finalans);
        printf("\n");
        if (flag==1)
        {
            printf("\nXXXXXXXXXCode not correctXXXXXXXXXXX \n");

        }
        else{
            printf("\n|||||||Code correctly verified||||||||| \n");
        }
        // printf("key %s \n",key2);
        // strcat(input,rem);
        // printf("input %s \n",input);
        // chk_error2(input,key2);

    // 1011101 1011





}







int main()
{
    int s_sock,cli;
    char buf[100],buf1[100];
    s_sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in server,other;
    server.sin_family = AF_INET;
    server.sin_port = htons(9002);
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
    printf("\n______File Recieved Succefully__________");
    printf("\n______data copied in add.txt file_______");
    fclose(fp);
    FILE *fp1;
    fp1 = fopen("add.txt", "r");
    fgets(buf1,50,fp1);
    printf("\n\n ----data = %s----" ,buf1);
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
        if (buf1[i1]==' ')
        {
          data[i1]='\0';
          break;
        }

    }
    i1=0;
    while (flag+i1+1<lenght1)

    {
        divisor[i1] = buf1[flag+i1+1];
        i1++;
        if (flag+i1+1 == lenght1)
        {
          divisor[i1]='\0';
          break;
        }

    }


     chk_error(data,divisor);
    //  chk_error2(data,divisor);
    // printf("\n %s  ,",data2);
    fclose(fp1);
    close(s_sock);

    return 0;
}
