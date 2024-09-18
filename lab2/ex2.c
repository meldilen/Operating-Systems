#include<stdio.h>
#include<string.h>

int main(){
    char input[256];
    int i = 0;

    while(1){
        char c =getchar();
        if (c == '.' || c == '\n' || i >= 256){
            break;
        }
        input[i++] = c;
    }
    input[i] = '\0';
    printf("\"");
    for (int j = strlen(input) - 1; j >= 0; j--){
        printf("%c", input[j]);
    }
    printf("\"");

    return 0;
}