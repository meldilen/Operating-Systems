#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>

//sanitizer indicates memory leaks, I dk how to fix it :(

void* add_double(const void* a, const void* b){
    double* result = malloc(sizeof(double));
    *result = *(double*)a + *(double*)b;
    return result;
}

void* add_int(const void* a, const void* b){
    int* result = malloc(sizeof(int));
    *result = *(int*)a + *(int*)b;
    return result;
}

void* multiply_double(const void* a, const void* b){
    double* result = malloc(sizeof(double));
    *result = *(double*)a * *(double*)b;
    return result;
}

void* multiply_int(const void* a, const void* b){
    int* result = malloc(sizeof(int));
    *result = *(int*)a * *(int*)b;
    return result;
}

void* max_double(const void* a, const void* b){
    double* result = malloc(sizeof(double));
    *result = (*(double*)a > *(double*)b) ? *(double*)a : *(double*)b;
    return result;
}

void* max_int(const void* a, const void* b){
    int* result = malloc(sizeof(int));
    *result = (*(int*)a > *(int*)b) ? *(int*)a : *(int*)b;
    return result;
}

void *aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    void* result = initial_value;
    for (int i = 0; i < n; i++){
        result = opr(result, (char*) base + i * size);
    }
    return result;
}

void test_on_double(){
    double initial_value = 0.0;
    double array[] = {1.1, 1.2, 1.3, 0.5, 3.2};
    int array_size = sizeof(array)/sizeof(array[0]);

    double* addition = aggregate(array, sizeof(double), array_size, &initial_value, add_double);
    printf("Sum result of doubles: %.2f\n", *addition);
    free(addition);


    initial_value = 1.0;
    double* multiplication = aggregate(array, sizeof(double), array_size, &initial_value, multiply_double);
    printf("Multiplication result of doubles: %.2f\n", *multiplication);
    free(multiplication);

    double min_value = -DBL_MAX;
    double* max_result = aggregate(array, sizeof(double), array_size, &min_value, max_double);
    printf("Max of doubles: %.2f\n", *max_result);
    free(max_result);
}

void test_on_int(){
    int initial_value = 0;
    int array[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(array)/sizeof(array[0]);

    int* addition = aggregate(array, sizeof(int), array_size, &initial_value, add_int);
    printf("Sum result of integers: %d\n", *addition);
    free(addition);

    initial_value = 1;
    int* multiplication = aggregate(array, sizeof(int), array_size, &initial_value, multiply_int);
    printf("Multiplication of integers: %d\n", *multiplication);
    free(multiplication);

    int min_value = INT_MIN;
    int* max_result = aggregate(array, sizeof(int), array_size, &min_value, max_int);
    printf("Max of integers: %d\n", *max_result);
    free(max_result);
}

int main(){
    test_on_double();
    printf("\n");
    test_on_int();
    return 0;
}