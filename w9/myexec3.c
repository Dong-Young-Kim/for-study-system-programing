#include <stdio.h>
void main(){
	char *x[10];
   	x[0]="/bin/cp";
	x[1]="f1";
	x[2]="f2";
	x[3]=0;
   	execve(x[0], x, 0);
}

