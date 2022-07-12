#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void main(){

	pid_t child_pid, my_pid, parent_pid;
	
	child_pid = fork(); //child_pid will be set to 0 if fork was successful
	
	if (child_pid<0){
		printf("Fork Failed\n");
		exit(1);
	}
	
	if (child_pid==0){
		my_pid = getpid();
		parent_pid = getppid();
		printf("[CHILD] My pid is: %d\n",my_pid);
		printf("[CHILD] My parent pid is: %d\n", parent_pid);
		
		
	printf("[CHILD] Sleeping for 10 seconds\n");
	sleep(10); //simply giving time for parent to complete execution and call exit
	
	printf("[CHILD] My Parent ended. So I am an orphan process adopted by init process\n");
		
	}
	
	else{
	
	printf("[PARENT] This is parent process\n");
	my_pid = getpid();
	printf("[PARENT] My pid is: %d\n",my_pid);
	
	printf("[PARENT] Exiting...\n");
	exit(0);
	
	}
	
}
