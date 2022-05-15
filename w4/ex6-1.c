#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
   int x, y;
   char buf[50];

   x=open("f1", O_RDONLY, 00777);
   y=read(x, buf, 20);
   write(1, buf, 20);
   return 0;
}
