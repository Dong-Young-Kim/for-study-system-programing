#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
        int x, y;
        x = open("./sw2.wav", O_RDWR, 07777);

        lseek(x, 44, SEEK_SET);

        char buf[10];
	buf[0] = 0;
        int i;
        for (i = 0; i < 15112; i++){
            write(x, &buf, 1);
        }
}
