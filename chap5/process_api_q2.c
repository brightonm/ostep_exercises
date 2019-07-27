#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

int main(int argc, char *argv[]) {
  FILE *f;
  f = fopen("./file.tmp", "w");
  if (f == NULL) {
    fprintf(stderr, "open file failed\n");
    exit(1);
  }
  int rc = fork();
  if (rc < 0) { // fork failed exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) { // child (new process)
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);
    printf("I am the child (pid:%d), I can access the file descriptor : %p\n", (int) getpid(), f);
  }
  else {
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);
    printf("I am the parent (pid:%d) of the child %d, I can access the file descriptor : %p\n", (int) getpid(), rc, f);
  }
  fclose(f);
  return EXIT_SUCCESS;
}
