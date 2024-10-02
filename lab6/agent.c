#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void handle_sigusr1(int sig) {
    FILE *file;
    char buffer[1024];
    file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Open file error!");
        return;
    }
    fgets(buffer, sizeof(buffer), file);
    printf("Received SIGUSR1: %s\n", buffer);
    fclose(file);
    }

void handle_sigusr2(int sig) {
    printf("SIGUSR2 handling. Process terminating...\n");
    exit(0);
}

void handle_sigstop(int sig){
    printf("Process stopped...\n");
}

void handle_sigcont(int sig){
    printf("Process continued...\n");
}

int main() {
    int pid_fd = open("/var/run/agent.pid", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pid_fd == -1) {
        perror("Error creating PID file");
        exit(1);
    }
    dprintf(pid_fd, "File PID %d\n", getpid());
    close(pid_fd);

    FILE *f;
    char buffer[1024];
    f = fopen("text.txt", "r");
    if (f == NULL) {
        perror("Txt file opening error!");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), f);
    printf("%s\n", buffer);
    fclose(f);

    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    signal(SIGSTOP, handle_sigstop);
    signal(SIGCONT, handle_sigcont);
    while (1) {
        sleep(1);
    }
    return 0;
}