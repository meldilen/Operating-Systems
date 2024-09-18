#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>

#define VECTOR_SIZE 120

int main(){
    srand(time(NULL));
    int u_vector[VECTOR_SIZE], v_vector[VECTOR_SIZE];
    for(int i = 0; i < VECTOR_SIZE; i++){
        u_vector[i] = rand()%100;
        v_vector[i] = rand()%100;
    }
    printf("Enter even number of processes: ");
    int n;
    scanf("%d", &n);
    if (n%2 == 0){
        int component_number_per_process = VECTOR_SIZE/n;
        pid_t processes[n];
        for (int i = 0; i < n; i++){
            processes[i] = fork();
            if (processes[i] == 0){
                int start = i * component_number_per_process;
                int end = (i + 1) * component_number_per_process;
                int partial_dot_product = 0;
                for (int j = start; j < end; j++){
                    partial_dot_product += u_vector[j] * v_vector[j];
                }

                FILE *file = fopen("temp.txt", "a");
                if (file == NULL){
                    perror("File open error!\n");
                    exit(1);
                }
                fprintf(file, "%d\n", partial_dot_product);
                fclose(file);
                exit(0);
            }
        }
        int dot_product = 0;
        for (int i = 0; i < n; i++){
            wait(NULL);
        }

        FILE *file = fopen("temp.txt", "r");
        if (file == NULL){
            perror("File open error!\n");
            exit(1);
        }
        int partial_result;
        while (fscanf(file, "%d\n", &partial_result) != EOF){
            dot_product += partial_result;
        }
        fclose(file);
        printf("Dot product: %d\n", dot_product);
    }
    else printf("Number of processes should be even!\n");
    return 0;
}