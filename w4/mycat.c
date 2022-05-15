#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
   int x, y; char buf[20], tmp[20];
   printf("Enter file name\n");
   scanf("%s", tmp);
   x = open(tmp, O_RDONLY, 00777);
   for (;;){
	   y = read(x, buf, 20);
	   if(y==0) break;
	   write(1, buf, y);//standard output
   }
}

