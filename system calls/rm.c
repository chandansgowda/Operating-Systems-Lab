#include <stdio.h>

void main(){
	char filename[10];
	
	printf("Enter filename>> ");
	scanf("%s",filename);
	
	if(remove(filename)==0) 
		printf("File was removed!\n");
		
	else
		printf("File can't be removed\n");
}
