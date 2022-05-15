#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char *argv[]){
	int i;
	int totalSize = 0;
	struct stat fileStat;
	for (i = 1; i < argc; i++){
		int x = open(argv[i], O_RDONLY, 00777);
		fstat(x, &fileStat);
		int fileSize = fileStat.st_size;
		totalSize += fileSize;
		printf("%s: %d bytes\n", argv[i], fileSize);
	}
	printf("The total size %d\n", totalSize);
}
