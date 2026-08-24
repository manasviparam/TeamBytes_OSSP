#include<stdio.h>
#include<unistd.h>
int main(){
int pid;
pid=fork();
if(pid<0){
printf("Process creation failed\n");
}
else if(pid==0){
printf("Child is running\n");
printf("Child ID: %d\n",getpid());
printf("Parent ID: %d\n",getppid());
while(1){
}
}
else{
printf("Parent is running\n");
printf("Parent ID: %d\n",getpid());
printf("Grandparent ID: %d\n",getppid());
}
return 0;
}