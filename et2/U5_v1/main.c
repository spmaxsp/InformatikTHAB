#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myList.h"  

int addSorted(myList** p_current, int value){

    myList* tmp_new = (myList*) malloc(sizeof(myList));  //alociere neuen speicher
    if (tmp_new == NULL){          //überprüfe ob alocation erfolgreich
        return 0;
    } 
    tmp_new->value = value;
    tmp_new->next = NULL;

    if (*p_current == NULL){              // überprüfe ob head noch null ist
        *p_current = tmp_new;             //mache new das head element
        return 1;
    }

    if ((*p_current)->value > value){       //überprüfe ob neues element kleiner als head
        tmp_new->next = *p_current;
        *p_current = tmp_new;
        return 1;
    }

    myList* current = *p_current;     //current ist nun die adresse auf die head zeigt
    while(current->next != NULL && current->next->value < value){ //solange bis ende der liste oder ein größeres Element gefungen
        current = current->next;                                  //current wird das nächste element zugewisen
    }   
    tmp_new->next = current->next;
    current->next = tmp_new;
    return 1;
}

int addToTail(myList** p_current, int value){
    if (*p_current == NULL){              // überprüfe ob head bereits auf null zeigt
        *p_current = (myList*) malloc(sizeof(myList));  //erstelle das head element
        (*p_current)->next = NULL;
        (*p_current)->value = value;
    }
    else {
        myList* current = *p_current;     //current ist nun die adresse auf die head zeigt
        while(current->next != NULL){     //solange != Null also ende der Lsiste
            current = current->next;      //current wird das nächste element zugewisen
        }
        current->next = (myList*) malloc(sizeof(myList));  //alociere neuen speicher und schreibe die adresse un curent-next
        if (current->next == NULL){          //überprüfe ob alocation erfolgreich
            return 0;
        }
        current = current->next;             //curretn auf den neu erstellten Eintrag
        current->value = value;
    }
    return 1;
}

int removeFromTail(myList** p_current){   // *p_current wäre der head-pointer in der main
    if (*p_current == NULL){              // überprüfe ob head bereits auf NULL zeigt

    }
    else if ((*p_current)->next == NULL){ //überprüfe ob der next des headpointer bereits auf NULL zeigt
        free(*p_current);                 //wenn ja löche und setze auf null
        *p_current = NULL;  
    }
    else{
        myList* current = *p_current;     //current ist nun die adresse auf die head zeigt
        myList* previous;
        while(current->next != NULL){
            previous = current;           //merke das vorherige element
            current = current->next;      //springe zum nächsten
        }
        previous->next = NULL;            //das next des vorherigen auf null
        free(current);                    //löche das aktuelle element
    }
    return 1;
}

int deleteList(myList** p_current){
    while (*p_current != NULL){           // solange bis head bereits auf NULL zeigt
        removeFromTail(p_current);
    }
    return 1;
}

int printList(myList** p_current){
    if (*p_current == NULL){              // überprüfe ob head bereits auf null zeigt

    }
    else {
        myList* current = *p_current;     //current ist nun die adresse auf die head zeigt
        printf("value: %d\n", current->value);
        while(current->next != NULL){
            current = current->next;      //gehe zum nächsten element und printe
            printf("value: %d\n", current->value);
        }
        printf("\n");
    }
    return 1;
}




int main() {
    //-----------------------Teil1---------------------

    myList* head = NULL;

    for(int i = 0; i < 4; i++){             //generate new test data
        if(!addToTail(&head, i)) {
            printf("Konnte Element nicht hinzufügen!\n");
            return 0;
        }
        printList(&head);
    }

    deleteList(&head);
    printList(&head);

    //-----------------------Teil2---------------------

    myList* headOfSortedList = NULL;

    if(!addSorted(&headOfSortedList, 10)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    if(!addSorted(&headOfSortedList, 8)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    if(!addSorted(&headOfSortedList, 7)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    if(!addSorted(&headOfSortedList, 11)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    if(!addSorted(&headOfSortedList, 15)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    if(!addSorted(&headOfSortedList, 9)) {
        printf("Konnte Element nicht hinzufügen!\n");
        return 0;
    }

    return 1;
}