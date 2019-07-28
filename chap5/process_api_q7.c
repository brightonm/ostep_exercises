#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?
*/

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    close(STDOUT_FILENO); // close standard output of this the chid process
    printf("child\n"); // this will no be printed but the printf of the parent will be printed
  }
  else {
    int rc_wait = waitpid(rc, NULL, 0); // waitpid is useful when there are several children
    printf("parent (pid : %d) of child with pid : %d and rc_wait = %d\n", (int) getpid(), rc, rc_wait);
  }
  return EXIT_SUCCESS;
}
