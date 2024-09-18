#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    int n = 4;
    pid_t pid = fork();
    if (pid == 0){
        printf("Hello from - %d - %d\n", getpid(), n);
        sleep(5);
        exit(0);
    } if (pid < 0){
        printf("Fork failed");
        return 1;
    } else {
        printf("Parent process is executed\nHello from - %d - %d\n", getpid(), n);
        kill(pid, SIGKILL);
        printf("Killed child process - %d\n", pid);
        wait(NULL);
        exit(1);
    }


    // FILE* file = fopen("/proc/sys/kernel/pid_max", "r");
    // if (file == NULL){
    //     printf("Open file error!");
    //     return (EXIT_FAILURE);
    // }
    // int max_pid;
    // fscanf(file, "%s", max_pid);
    // fclose(file);
    // printf("Maximum value is %d\nFile path: /proc/sys/kernel/pid_max\n", max_pid);

    // file = fopen("/proc/1/stat", "r");
    // if (file == NULL){
    //     printf("Open file error!");
    //     return EXIT_FAILURE;
    // }
    // int pid_from_file, ppid;
    // fscanf(file, "%s", pid_from_file);
    // fscanf(file, "%s", ppid);
    // fclose(file);
    // printf("%d\n%d\n", max_pid);
    return EXIT_SUCCESS;
}