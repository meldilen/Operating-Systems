#include<stdio.h>
#include<stdlib.h>

int const_tri(int*, int);

int main(){
    int* const p = (int*)malloc(3*sizeof(int));
    const int x = 1;
    const int* q = &x;
    *p = *q;
    p[1] = *q;
    p[2] = 2*(*q);

    printf("p0 addres: %p\np1 address: %p\np2 address:%p\n", p, p+1, p+2);

    if((p+1) == (p+2)-1 && (p+2) == (p+3)-1)
        printf("Contiguous\n");
    else printf("Not contiguous\n");
    
    printf("Enter n for tribonacci sequence: ");
    int n;
    scanf("%d", &n);
    int *tribonacci_sequence = (int*)malloc(n*sizeof(int));
    int result = const_tri(tribonacci_sequence, n);
    printf("%d\n", result);
    free(p);
    free(tribonacci_sequence);
    return 0;
}

int const_tri(int* ptr, int n){
    if (n <= 1){
        return 0;
    }
    if (n == 2){
        return 1;
    }
    *(ptr+0) = 0;
    *(ptr+1) = 0;
    *(ptr+2) = 1;
    for (int i = 3; i < n; i++){
        ptr[i] = ptr[i-2] + ptr[i-1] + ptr[i-3];
    }

    return ptr[n-1];
}