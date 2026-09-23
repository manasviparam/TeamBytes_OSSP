#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main()
{
    int fd[2];
    pipe(fd);
    int pid,data;
    int start,end;
    double timetaken;

    pid = fork();
    start = clock();

    if(pid == 0)
    {
        printf("consumer");
        close(fd[1]);

        for(int i=0;i<5;i++)
        {
            read(fd[0], &data, sizeof(data));
            printf("Consumed %d",data);
        }

        close(fd[0]);
    }
    else
    {
        printf("producer ");

        close(fd[0]);

        for(int i=1;i<=5;i++)
        {
            data = i*10;
            write(fd[1], &data, sizeof(data));
            printf("produced %d",data);
        }

        close(fd[1]);

        end = clock();
        timetaken = (double)(end-start)/CLOCKS_PER_SEC;
        printf("time taken is %f ",timetaken);
    }
}
