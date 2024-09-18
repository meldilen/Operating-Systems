#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    int status;
    pid_t pid = fork();
    if (pid == 0){
        printf("Child process sleeps for 5 seconds\n");
        sleep(5);
        exit(0);
    } 
    if (pid < 0){
        printf("Fork failed");
        return 1;
    } else {
        printf("Parent process is executed with PID %d\nChild process PID - %d\n", getpid(), pid);
        wait(&status); //prevent the child from becoming a zombie
        printf("Waiting for child process to finish\n");
        printf("Child process status: %d\n", WEXITSTATUS(status));
        //sleep(1);

        //kill(pid, SIGKILL);
        //printf("Killed child process - %d\n", pid);
        //exit(1);

        printf("Parent process exiting.\n");
        exit(0);
    }
    return 0;
}