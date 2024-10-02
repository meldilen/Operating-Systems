#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

// I did not get how to change file permissions

void handle_sigint(int sig) {
    int pid_fd = open("/var/run/agent.pid", O_RDONLY);
    if (pid_fd == -1) {
        perror("Error opening PID file");
        exit(1);
    }
    FILE *f = fdopen(pid_fd, "r");
    if (f == NULL){
        perror("Reading error from PID file!\n");
        close(pid_fd);
        exit(1);
    }
    int pid;
    if (fscanf(f, "%d", &pid) != 1) {
        perror("Error reading PID from file");
        fclose(f);
        exit(1);
    }

    close(pid_fd);
    fclose(f);
    kill(pid, SIGTERM);
    printf("Sent SIGTERM to agent\n");
    exit(0);
}

int main() {
    int pid_fd = open("/var/run/agent.pid", O_RDONLY);
    if (pid_fd == -1) {
        perror("Error opening PID file");
        fprintf(stderr, "Error: No agent found.\n");
        exit(1);
    }
    FILE *f = fdopen(pid_fd, "r");
    if (f == NULL){
        perror("Reading error from PID file!\n");
        close(pid_fd);
        exit(1);
    }
    int pid;
    if (fscanf(f, "%d", &pid) != 1) {
        perror("Error reading PID from file");
        fprintf(stderr, "Error: No agent found.\n");
        fclose(f);
        exit(1);
    }
    close(pid_fd);
    fclose(f);
    printf("Agent found.\n");
    signal(SIGINT, handle_sigint);

    while (1) {
        char command[10];
        printf("Choose a command to send to the agent:\n1- read\n2- exit\n3- stop\n4- continue\n");
        scanf("Your choice: %s", command);

        if (strcmp(command, "1") == 0) {
            kill(pid, SIGUSR1);
            printf("Sent SIGUSR1 to agent\n");
        } else if (strcmp(command, "2") == 0) {
            kill(pid, SIGUSR2);
            printf("Sent SIGUSR2 to agent\n");
            break;
        } else if (strcmp(command, "3") == 0) {
            kill(pid, SIGSTOP);
            printf("Sent SIGSTOP to agent\n");
        } else if (strcmp(command, "4") == 0) {
            kill(pid, SIGCONT);
            printf("Sent SIGCONT to agent\n");
        } else {
        printf("Invalid command.\n");
        }
    }

    return 0;
}