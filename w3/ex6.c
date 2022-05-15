#include <stdio.h>
#include <string.h>

void main(){
	char buff[10];
	printf("Enter a string");
	scanf("%s", buff);
	int i;
	for(i = 0; i <= strlen(buff); i++){
		printf("%c\n", buff[i]);
	}
}
