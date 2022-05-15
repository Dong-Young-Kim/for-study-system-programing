#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
   int x1, x2, y; char buf[20], tmp1[20], tmp2[20];
   printf("Enter src file name\n");
   scanf("%s", tmp1);
   x1 = open(tmp1, O_RDONLY, 00777);
   printf("Enter dest file name\n");
   scanf("%s", tmp2);
   x2 = open(tmp2, O_RDWR | O_CREAT | O_TRUNC, 00777);
   for (;;){
	   y = read(x1, buf, 20);
	   if(y==0) break;
	   write(x2, buf, y);
   }
   printf("%s is copied into %s successfully.\n", tmp1, tmp2);
}

