#include <stdio.h>
#include <string.h>
void main(){
	int LOOP;
	for (LOOP=0;LOOP<5;LOOP++){
		int t;
		t=fork();
		if(t){
			wait();
			continue;
		}
		char buf[255];
		getcwd(buf,255);
		printf("[%s]$ ",buf);
		char *x[10]; char *tok;
		int i = 0;
		fgets(buf,255,stdin);
		buf[strlen(buf)-1]=0;
		tok=strtok(buf," ");
		for(;;){
			x[i]=tok;
			i++;
			tok=strtok(NULL," ");
			if (tok==NULL){
				x[i]=0;
				break;
			}
		}

   		execve(x[0], x, 0);
	}
}

