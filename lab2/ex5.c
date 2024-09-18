#include<stdio.h>

int tribonacci(int);

int main(){
    printf("%d\n", tribonacci(4));
    printf("%d\n", tribonacci(36));
    return 0;
}

int tribonacci(int n){
    if (n==0)
        return 0;
    if (n <= 2)
        return 1;
    int t0 = 0, t1 = 1, t2 = 1, result;
    for (int i = 3; i <= n; i++){
        result = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = result;
    }
    return result;
}