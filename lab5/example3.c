#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter = 0;

//critical region
void *increment_counter(void *arg){
    for(int i = 0; i < 100; i++){
        counter++;
    }
    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    //race condition
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    //sleep(1);

    //join
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("final counter value: %d\n", counter);
}