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
		
		printf("[CHILD] Exiting...\n");
		exit(0); //notice that we are exitting child process here but not calling wait in parent process
	}
	
	printf("[PARENT] This is parent process\n");
	my_pid = getpid();
	printf("[PARENT] My pid is: %d\n",my_pid);
	
	printf("[PARENT] Sleeping for 10 seconds\n");
	sleep(10); //simply giving time for child to complete execution and call exit
	
	printf("[PARENT] Child (pid=%d) has ended, but it has an entry in the process table.It is a zombie process\n", child_pid);
	
}
