#include<stdio.h> 

unsigned long long recursion(int n){
    unsigned long long res = 1;
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 1;
    }
    else{
        res = n * recursion(n-1);
        return res;
    }
}

int test_max_recursion(){
    int n = 1;
    unsigned long long res = recursion(n);
    unsigned long long prev_res = 1;
    while (res/n == prev_res){
        n++;
        prev_res = res;
        res = recursion(n);
        
    }
    return n-1;
}

unsigned long long for_loop(int n){
    if(n < 0){
        return -1;
    }
    unsigned long long res = 1;
    for(int i = 1; i <= n; i++){
        res = res * i;
    }
    return res;
}

void main(){
    int n = 17;
    unsigned long long res = 1;
    res = for_loop(n);
    printf("Ergebnis: %llu \n", res);
    res = recursion(n);
    printf("Ergebnis: %llu \n", res);
    int max = test_max_recursion(n);
    printf("Ergebnis: %d \n", max);
    return;
}