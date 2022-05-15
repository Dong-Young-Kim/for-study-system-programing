#include <stdio.h>
#include <string.h>

void main(){
	char x[10];
	printf("Enter a string : ");
	scanf("%s", x);

	char x1[10], x2[10], x3[10];
	strcpy(x1, x);
	strcpy(x2, x);
	strcpy(x3, x);
	x1[0] = 'a';
	x2[0] = 'b';
	x3[0] = 'c';
	printf("After copying and changing the first letter\n");
	printf("%s ", x1);
	printf("%s ", x2);
	printf("%s ", x3);

}
