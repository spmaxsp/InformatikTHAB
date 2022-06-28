#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
    struct person* father;
    struct person* mother;
    char name[20];
    unsigned int gender;
    unsigned int yob;
} person;

int create_person(person** p_head, char name[], unsigned int gender, unsigned int yob){
    if(p_head == NULL){
        return 1;
    }
    if(*p_head != NULL){
        return 1;
    }

    person* new_person = (person*) malloc(sizeof(person));
    if (new_person == NULL){
        return 1;
    }
    new_person->father = NULL;
    new_person->mother = NULL;
    strcpy(new_person->name, name);
    new_person->gender = gender;
    new_person->yob = yob;

    *p_head = new_person;
    return 0;
}

int create_parent(person** p_head, char nameofchild[], char name[], unsigned int gender, unsigned int yob, int father){
    if(p_head == NULL){
        return 1;
    }
    if(*p_head == NULL){
        return 1;
    }
    if(!strcmp(nameofchild, (*p_head)->name)){
        if (father){
            return create_person(&((*p_head)->father), name, gender, yob);
        }
        else{
            return create_person(&((*p_head)->mother), name, gender, yob);
        }
    }
    create_parent(&((*p_head)->father), nameofchild, name, gender, yob, father);
    create_parent(&((*p_head)->mother), nameofchild, name, gender, yob, father);
}

int main(){
    person* head = NULL;
    if(create_person(&head, "Me", 1, 2000)){
        return 1;
    }
    if(create_person(&(head->father), "MyFather", 1, 1970)){
        return 1;
    }
    if(create_person(&(head->father->father), "MyFathersFather", 1, 1950)){
        return 1;
    }
    if(create_person(&(head->father->mother), "MyFathersMother", 2, 1950)){
        return 1;
    }
    create_parent(&head, "Me", "MyMother", 2, 1970, 0);
    return 0;
}
