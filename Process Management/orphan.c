//Orphan process
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  pid_t child_pid, my_pid, parent_pid;
  child_pid = fork();
  if (child_pid < 0)
  {
  printf("Fork failed. Exiting!\n");
  exit(0);
  }
  if (child_pid == 0)
  {
  // Child process
  printf("[CHILD] This is the child process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[CHILD] My pid is %d\n", my_pid);
  printf("[CHILD] My parent's pid is %d\n", parent_pid);
  printf("[CHILD] Sleeping for 10 seconds.\n");
  sleep(10);
  printf("[CHILD] My parent ended. So I am an orphan process adop>
  }
  else
  {
  // Parent process
  printf("[PARENT] This is the parent process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[PARENT] My pid is %d\n", my_pid);
  printf("[PARENT] My parent's pid is %d\n", parent_pid);
  printf("[PARENT] Exiting.\n");
  exit(0);
  }
return 0;
}
