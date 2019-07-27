#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?
*/

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    printf("child\n");
    char *myargs[3];
    myargs[0] = strdup("/bin/ls");
    myargs[1] = strdup(".");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    printf("This shouldn't print out\n");
  }
  else {
    waitpid(rc, NULL, 0);
    printf("parent\n");
  }
  return EXIT_SUCCESS;
}
