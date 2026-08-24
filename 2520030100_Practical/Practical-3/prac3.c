#include <stdio.h>
#include <unistd.h>

int main()
{
int pid;

pid = fork();

if(pid < 0)
{
printf("Fork not successful\n");
}
else if(pid == 0)
{
printf("Child Process\n");
printf("Child Process ID is %d\n", getpid());
printf("Parent Process ID is %d\n", getppid());
while(1){
}}
else
{
printf("Parent Process\n");
printf("Parent Process ID is %d\n", getpid());
printf("Parent's Parent Process ID is %d\n", getppid());
}
}
