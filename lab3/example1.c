#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char static_array [5] = "inno";
    char new_static_array[11];
    strcpy(new_static_array, "innopolis");

    char *dynamic_array = malloc(5*sizeof(int));
    dynamic_array = realloc(dynamic_array, 11);
    strcpy(dynamic_array, "innopolis");
    free(dynamic_array);

    float stat_array[4] = {0.25, 0.5, 0.75, 1};
    float *p = stat_array;

    printf("Pointer size: %zu\nArray size: %zu\nPointer to a char size: %zu\n", 
    sizeof(p),sizeof(stat_array), sizeof(char*));

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int (*new_matrix)[4];
    new_matrix = malloc(sizeof(int[2][4]));
    int *matrix_ptr = (int *)matrix;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            new_matrix[i][j] = *matrix_ptr;
            matrix_ptr++;
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", new_matrix[i][j]);
        }
        printf("\n");
    }
    free(new_matrix);
    return 0;
}