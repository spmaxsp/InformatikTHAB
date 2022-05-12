#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myList.h"  

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
            return -1;
        }
        current = current->next;             //curretn auf den neu erstellten Eintrag
        current->value = value;
    }
    return 0;
}

int removeFromTail(myList** p_current){   // *p_current wäre der head-pointer in der main
    if (*p_current == NULL){              // überprüfe ob head bereits auf head zeigt

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
        free(current);                    //öoche das aktuelle element
    }
    return 0;
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
    return 0;
}




int main() {
    myList* head = NULL;

    if(addToTail(&head, 11) == 1) {
        printf("Konnte Element nicht hinzufügen!\n");
        return -1;
    }

    printList(&head);

    if(addToTail(&head, 22) == 1) {
        printf("Konnte Element nicht hinzufügen!\n");
        return -1;
    }

    printList(&head);

    removeFromTail(&head);

    printList(&head);

    removeFromTail(&head);
    removeFromTail(&head);

    printList(&head);

    if(addToTail(&head, 23) == 1) {
        printf("Konnte Element nicht hinzufügen!\n");
        return -1;
    }

    printList(&head);

    removeFromTail(&head); //doppel-pointer notwendig da head nur auf den speicherplatz zeigt und head selbst nicht verändert weren kann
    
    return 0;
}