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
			int k;
			for(k=0;k<7;k++){
				char tmp[50];
				sprintf(tmp,"%s/%s",envp[k],argv[0]);
				//printf("%s\n",tmp);
           			y=execve(tmp, argv, 0); 
			
			}
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
