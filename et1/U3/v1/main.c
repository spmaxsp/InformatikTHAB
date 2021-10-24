#include<stdio.h> 
#include<ctype.h>
 
void main() { 
    char mode;
    float f;
    float c;
    while(1){
        printf("Umrechnung von:\n\t F: Farenheit in Celcius\n\t C: Celcius in Farenheit \n\n (F/C)");  
        mode = getchar();
        mode = toupper(mode);

        switch (mode)
        {
        case 'C':
            printf("Celcius: ");
            scanf("%f%*c", &c);
            f = (c * 9/5) + 32;
            printf("Farenheit: %f\n", f);
            break;

        case 'F':
            printf("Farenheit: ");
            scanf("%f%*c", &f);
            c = (f - 32) * 5/9;
            printf("Celcius: %f\n", c);
            break;
        
        default:
            return;
        }

        printf("\n--------------------------------------\n\n");
    }
    return;
}