#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
	int x1, x2, x3, x4, y, file_size; char buf[256];
	struct stat tmp_stat;
	x1 = open("f9", O_RDONLY, 00777);
	fstat(x1, &tmp_stat);
	file_size = tmp_stat.st_size;
	x2 = open("f91", O_RDWR | O_CREAT | O_TRUNC, 00777);
	x3 = open("f92", O_RDWR | O_CREAT | O_TRUNC, 00777);
	x4 = open("f93", O_RDWR | O_CREAT | O_TRUNC, 00777);

	y = read(x1, buf, file_size / 3);
  	write(x2, buf, y);

	y = read(x1, buf, file_size / 3);
  	write(x3, buf, y);
	
	y = read(x1, buf, file_size - 2*(int)(file_size / 3));
  	write(x4, buf, y);
	
	printf("f9 is split into f91, f92, and f93");
}

