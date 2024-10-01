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
    int id;
    char message[MAX_MSG_SIZE];
    char pipe_name[20];
    int fd;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <subscriber id>n", argv[0]);
        exit(1);
    }
    id = atoi(argv[1]);
    sprintf(pipe_name, "%s%d", PIPE_PATH, id);
    fd = open(pipe_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    while (1) {
        if (read(fd, message, MAX_MSG_SIZE) == -1) {
            perror("read");
            exit(1);
        }
        printf("Subscriber %d received: %sn", id, message);
    }
    close(fd);
    return 0;
}