#include<stdio.h>
#include<string.h>
#include<ctype.h>

// ./ex5.sh "Innopolis" if main function called with parametrs

int count (char input[], char symbol){
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++){
        if (tolower(input[i]) == tolower(symbol)){
            count++;
        }
    }
    return count;
}

void countAll(char input[]){
    for (int i = 0; input[i] != '\0'; i++){
        char symbol = tolower(input[i]);
        int occurrences = count (input, symbol);
        printf("%c:%d, ", symbol, occurrences);
    }
}

int main(){
    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
     countAll(input);
     printf("\n");
     return 0;
}