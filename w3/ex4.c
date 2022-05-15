#include <stdio.h>
#include <string.h>

void main(){
	char x[128];
	int i;
	for (i = 0; i < 128; i++){
		x[i] = i;
	}
	for (i = 0; i < 128; i++){
		printf("%d%c%d\n", x[i], x[i], x[i]);
	}
}
