#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
   int x1, x2, y;
   char buf[50];

   x1=open("f1", O_RDONLY, 00777);
   x2=open("f2", O_RDWR | O_CREAT | O_TRUNC, 00777);
   y=read(x1, buf, 20);
   write(x2, buf, y);
   return 0;
}
