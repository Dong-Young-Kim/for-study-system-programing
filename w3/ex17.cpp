#include <stdio.h>
#include <string.h>

int main(){
	char* x[9];
	int i = 0;
	while (1) {
		printf("Enter a name : ");
		x[i] = new char[200];
		fgets(x[i], 199, stdin);
		x[i][strlen(x[i]) - 1] = 0;
		if (!strcmp("bye", x[i])) break;
		i++;
	}
	printf("There were %d names.\n", i);
	printf("The names were\n");
	int j;
	for (j = 0; j < i; j++)
		printf("%s\n", x[j]);
}
