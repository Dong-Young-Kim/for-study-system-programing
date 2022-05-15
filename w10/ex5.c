#include <stdio.h> 
#include <unistd.h> 
#include <string.h>

void main(){ 
	int x,y,status,i;
    	char buf[50]; 
    	char *argv[10]; 
    	char *tok;
    	for(i=0;i<10;i++){
       		printf("$");
       		fgets(buf,50,stdin);
       		buf[strlen(buf)-1]=0; 
       		argv[0]=buf; 
       		argv[1]=0; 
       		if(!strcmp(buf,"exit")) exit(0);
       		tok=strtok(buf," ");
		int t=0;
		int no_amph = 1;
       		for(;;){
			argv[t]=tok;
			if(!strcmp(tok,"&")){ no_amph = 0; t--;}
			t++;
			tok=strtok(NULL," ");
			if(tok==NULL){
				argv[t]=0;
				break;
			}
       		}
       		x=fork(); 
       		if (x==0){ 
           		//printf("I am child to execute %s\n", buf); 
           		y=execve(argv[0], argv, 0); 
           		if (y<0){
              			perror("exec failed"); 
              			exit(1); 
           		}
       		} else if(no_amph) wait(&status); 
    	}  
} 

