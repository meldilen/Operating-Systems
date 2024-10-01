#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_MSG_SIZE 1024

int main(){
    int pipefd[2];
    pid_t pid;
    char message[MAX_MSG_SIZE];
    if (pipe(pipefd) == -1){
        perror("Pipe creation error!");
        exit(1);
    }
    pid = fork();
    if (pid == 0){
        close(pipefd[1]);
        if (read(pipefd[0], message, MAX_MSG_SIZE) == -1){
            perror("Read error!");
            exit(1);
        }
        printf("Subscriber received: %s\n", message);
        close(pipefd[0]);
    } else if (pid > 0){
        close(pipefd[0]);
        printf("Enter message: ");
        fgets(message, MAX_MSG_SIZE, stdin);
        message[strcspn(message, "n")] = '0';
        if (write(pipefd[1], message, strlen(message) + 1) == -1){
            perror("Write error!");
            exit(1);
        }
        close(pipefd[1]);
        wait(NULL);
    } else {
        perror("Successfull fork creation!\n");
        exit(1);
    }
    return 0;
}