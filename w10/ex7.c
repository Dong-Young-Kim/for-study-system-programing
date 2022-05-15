#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
void tokenize(char *buf, char *tokarr[]);
void main(){ 
	int x,y,status,i;
    	char *buf; 
    	char *argv[15]; char *envp[15];
    	char *tok;
	for(i=0;i<10;i++){
        	buf=getenv("PATH");
		tokenize(buf,envp);
       		printf("$");		
       		fgets(buf,50,stdin);
       		buf[strlen(buf)-1]=0;
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
           		y=execve(argv[0], argv, envp); 
           		if (y<0){
              			perror("exec failed"); 
              			exit(1); 
           		}
       		} else if(no_amph) wait(&status); 
    	}  
} 

void tokenize(char *buf, char *tokarr[]){
        char *tok;
        tok=strtok(buf,":");
        int t=0;
        for(;;){
		tokarr[t]=tok;
                t++;
                tok=strtok(NULL,":");
                if(tok==NULL){
			tokarr[t]=0;
                        break;
                }
        }
}
