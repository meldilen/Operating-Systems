#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person{
    char* name;
    int age;
    float height;
};

struct Person *createPerson(char* name, int age, float height){
    struct Person *newPerson = (struct Person*)malloc(sizeof(struct Person));
    if (newPerson == NULL){
        printf("Memory allocation error for new person creation!\n");
        return NULL;
    }
    newPerson->name = (char *)malloc((strlen(name)+1)*sizeof(char));
    if (newPerson->name == NULL){
        printf("Memory allocation error for name creation!\n");
        free(newPerson);
        return NULL;
    }
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->height = height;

    return newPerson;
}

void showPerson(struct Person *person){
    if (person == NULL){
        printf("Person does not exist!");
    } else {
        printf("Name: %s, age: %d, height: %.2f\n", person->name, person->age, person->height);
    }
}

int main(){
    struct Person *friends[3];
    friends[0] = createPerson("Nastya", 19, 69.1);
    friends[1] = createPerson("Dzhamilia", 19, 169);
    friends[2] = createPerson("Ivan", 5, 180);

    for (int i = 0; i< 3; i++){
        showPerson(friends[i]);
    }

    for (int i = 0; i< 3; i++){
        free(friends[i]->name);
        free(friends[i]);
    }
    return 0;
}