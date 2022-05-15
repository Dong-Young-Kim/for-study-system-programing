#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main(){
   	int x, i;
   	for(i=0;i<5;i++){
      		x=fork();
      		if (x==0){
         		int k;
         		for(k=0;k<10;k++){
            			//printf("%d-th child running %d-th iteration\n", i, k);
            			//fflush(stdout);
            			//sleep(1);
        		}
      		}
   	}
   	printf("PID: %d\n",getpid());
}
