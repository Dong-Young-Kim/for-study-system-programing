#include <stdio.h>
void main(){
	char *x[10];
   	x[0]="/bin/ls";
	x[1]="-l";
	x[2]=0;
   	execve(x[0], x, 0);
}

