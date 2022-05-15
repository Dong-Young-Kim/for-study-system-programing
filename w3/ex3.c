#include <stdio.h>
#include <string.h>

void main(){
	char x[10];
	int i;
	for (i = 0; i < 10; i++){
		x[i] = i + 97;
	}
	for (i = 0; i < 10; i++){
		printf("%d %c\n", x[i], x[i]);
	}
}
