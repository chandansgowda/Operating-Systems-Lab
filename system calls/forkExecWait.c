#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(){

	pid_t child_pid, my_pid, parent_pid, wait_pid;
	
	int i = 10; //used to show that i wont change in parent even though its changed in child process
	
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
		
		printf("[CHILD] i= %d\n",--i);
		
		printf("[CHILD] Child process going to load another program using execlp system call\n");
		execlp("pwd","pwd", NULL); //we are running pwd (print working directory) using child process
	}
	
	printf("[PARENT] This is parent process\n");
	my_pid = getpid();
	printf("[PARENT] My pid is: %d\n",my_pid);
	
	printf("[PARENT] Waiting for child to terminate\n");
	wait_pid = wait(NULL); //Here, code inside above if statement starts execution
	
	printf("Resuming after the termination of %d\n",wait_pid);
	printf("My child's PID was : %d\n",child_pid);
	
	printf("[PARENT] i= %d\n",++i); //even though i has been decremented by child, it wont change the i in parent process
	
}
