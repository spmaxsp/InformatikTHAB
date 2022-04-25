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
    //-------Teil1------------------

    struct myStruct a, b;
    a.myFloat = 1.123;
    a.myInteger = 4;
    b.myFloat = 5.678;
    b.myInteger = 9;

    struct myStruct* c = &b;

    c->myFloat = 9.999;
    c->myInteger = 10;

    //-------Teil2------------------

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