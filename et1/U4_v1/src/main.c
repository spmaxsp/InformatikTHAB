#include<stdio.h> 
#include "geomittel.h"
 
void main() {
    double a;
    double b;
    double c;
    printf("Zahl1: ");
    scanf("%lf%*c", &a);
    printf("Zahl1: ");
    scanf("%lf%*c", &b);
    c = geoMittel(a, b);
    if (c != -1){
        printf("Ergebnis: %g \n", c);
    }
    else {
        printf("Fehler");
    }
    return;
}