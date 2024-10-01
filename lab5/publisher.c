#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_MSG_SIZE 1024
#define PIPE_PATH "/tmp/ex1/s" 

int main(int argc, char *argv[]) {
    int n, i;
    char message[MAX_MSG_SIZE];
    char pipe_name[20];
    int fd;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number of subscribers>n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    for (i = 1; i <= n; i++) {
        sprintf(pipe_name, "%s%d", PIPE_PATH, i);
        if (mkfifo(pipe_name, 0666) == -1) {
            perror("mkfifo error");
            exit(1);
        }
    }
    while (1) {
        printf("Enter message: ");
        fgets(message, MAX_MSG_SIZE, stdin);
        message[strcspn(message, "n")] = '0';
        for (i = 1; i <= n; i++) {
            sprintf(pipe_name, "%s%d", PIPE_PATH, i);
            fd = open(pipe_name, O_WRONLY);
            if (fd == -1) {
                perror("open");
                exit(1);
            }
            if (write(fd, message, strlen(message) + 1) == -1) {
                perror("write");
                exit(1);
            }
            close(fd);
        }
    }
    return 0;
}