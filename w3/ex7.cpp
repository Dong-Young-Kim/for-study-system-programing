#include <stdio.h>
#include <iostream>
#include <string.h>

int main(){
	while(1){
		printf("Enter a string : ");
		char x[10];
		scanf("%s", x);
		std::cout << "You entered " << x << ".";
		std::cout << "length = " << strlen(x) << std::endl;
		if (!strcmp(x, "hello")){
			printf("Yes it is hello. Bye\n");
			break;
		}
		printf("NO it is not hello\n");
	}
}
		
