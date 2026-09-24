#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buffer[100] = {0};
    int fd;

    printf("Client started\n");

    fd = open("myfifo", O_WRONLY);

    char message[] = "Hello Server";

    write(fd, message, sizeof(message));

    printf("Message sent to server\n");

    close(fd);

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Server response: %s\n", buffer);

    close(fd);

    return 0;
}
