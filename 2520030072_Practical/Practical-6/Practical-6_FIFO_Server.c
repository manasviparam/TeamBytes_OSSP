#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char buffer[100] = {0};
    int fd;

    mkfifo("myfifo", 0666);

    printf("Server started...\n");
    printf("Waiting for client message...\n");

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Client message: %s\n", buffer);

    close(fd);

    fd = open("myfifo", O_WRONLY);

    char response[] = "Message processed by server";

    write(fd, response, sizeof(response));

    printf("Server response sent\n");

    close(fd);

    return 0;
}
