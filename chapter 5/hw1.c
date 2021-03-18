#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main (int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    int x = 100; // set x = 100;
    if (rc < 0)
    {
        fprintf(stderr, "fork fialed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        x = 99; // change x's value
        printf("In the child process, x=%d\n",x);
    } else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",rc, wc, (int) getpid());
    }
    printf("In the parent process,x=%d\n",x);
    return 0;
}