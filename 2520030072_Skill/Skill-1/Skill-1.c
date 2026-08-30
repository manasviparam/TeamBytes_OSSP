#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child (PID %d) running 'ls' using exec:\n", getpid());
        execlp("ls", "ls", NULL);
    } else {
        wait(NULL);
        printf("Parent (PID %d): child has finished.\n", getpid());
    }

    return 0;
}
