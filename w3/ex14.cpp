#include <stdio.h>
#include <string.h>

int main(){
	char* x[9];
	int i = 0;
	while (1) {
		printf("Enter a string : ");
		x[i] = new char[10];
		scanf("%s", x[i]);
		if (!strcmp("end", x[i])) break;
		i++;
	}
	printf("Strings entered so far are\n");
	int j;
	for (j = 0; j < i; j++)
		printf("%s ", x[j]);
}
