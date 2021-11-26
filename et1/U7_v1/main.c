#include<stdio.h> 
#include<math.h>

#define pi 3.14

void main() {
    int R = 3;
    double a[R], b[R];

    double scalar, amount_a, amount_b, angle, cross[R];

    printf("Input vector a: \n"); 
    printf("a = [\n");
    printf("      "); scanf("%lf%*c", &a[0]);
    printf("      "); scanf("%lf%*c", &a[1]);
    printf("      "); scanf("%lf%*c", &a[2]);
    printf("          ]\n\n");

    printf("Input vector b: \n"); 
    printf("b = [\n");
    printf("      "); scanf("%lf%*c", &b[0]);
    printf("      "); scanf("%lf%*c", &b[1]);
    printf("      "); scanf("%lf%*c", &b[2]);
    printf("          ]\n\n");

    cross[0] = a[1] * b[2] - a[2] * b[1];
    cross[1] = a[0] * b[2] - a[2] * b[0];
    cross[2] = a[0] * b[1] - a[1] * b[0];

    amount_a = sqrt(pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2));
    amount_b = sqrt(pow(b[0], 2) + pow(b[1], 2) + pow(b[2], 2));
    scalar = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    if (cross[0] == 0 && cross[1] == 0 && cross[2] == 0){
        angle = 0;
    }
    else {
        angle = acos(scalar/(amount_a*amount_b)) * (180/pi);
    }
    
    printf("|a| = %lf\n", amount_a);
    printf("|b| = %lf\n", amount_b);
    printf("angle = %lfdegree\n", angle);
    printf("a * b = %lf\n", scalar);


    printf("a x b = [\n");
    printf("      %lf \n", cross[0]);
    printf("      %lf \n", cross[1]);
    printf("      %lf \n", cross[2]);
    printf("          ]\n\n");
}
