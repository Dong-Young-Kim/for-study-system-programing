#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main(int argc, char *argv[]){ 
	int x,y; 
	char buf[20]; 

	x=open(argv[1], O_RDONLY, 00777);
	if (x==-1){
		perror("error in open");
		exit(1);
	}
	for(;;){ 
		y=read(x, buf, 20);
		if (y=0) break;
		write(1, buf, y);
	} 
} 

