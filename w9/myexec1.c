#include <stdio.h>
void main(){
	char *x[10];
   	x[0]="/bin/cat";
   	x[1]="f1";
	x[2]=0;
   	execve(x[0], x, 0);
}

