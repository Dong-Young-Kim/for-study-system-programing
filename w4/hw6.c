#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
	int x;
	x = open("f3", O_RDWR | O_CREAT | O_TRUNC, 00777);
	write(x, "hello there", 11);
}

