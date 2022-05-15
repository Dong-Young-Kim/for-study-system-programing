#include <stdio.h>
#include <string.h>

void main() {
   char * strarr[10]={NULL};
   strarr[0]="hello";
   //strcpy(strarr[1],"bye");
   strarr[1] = "bye";
   printf("%s %s\n", strarr[0], strarr[1]);
}

