#include <stdio.h> 
#include <unistd.h> 
#include <string.h>

void main(){ 
   int x,y,status,i;
   char buf[50]; 
   char *argv[10]; 

   for(i=0;i<10;i++){
      printf("$"); 
      scanf("%s", buf); 
      argv[0]=buf; 
      argv[1]=0; 

      x=fork(); 
      if (x==0){ 
          printf("I am child to execute %s\n", buf); 
          y=execve(buf, argv, 0); 
          if (y<0){ 
             perror("exec failed"); 
             exit(1); 
          } 
      } else wait(&status); 
   } 
} 

