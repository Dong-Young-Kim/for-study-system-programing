#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void foo(int signum){
	int x,y;
	x=wait(&y);
	printf("child %d is removed. the exit status was %d\n",x,y);
}
void main(){
	int x,y;
	signal(SIGCHLD,foo);
        x = fork();
        if (x==0) for(;;);  // first child
        else{
        	y=fork();
        	if (y==0) for(;;);  // second child
        }
        for(;;);     // parent
}
