#include <stdio.h>
#include <string.h>

void main(){

	char fn[10], pat[10], temp[200];
	FILE *fp;
	
	printf("Enter filename>> ");
	scanf("%s",fn);
	printf("Enter pattern>> ");
	scanf("%s",pat);
	
	fp=fopen(fn,"r");
	
	while(!feof(fp)){
		fgets(temp,100,fp);
		if(strstr(temp,pat)) printf("%s",temp);
	}
	
	fclose(fp);
}
