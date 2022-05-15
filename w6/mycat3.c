#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void show_file(char * fname);
void display_content(int x);

void main(int argc, char *argv[]){
	show_file(argv[1]); 
} 
void display_content(int x){
	char buf[20];
	int y;
	for(;;){ 
		y=read(x, buf, 20); 
		if (y==0) break; 
		write(1,buf,y);
	}
}
void show_file(char * fname){
	int x;
	x=open(fname, O_RDONLY, 00777);
	if (x==-1){
		perror("error in open");
		exit(1);
	}
	display_content(x);
}
