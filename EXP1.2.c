#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else if (pid > 0) {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }
    else {
        printf("Fork failed\n");
    }

    return 0;
}
