#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<stdlib.h>

int main(){
    pid_t process1, process2;
    clock_t start1, end1, start2, end2;
    printf("Parent process ID: %d\n", getpid());

    start1 = clock();
    process1 = fork();
    if (process1 == 0){
        printf("Process ID of child 1: %d\nID of the parent process child 1: %d\n", getpid(), getppid());
        end1 = clock();
        printf("Execution time for child 1: %ld\n", (end1 - start1)*1000/CLOCKS_PER_SEC);
        exit(0);
    }
    if (process1 < 0){
        perror("Fork failed");
        return 1;
    }

    start2 = clock();
    process2 = fork();
    if (process2 == 0){
        printf("Process ID of child 2: %d\nID of the parent process child 2: %d\n", getpid(), getppid());
        end2 = clock();
        printf("Execution time for child 2: %ld\n", (end2 - start2)*1000/CLOCKS_PER_SEC);
        exit(0);
    }
    if (process2 < 0){
        perror("Fork failed");
        return 1;
    }
    end1 = clock();
    printf("Parent execution time: %ld\n", (end1 - start1)*1000/CLOCKS_PER_SEC);
    return 0;
}