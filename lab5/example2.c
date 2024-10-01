#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void *start_routine(void *);

int main(){
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, start_routine, NULL) != 0){
        perror("Failed to create thread 1");
        exit(1);
    }
    if (pthread_create(&thread2, NULL, start_routine, NULL) != 0){
        perror("Failed to create thread 2");
        exit(1);
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Work is done\n");
    return 0;
}

void *start_routine(void *arg){
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long) thread_id);
    sleep(5);
    pthread_exit(NULL);
    return NULL;
}