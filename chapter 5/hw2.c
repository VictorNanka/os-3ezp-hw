#include <fcntl.h>    // open
#include <stdio.h>    // fgetc, fopen, fclose
#include <stdlib.h>   // exit
#include <string.h>   // strlen
#include <sys/stat.h> // S_IRWXU
#include <sys/wait.h>
#include <unistd.h> // fork, write, close

int
main(int argc, char *argv[])
{
    int fd = open("./2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    
    if (rc < 0)
    {
        fprintf(stderr, "fork fialed\n");
        exit(1);
    } else if (rc == 0) {
        write(fd, "child writes a line.\n", strlen("child writes a line.\n"));
        printf("file descriptor in child process: %d\n", fd); 
    } else {
        write(fd, "parent writes a line.\n", strlen("parent writes a line.\n"));
        printf("file descriptor in parent prosess: %d\n", fd);
    }
    return 0;
}