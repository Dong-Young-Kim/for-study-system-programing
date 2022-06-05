#include <stdio.h>
#include <signal.h>
void foo(int signum){
	printf("I am OK\n");
}
void main(){
	signal(SIGINT,foo);
	signal(15,foo);
	for(;;);
}

