#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
   int x, y; unsigned char buf[16], tmp[20];
   printf("Enter file name\n");
   scanf("%s", tmp);
   x = open(tmp, O_RDONLY, 00777);
   for (;;){
	   y = read(x, buf, 16);
	   if(y==0) break;
	   int i;
	   for(i = 0; i < y; i++) //repeat as y
		   printf("%x ", buf[i]);
	   printf("\n");
   }
}

