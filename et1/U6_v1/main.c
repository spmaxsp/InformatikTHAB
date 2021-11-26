#include<stdio.h> 
#include<math.h>
#include<time.h>

unsigned long long is_prime_basic(unsigned long long z){
    if (z <= 1){
        return z;
    }
    for (unsigned long long p = 2; p < z; p++){
        if (z%p == 0 && z != p) {
            return p;
        }
    }
    return z;
}

unsigned long long is_prime_sqr(unsigned long long z){
    if (z <= 1){
        return 1;
    }
    if (z == 2){
        return z;
    }
    unsigned long long max_div = sqrt(z);
    max_div = floor(max_div);
    for (unsigned long long p = 2; p <= max_div+1; p++){
        if (z%p == 0) {
            return p;
        }
    }
    return z;
}

unsigned long long is_prime_sqr_div_two(unsigned long long z){
    if (z <= 1){
        return 1;
    }
    if (z == 2){
        return z;
    }
    if (z > 2 && z%2 == 0){
        return 2;
    }
    unsigned long long max_div = sqrt(z);
    max_div = floor(max_div);
    for (unsigned long long p = 3; p <= max_div+1; p+=2){
        if (z%p == 0) {
            return p;
        }
    }
    return z;
}




void main(){
    //944871823102126331 (nicht prim, Faktoren sind 961748927 und 982451653)
    unsigned long long z = 3497526502987;
    unsigned long long out = 0;

    clock_t start, end;
    double Rechenzeit;

    start = clock();
    out = is_prime_basic(z);
    end = clock();
    Rechenzeit = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ergebnis: %d \n", out);
    printf("Operation finished after %.2f seconds.\n", Rechenzeit);


    start = clock();
    out = is_prime_sqr(z);
    end = clock();
    Rechenzeit = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ergebnis: %d \n", out);
    printf("Operation finished after %.2f seconds.\n", Rechenzeit);


    start = clock();
    out = is_prime_sqr_div_two(z);
    end = clock();
    Rechenzeit = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ergebnis: %d \n", out);
    printf("Operation finished after %.2f seconds.\n", Rechenzeit);

    return;
}



