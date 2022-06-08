#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <signal.h>

#define SERV_TCP_PORT 27950
#define SERV_ADDR "165.246.38.152"

void main(){
   int x,y;
   struct sockaddr_in serv_addr;
   char buf[50];
   printf("Hi, I am the client\n");
   
   bzero((char *)&serv_addr, sizeof(serv_addr));
   serv_addr.sin_family=PF_INET;
   serv_addr.sin_addr.s_addr=inet_addr(SERV_ADDR);
   serv_addr.sin_port=htons(SERV_TCP_PORT);

   //open a tcp socket
   if ((x=socket(PF_INET, SOCK_STREAM, 0))<0){
      printf("socket creation error\n");
      exit(1);
   }
   printf("socket opened successfully. socket num is %d\n", x);

   //connect to the server
   if (connect(x, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
      printf("can't connect to the server\n");
      exit(1);
   }
   
   int k;
   k=fork();
   
   if(k==0){
      //receive
      int i;
      for(i=0;i<10;i++){
         y=read(x, buf, 50);
         buf[y]=0;
         printf("server : %s\n", buf);
      }
   }
   else{
      //send
      int i;
      for(i=0;i<10;i++){
         fgets(buf,255,stdin);
         buf[strlen(buf)-1]=0;
         write(x, buf, strlen(buf));
         if(!strcmp(buf,"bye")){
            kill(k,9);
            break;
         }
      }
   }

   close(x);  // disconect the communication
}
