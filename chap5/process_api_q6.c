#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
Write a slight modification of the previous program, this time using
waitpid() instead of wait(). When would waitpid() be
useful?
*/

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    printf("child\n");
  }
  else {
    int rc_wait = waitpid(rc, NULL, 0); // waitpid is useful when there are several children
    printf("parent (pid : %d) of child with pid : %d and rc_wait = %d\n", (int) getpid(), rc, rc_wait);
  }
  return EXIT_SUCCESS;
}
