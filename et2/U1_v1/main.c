#include<stdio.h> 

int isBigger(int myArr1[], int size_myArr1, int myArr2[], int size_myArr2) {
    int sum_1 = 0;
    int sum_2 = 0;
    for (int i=0; i<size_myArr1; i++) {
        sum_1 += myArr1[i];
    }
    for (int i=0; i<size_myArr2; i++) {
        sum_2 += myArr2[i];
    }
    return sum_1 >= sum_2;
}
 
int main() { 
    int myArr1[5] = {1,2,3,4,5};
    int size_myArr1 = sizeof myArr1 / sizeof myArr1[0];
    int myArr2[5] = {6,7,8,9,10};
    int size_myArr2 = sizeof myArr2 / sizeof myArr2[0];
    int myArr3[10] = {11,12,13,14,15,16,17,18,19,20};
    int size_myArr3 = sizeof myArr3 / sizeof myArr3[0];
    int result = isBigger(myArr1, size_myArr1, myArr3, size_myArr3);
 return 0; 
}
