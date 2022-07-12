#include <stdio.h>
#include <unistd.h> // to use fork()

void main(){

	printf("Before fork\n");
	fork();
	printf("After first fork\n"); //2 times
	fork();
 	printf("After second fork\n"); //4 times
	fork();
	printf("After third fork\n"); //8 times
	
}
