#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something
(e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?
*/

int main(int argc, char *argv[]) {
  int x = 100;
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    printf("I am the child (pid:%d), the variable x = %d \n", (int) getpid(), x);
    x = 3;
    printf("I changed the value of x (the child (pid:%d)), now the variable x = %d \n", (int) getpid(), x);

  }
  else { // parent process (main)
    x = 6;
    printf("I am the parent (pid:%d) of the child %d, the variable x = %d\n", (int) getpid(), rc, x);
  }
  printf("The final value of x is : %d\n", x);
  return EXIT_SUCCESS;
}
