#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heap.h"

int createMemoryForHeap(heap** myHeapPtr, int depth){
    //allocating memory for heapArray
    int required_array_size = pow(2, depth) -1;
    
    unsigned int* heapArray = (unsigned int*) calloc(required_array_size, sizeof(unsigned int));
    if (heapArray == NULL) {
        return 0;
    }
    
    //allocating memory for heap struckt
    *myHeapPtr = (heap*) malloc(sizeof(heap));
    if (*myHeapPtr == NULL) {
        return 0;
    }
    (*myHeapPtr)->heapArray = heapArray;
    (*myHeapPtr)->size = required_array_size;
    return 1;
}

int deleteHeap(heap** myHeapPtr) {
    free((*myHeapPtr)->heapArray);
    free((*myHeapPtr));
    return 1;
}

int addToHeap(heap* myHeap, unsigned int node) {
    if (node == 0){
        return 0;
    }
    unsigned int* heapArray = myHeap->heapArray;
    for(int i = 0; i < myHeap->size; i++){
        if(*(heapArray + i) == 0){
            *(heapArray + i) = node;
            while(*(heapArray + i) > *(heapArray + ((i-1)/2)) && i != 0){
                unsigned int tmp = *(heapArray + i);
                *(heapArray + i) = *(heapArray + (i-1)/2);
                *(heapArray + (i-1)/2) = tmp;
                i = (i-1)/2;
            }
            return 1;
        }
    }
    return 1;
}

int printHeap(heap* myHeap) {
    for(int i = 0; i < myHeap->size; i++){
        if(*(myHeap->heapArray + i) == 0){
            printf("\n");
            return 1;
        }
        printf("%i ", *(myHeap->heapArray + i));
    }
}

int main() {
    heap* myHeap = NULL;
    createMemoryForHeap(&myHeap, 4);
    //  8, 4, 9, 3, 5, 1, 2, 6, 10
    printHeap(myHeap);
    addToHeap(myHeap, 8);
    printHeap(myHeap);
    addToHeap(myHeap, 4);
    printHeap(myHeap);
    addToHeap(myHeap, 9);
    printHeap(myHeap);
    addToHeap(myHeap, 3);
    printHeap(myHeap);
    addToHeap(myHeap, 5);
    printHeap(myHeap);
    addToHeap(myHeap, 1);
    printHeap(myHeap);
    addToHeap(myHeap, 2);
    printHeap(myHeap);
    addToHeap(myHeap, 6);
    printHeap(myHeap);
    addToHeap(myHeap, 10);
    printHeap(myHeap);
    return 1;
}
