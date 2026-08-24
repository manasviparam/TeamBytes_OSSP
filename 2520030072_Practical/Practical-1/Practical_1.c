#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
char cmd[20];
int pid;
printf("Enter command: ");
scanf("%s",cmd);
pid=fork();
if(pid>0){
wait(NULL);
printf("Parent PID = %d\n",getpid());
}
else if(pid==0){
printf("Child PID = %d\n",getpid());
execlp(cmd,cmd,NULL);
}
return 0;
}
