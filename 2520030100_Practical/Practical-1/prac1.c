#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int pid=fork();
char command[20];
scanf("%s",command);
if(pid==0){
printf("Child PID is = %d\n",getpid());
execlp(command,command,NULL);
}
else if(pid>0){
wait(NULL);
printf("Parent PID is = %d\n",getppid());
}
}
