#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    pid_t pid;
    if (pipe(pipefd) < 0) {
        perror("Pipe creation error!");
        exit(1);
    }
    pid = fork();
    if (pid < 0) {
        perror("Fork creation error!");
        exit(1);
    } else if (pid > 0) { 
        close(pipefd[1]);
        int length;
        ssize_t bytes_read = read(pipefd[0], &length, sizeof(length));
        if (bytes_read < 0) {
            perror("Read error!");
            exit(1);
        }
        char buffer[1024];
        bytes_read = read(pipefd[0], buffer, sizeof(length) + 1);
        if (bytes_read < 0) {
            perror("Read error!");
            exit(1);
        }
        printf("Message received: %s\n", buffer);
        close(pipefd[0]);
        wait(NULL);
        exit(0);
    } else {
        close(pipefd[0]);
        if (argc < 2) {
            fprintf(stderr, "Message: %s\n", argv[0]);
            exit(1);
        }
        int length = strlen(argv[1]);
        ssize_t bytes_written = write(pipefd[1],&length, sizeof(int));
        if (bytes_written == -1) {
            perror("Write error!");
            exit(1);
        }
        bytes_written = write(pipefd[1], argv[1], strlen(argv[1]) + 1);
        if (bytes_written == -1) {
            perror("Write error!");
            exit(1);
        }
        close(pipefd[1]);
        exit(0);
    }
    return 0;
}

