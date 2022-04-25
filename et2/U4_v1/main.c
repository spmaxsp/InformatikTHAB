#include<stdio.h>
#include<string.h>  
#include "myStruct.h"
#include "myList.h"

void printList(struct myList* p){
    printf("Number: %d\n", p->value);
    if (p->next != NULL) {
        printList(p->next);
    }
    return;
}

void main() {
    myList* head;

    malloc(sizeof(myList))
    struct myList x;
    x.value = 2;
    x.next = NULL;
    
    struct myList y;
    y.value = 1;
    y.next = &x;
    
    struct myList z;
    z.value = 0;
    z.next = &y;

    printList(&z);

    return;
}