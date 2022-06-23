#include <stdio.h>
#include <stdlib.h>
#include "numArrays.h"
#include "sortingHelperStructures.h"

int qsort_cmp_asc_int(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mySort(int* myArray, unsigned long length) {
	qsort(myArray, length, sizeof(int), qsort_cmp_asc_int);
}

void mySortForReal(int* myArray, unsigned long length) {
	//selection sort
	for(int i = 0; i < length; i++) {
		for(int j = i+1; j < length; j++) {
			if (myArray[j] < myArray[i]){
				myArray[i] = myArray[i] ^ myArray[j];
				myArray[j] = myArray[i] ^ myArray[j];
				myArray[i] = myArray[i] ^ myArray[j];
			}
		}
	}
}

void AnotherBadIdea(int* myArray, unsigned long length) {
	//buble sort
	int sorted = 0;
	while(!sorted) {
		sorted = 1;
		for(int i = 0; i < length; i++) {
			if (myArray[i+1] < myArray[i]){
				sorted = 0;
				myArray[i] = myArray[i] ^ myArray[i + 1];
				myArray[i + 1] = myArray[i] ^ myArray[i + 1];
				myArray[i] = myArray[i] ^ myArray[i + 1];
			}
		}
	}
}

void notMySort(int* myArray, unsigned long length) {
	unsigned long j = 1;
	while (!isSortedArray(myArray, length)) {
		for (unsigned long i = 0; i < length - j; i++) {
			if (myArray[i] > myArray[i + 1]) {
				myArray[i] = myArray[i] ^ myArray[i + 1];
				myArray[i + 1] = myArray[i] ^ myArray[i + 1];
				myArray[i] = myArray[i] ^ myArray[i + 1];
			}
		}
		j++;
	}
}


void quicksort(int* myArray, unsigned long length) {
	if(length<=1){
		return;
	}
	int p = myArray[length/2-1];
	int i = 0;
	int j = length-1;
	while(1) {
		while(myArray[i]<p){i++;}
		while(myArray[j]>p){j--;}
		if(i>=j){
			break;
		}
		else{
			swap(&(myArray[i]), &(myArray[j]));
			j--;
			i++;
		}
	}
	quicksort(myArray, j+1);
	quicksort(myArray + j + 1, length-j-1);
}

int main(void) {
	//you don't need to make any changes to the code below.
	//but feel free, if you like ...
	setvbuf(stdout, 0, _IONBF, 0);
	numArrays* myNA = initializeArrays(getUserInput());

	//If you look closely, we do some interesting stuff here:
	//We pass a function (our sorting algorithm) as an argument into
	//the function callSorter. If have a look in sortingHelperStructures.c
	//you will see, how the parameter list looks like
	
	callSorter(mySort, myNA, "mySort");
	//callSorter(mySortForReal, myNA, "mySortForReal");
	//callSorter(notMySort, myNA, "notMySort");
	//callSorter(AnotherBadIdea, myNA, "AnotherBadIdea");
	callSorter(quicksort, myNA, "Quicksort");


	deleteNumArray(&myNA);
	return EXIT_SUCCESS;
}
