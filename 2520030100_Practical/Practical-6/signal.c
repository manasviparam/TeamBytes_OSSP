#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int count = 0;

void handler(int sig)
{
    if(sig == SIGINT)
        printf("SIGINT received\n");

    else if(sig == SIGTERM)
        printf("SIGTERM received\n");

    else if(sig == SIGUSR1)
        printf("SIGUSR1 received\n");

    count++;

    if(count == 3)
    {
        printf("All signals received. Exiting...\n");
        _exit(0);
    }
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);

    printf("Process ID = %d\n", getpid());
    printf("Waiting for signals...\n");

    while(1)
    {
        pause();
    }

    return 0;
}
