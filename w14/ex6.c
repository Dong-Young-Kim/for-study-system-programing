#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void main(){
	int x,y;
        x = fork();
        if (x==0) for(;;);  // first child
        else{
        	y=fork();
        	if (y==0) for(;;);  // second child
        }
        for(;;);     // parent
}
