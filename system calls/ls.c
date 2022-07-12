#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

void main(int argc, char* argv[]){

	DIR *dp;
	struct dirent *dirp;
	
	if(argc<2){
		printf("Didn't pass directory path\n");
		exit(1);
	}
	
	if ((dp=opendir(argv[1]))==NULL){
		printf("Cannot Access Directory\n");
		exit(1);
	}
	
	while(dirp=readdir(dp)){
		printf("%s\n", dirp->d_name);
	}
	
	closedir(dp);
}
