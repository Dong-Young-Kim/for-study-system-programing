#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void foo(int signum){
	printf("I am OK\n");
}
void main(){
	int x,y;
	signal(1,foo);
        x = fork();
        if (x==0) for(;;);  // first child
        else{
        	y=fork();
        	if (y==0) for(;;);  // second child
        }
        for(;;);     // parent
}
