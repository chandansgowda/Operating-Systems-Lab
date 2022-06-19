#include<stdio.h>
#include<unistd.h>

void main(){
        printf("Before fork>> \n");  // 1
        fork();
        printf("After first fork>> \n");  // 2
        fork();
        printf("After second fork>> \n");  // 4
        fork();
        printf("After third fork>> \n"); // 8
}
