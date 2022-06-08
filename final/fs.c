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
#include <fcntl.h>

#define SERV_TCP_PORT 27950
#define SERV_ADDR "165.246.38.152"

void handle_protocol(int x, fd_set * pset, int state[], char* fname[]);
void handle_state_1(int x, fd_set *pset, char* buf, int state[], char* fname[]);
void handle_state_2(int x, fd_set *pset, char* buf, int state[], char* fname[]);
void handle_state_3(int x, fd_set *pset, char* buf, int state[], char* fname[]);
void handle_state_4(int x, fd_set *pset, char* buf, int state[], char* fname[]);
void handle_state_5(int x, fd_set *pset, char* buf, int state[], char* fname[]);

void main(){
   int s1,s2, i, x, y;
   struct sockaddr_in serv_addr, cli_addr;
   char buf[50];
   socklen_t  xx;
   int state[50]; // state of each client (state of each client socket)
   char *fname[50];

   printf("Hi, I am the server\n");
   
   bzero((char *)&serv_addr, sizeof(serv_addr));
   serv_addr.sin_family=PF_INET;
   serv_addr.sin_addr.s_addr=inet_addr(SERV_ADDR);
   serv_addr.sin_port=htons(SERV_TCP_PORT);

   //open a tcp socket
   if ((s1=socket(PF_INET, SOCK_STREAM, 0))<0){
      printf("socket creation error\n");
      exit(1);
   }
   printf("socket opened successfully. socket num is %d\n", s1);

   // bind ip
   x =bind(s1, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
   if (x < 0){
      printf("binding failed\n");
      exit(1);
   }
   printf("binding passed\n");
   listen(s1, 5);
   xx = sizeof(cli_addr);

   // now start ping-pong-pang-pung
   // pset remembers all sockets to monitor
   // rset is the copy of pset passed to select
   fd_set rset, pset;
   int maxfd=50; // just monitor max 50 sockets

   FD_ZERO(&rset); // init rset
   FD_ZERO(&pset); // init pset

   // step 1. monitor conn req packet
   FD_SET(s1, &pset);
   // and loop on select
   for(i=0;i<20;i++){ // should be infinite loop in real life
      rset=pset;  // step 2
      select(maxfd, &rset, NULL, NULL, NULL); // step 3
      // now we have some packets
      for(x=0;x<maxfd;x++){ // check which socket has a packet
         if (FD_ISSET(x, &rset)){ // socket x has a packet
            // s1 is a special socket for which we have to do "accept"
            // otherwise do ping-pong-pang-pung
            if (x==s1){ // new client has arrived
               // create a socket for this client
               s2 = accept(s1, (struct sockaddr *)&cli_addr, &xx);
               state[s2]=1;// init the state of this client.
               printf("new cli at socket %d\n",s2);
               FD_SET(s2, &pset); // and include this socket in pset 
            }else{ // data packet. do ping-pong-pang-pung protocol
               handle_protocol(x, &pset, state, fname);
            }
         }
      }
   }
}
void handle_protocol(int x, fd_set * pset, int state[], char* fname[]){
// we have a data packet in socket x. do protocol
// we have data packet in socket x. state[x] shows the state of socket x.
// handle the protocol.
   int y; char buf[50];
   y=read(x, buf, 50); // read the data
   buf[y]=0; // make it a string
   if (state[x]==1){ // the state of this socket is 1 meaning we are 
                    // expecting "ping" from this socket
      handle_state_1(x, pset, buf, state, fname);
   }else if (state[x]==2){ // expecting "pang"
      handle_state_2(x, pset, buf, state, fname);
   }else if (state[x]==3){
      handle_state_3(x, pset, buf, state, fname);
   }else if (state[x]==4){
      handle_state_4(x, pset, buf, state, fname);
   }else if (state[x]==5){
      handle_state_5(x, pset, buf, state, fname);
   }
}
void handle_state_1(int x, fd_set *pset, char* buf, int state[], char* fname[]){
   if (strcmp(buf, "hello")==0){ 
      write(x, "download or upload?", 19);  // send pong to this client
      state[x]=2; // now we are waiting for "pang" from this client
   }else{ // no we didn't receive "ping"
      write(x, "protocol error", 14); // send err message to the client
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list. 
                       // we don't monitor socket x any more
   }
}
void handle_state_2(int x, fd_set *pset, char* buf, int state[], char* fname[]){ 
   if (strcmp(buf, "download")==0){
      write(x, "file name to download?", 22);
      state[x]=3;
   }
   else if(strcmp(buf,"upload")==0){
      write(x, "file name to upload?", 20);
      state[x]=4;
   }
   else{ 
      write(x, "protocol error", 14); // send err message to the client
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list.
                       // we don't monitor socket x any more
   }
} 
void handle_state_3(int x, fd_set *pset, char* buf, int state[], char* fname[]){ 
   if (strlen(buf)>0){
      fname[x]=buf;
      int z=open(buf,O_RDONLY,00777);
      int y=read(z,buf,50);
      write(x, buf, strlen(buf));
      close(x);
      FD_CLR(x, pset);
   }else{ 
      write(x, "protocol error", 14); // send err message to the client
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list.
                       // we don't monitor socket x any more
   }
}
void handle_state_4(int x, fd_set *pset, char* buf, int state[], char* fname[]){ 
   if (strlen(buf)>0){
      char fn[10];
      strcpy(fn,buf);
      fname[x]=fn;
      write(x, "send ", 5);
      write(x, buf, strlen(buf));
      state[x]=5;
   }else{ 
      write(x, "protocol error", 14); // send err message to the client
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list.
                       // we don't monitor socket x any more
   }
}
void handle_state_5(int x, fd_set *pset, char* buf, int state[], char* fname[]){ 
   if (strlen(buf)<50){
      printf(fname[x]);
      int z=open(fname[x],O_WRONLY | O_CREAT | O_TRUNC,00777);
      write(z, buf, strlen(buf));
      write(x, "protocol completed", 18);
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list.
   }else{ 
      write(x, "protocol error", 14); // send err message to the client
      close(x);   // end the connection
      FD_CLR(x, pset); // remove from the watch list.
                       // we don't monitor socket x any more
   }
}
