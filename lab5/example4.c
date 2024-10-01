#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter = 0;
pthread_mutex_t mutex;

//critical region
void *increment_counter(void *arg){
    for(int i = 0; i < 1000; i++){
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t threads[1000];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 1000; i++){
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }
    for(int i = 0; i < 1000; i++){
        pthread_join(threads[i], NULL);
    }
    printf("final counter value: %d\n", counter);
    pthread_mutex_destroy(&mutex);
}