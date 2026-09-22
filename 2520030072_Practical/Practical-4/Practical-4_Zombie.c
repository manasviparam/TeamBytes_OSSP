#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();

    if(pid == 0)
    {
        printf("child process %d", getpid());
        exit(0);
    }
    else
    {
        printf("parent process %d", getpid());
        sleep(30);
        wait(NULL);
        printf("Parent process completed");
    }
}
