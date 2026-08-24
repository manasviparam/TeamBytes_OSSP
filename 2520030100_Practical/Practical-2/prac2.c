#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
int fd1,fd2;
char buf[100];
int n;

fd1=open("sample.txt",O_RDONLY);
fd2=open("copy.txt",O_WRONLY|O_CREAT,0644);

n=read(fd1,buf,sizeof(buf));
write(fd2,buf,n);

close(fd1);
close(fd2);

printf("file copied successfully");
}
