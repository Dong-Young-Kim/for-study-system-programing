#include <stdio.h>
#include <string.h>
void main(){
	printf("command> ");
	char *x[10]; char *tok; char buf[255];
	int i = 0;
	fgets(buf,255,stdin);
	buf[strlen(buf)-1]=0;
	tok=strtok(buf," ");
	printf("...myexec execs to \"");
	for(;;){
		x[i]=tok;
		printf("%s ",x[i]);
		i++;
		tok=strtok(NULL," ");
		if (tok==NULL){
			x[i]=0;
			break;
		}
	}

	printf("\"\n");
   	execve(x[0], x, 0);
}

