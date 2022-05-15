#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>

void main(){ 
    	char *buf; 
	char *tok;
	buf=(char*)getenv("PATH");
       	tok=strtok(buf,":");
	int t=0;
       	for(;;){
		printf("%s\n",tok);
		t++;
		tok=strtok(NULL,":");
		if(tok==NULL){
			break;
		}
       	}
} 

