#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
        int x1, x2, y;
        x1 = open("./swvader03.wav", O_RDONLY, 07777);
        x2 = open("./sw3.wav", O_RDWR, 07777);

	lseek(x1, 44 + 15112, SEEK_SET);
        lseek(x2, 44, SEEK_SET);

        char buf[10];
        int i;
        for (i = 0; i < 15112; i++){
           	y = read(x1, buf, 1);
		write(x2, buf, y);
        }
}
