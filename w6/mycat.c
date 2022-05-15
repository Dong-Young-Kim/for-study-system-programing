#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void docopy(char*, char*);
void show_cat(char*);
void show_xxd(char*);
void show_passwd();
void show_dir(char*);

void main(int argc, char *argv[]){
	char buf[20]; 
	if (strcmp(argv[1],"-o")==0){ // copy option. copy argv[2] to argv[3]
      		docopy(argv[2], argv[3]);
   	}
	else if (strcmp(argv[1],"-x")==0){ // xxd option
      		show_xxd(argv[2]);	
   	}
	else if (strcmp(argv[1],"-p")==0){
		show_passwd();
	}
	else if (strcmp(argv[1],"-d")==0){
		show_dir(argv[2]);
	}
	else {
		show_cat(argv[1]);
	}
}

void docopy(char *f1, char *f2){ // copy f1 to f2
	int x1 = open(f1, O_RDONLY, 00777); // input file
   	int x2 = open(f2, O_WRONLY|O_CREAT|O_TRUNC, 00777); // output file
	int y;
	if (x1==-1){
		perror("error in open");
		exit(1);
	}
	char buf[20];
	for(;;){
		y=read(x1, buf, 20);
		if (y==0) break;
		write(x2, buf, y);
	} 
}
void show_cat(char * fname){
	int x; 
   	x=open(fname, O_RDONLY, 00777);
   	if (x==-1){
       		perror("error in open");
       		exit(1);
   	}
	char buf[20];
   	int y;
   	for(;;){ 
       		y=read(x, buf, 20); 
       		if (y==0) break; 
      	 	write(1, buf, y); 
   	} 
}

void show_xxd(char * fname){
	int x; 
   	x=open(fname, O_RDONLY, 00777);
   	if (x==-1){
       		perror("error in open");
       		exit(1);
   	}
	char buf[16];
   	int y;
   	for(;;){ 
       		y=read(x, buf, 16); 
       		if (y==0) break; 
		int i;
		for(i=0;i<y;i++)
			printf("%x ", buf[i]);
      	 	printf("\n");
   	} 
}
void show_passwd(){
	FILE *f;
	char buf[256];
	f=fopen("/etc/passwd","r");
	while(fgets(buf,256,f)!=0){
		char *token;
		buf[strlen(buf)-1]=0;
		token=strtok(buf,":");
		printf("id %s  ",token);
		token=strtok(NULL,":");
		printf("passwd %s  ",token);
		token=strtok(NULL,":");
		printf("uid %s  ",token);
		token=strtok(NULL,":");
		printf("gid %s  ",token);
		token=strtok(NULL,":");
		printf("desc %s  ",token);
		token=strtok(NULL,":");
		printf("home %s  ",token);
		token=strtok(NULL,":");
		printf("p %s\n",token);
	}
}
void show_dir(char* dname){
	DIR* d;
	struct dirent* de;
	d=opendir(dname);
	while(de = readdir(d))
		printf("%s\n",de->d_name);
	closedir(d);
}
