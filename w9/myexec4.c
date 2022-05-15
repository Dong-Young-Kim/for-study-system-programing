#include <stdio.h>
void main(){
	int x;
	x=fork();
	if(x){
		wait();
		printf("job done\n");
	}
	else{
		char *x[10];
   		x[0]="/bin/ls";
		x[1]="-l";
		x[2]=0;
   		execve(x[0], x, 0);
	}
}

