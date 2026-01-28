#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buf[20];

    fd = open("data.txt", O_CREAT | O_WRONLY, 0777);
    printf("open() for write executed\n");

    write(fd, "Hello", 5);
    printf("write() executed\n");

    close(fd);
    printf("close() after write executed\n");

    fd = open("data.txt", O_RDONLY);
    printf("open() for read executed\n");

    read(fd, buf, sizeof(buf));
    printf("read() executed\n");

    printf("File content: %s\n", buf);

    close(fd);
    printf("close() after read executed\n");

    return 0;
}
