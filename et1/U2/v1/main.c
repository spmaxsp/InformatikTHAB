#include<stdio.h> 

#define pi 3.14159
 
void main() { 
    float h;
    float r;
    float A;
    float V;

    printf("Radius: "); 
    scanf("%f", &r);

    printf("Hoehe: "); 
    scanf("%f", &h);

    V = pi * r * r * h;
    A = 2 * pi * r * (r + h);
    printf("Volumen: %f \n", V); 
    printf("Oberflaeche: %f \n", A); 
    return;
}