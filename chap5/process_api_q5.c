#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?
*/

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    printf("child\n");
    int rc_wait_child = wait(NULL); // this will return -1 (error) because there are no processes to wait for
    printf("rc_wait_child : %d \n", rc_wait_child);
  }
  else {
    int rc_wait = wait(NULL); // wait returns the pid of the child process that is terminated
    printf("parent (pid : %d) of child with pid : %d and rc_wait = %d\n", (int) getpid(), rc, rc_wait);
  }
  return EXIT_SUCCESS;
}
