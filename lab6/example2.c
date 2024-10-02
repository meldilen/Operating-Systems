#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<ctype.h>

void sigint_handler(int sig) {
    static int first_time = 1;
    if (first_time) {
        printf("Catch SIGINT! Interrupted!\n");
        first_time = 0;
    } else {
        signal(SIGINT, SIG_DFL);
        raise(SIGINT);
    }
}

void sigusr1_handler(int sig){
    printf("Input can not start with '-'. Enter positive integer!\n");
}

void sigusr2_handler(int sig){
    printf("Error. Enter positive integer!\n");
}

void alarm_handler(int sig) {
    printf("Child process (PID: %d) terminated after 3 seconds\n", getpid());
}

int main() {
    
    //part 1

    // signal(SIGINT, sigint_handler);
    // pid_t pid = fork();
    // if (pid == 0) {
    //     alarm(3);
    //     signal(SIGALRM, alarm_handler);
    //     while (1) {
    //         printf("Child hello world!\n");
    //         sleep(1);
    //     }
    // } else if (pid > 0) {
    //         wait(NULL);
    //     } else {
    //         perror("Fork creation error!");
    //         exit(1);
    // }

    //part 2

    char input[100];
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    printf("Enter a positive integer: ");
    fgets(input, 100, stdin);
    if (input[0] == '-'){
        raise(SIGUSR1);
        return 1;
    }
    if (input[0] == '\n'){
        raise(SIGUSR2);
        return 1;
    }
    for (int i = 0; input[i] != '\0'; i++){
        if (isdigit(input[i])){continue;} else {
            raise(SIGUSR2);
            return 1;
        }
    }
    return 0;
}