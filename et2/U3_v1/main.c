#include<stdio.h>
#include<string.h>  

void main() {

    int* numbers = (int *) malloc(sizeof(int)*256);
    if (numbers == NULL) {
        printf("Cant allocate memory\n");
    }
    else{
        printf("Success!\n");
        for (int i = 0; i <= 255; i++){
           *(numbers + i) = i;
        }
        for (int i = 0; i <= 255; i++){
           printf("value at adress %p", (numbers + i));
           printf(" is: %d \n", *(numbers + i));
        }
    }
    return;
}
