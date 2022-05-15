#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main(int argc, char *argv[]){ 
	int i;
	for (i=1; i<argc; i++){
		
		int x,y; 
		char buf[20]; 

		x=open(argv[i], O_RDONLY, 00777);
		if (x==-1){
			perror("error in open");
			break; //replace exit to break
		}
		for(;;){ 
			y=read(x, buf, 20);
			if (y==0) break;
			write(1, buf, y);
		} 
	}
} 

