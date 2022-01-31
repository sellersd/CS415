#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
  pid_t pid;

  /* fork a child process */
  pid = fork();

  if(pid < 0) { /* error */
    fprintf(stderr, "Fork failed");
    return 1;
  }
  else if(pid == 0) { /* child */
    execlp("/bin/ls", "ls", NULL);
  }
  else { /* parent process */
    //wait(NULL);
    printf("Child Complete\n");
  }

}
