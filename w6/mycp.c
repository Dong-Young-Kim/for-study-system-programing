#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main(int argc, char *argv[]){ 
	int x1, x2, y; 
	char buf[20]; 

	x1=open(argv[1], O_RDONLY, 00777);
	x2=open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 00777);
	if (x1==-1){ //exit only x1 doesn't exist
		perror("error in open");
		exit(1);
	}
	for(;;){ 
		y=read(x1, buf, 20);
		if (y==0) break;
		write(x2, buf, y);
	} 
} 

