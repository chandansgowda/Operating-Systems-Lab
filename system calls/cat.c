//Simulation of cat command

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]){
	FILE *fp;
	char c;
	
	if (argc<2) printf("Didn't pass filename!\n");
	
	fp=fopen(argv[1],"r");
	
	do{
		c = fgetc(fp);
		printf("%c",c);
	}while(c!=EOF);
		
	fclose(fp);
}
