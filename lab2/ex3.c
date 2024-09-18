#include<stdio.h>
#include<string.h>

void convert(long long x, int s, int t);

int main (){
    long long x;
    int s, t;
    scanf("%lld", &x);
    scanf("%d", &s);
    scanf("%d", &t);

    convert(x, s, t);

    return 0;
}

void convert(long long x, int s, int t){
    if (s < 2 || s > 10 || t < 2 || t > 10){
        printf("cannot convert!");
    }

    char convertedNumber[100];
    int i = 0;

    long long decimal = 0;
    long long power = 1;

    while(x > 0){
        decimal += (x % 10) * power;
        x /= 10;
        power *= s;
    }

    while(decimal > 0){
        convertedNumber[i++] = (decimal % t) + '0';
        decimal /= t; 
    }

    for (int j = 0; j < i / 2; j++){
        char temp = convertedNumber[j];
        convertedNumber[j] = convertedNumber[i-j-1];
        convertedNumber[i-j-1] = temp;
    }

    printf("%s", convertedNumber);
    return;
}