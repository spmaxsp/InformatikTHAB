#include<stdio.h> 

void main() {
    const unsigned int x = 10;
    const unsigned int y = 5;

    int myArray[x][y];
    int myVector[y];

    int outVector[x];

    int s = 1;
    int c = 0;
    while(c<=x*y){
        myArray[c/y][c%y] = c+s;
        c++;
    }

    c = 1;
    for(unsigned int i=0; i<x; i++){
        for(unsigned int j=0; j<y; j++){
            myArray[i][j] = c++;
        }
    }

    int incr = 10;
    for(unsigned int i=0; i<y; i){
        myVector[i] = (i+1) * incr;
    }

    printf("arr = [\n");
    for(unsigned int i=0; i<x; i++){
        printf("       ");
        for(unsigned int j=0; j<y; j++){
            printf("%d  ", myArray[i][j]);
        }
        printf("\n");
    }
    printf("      ] \n\n");

    printf("vect = [\n");
    for(unsigned int i=0; i<y; i++){
        printf("        %d\n", myVector[i]);
    }
    printf("      ] \n\n");


    for(unsigned int i=0; i<x; i++){
        outVector[i] = 0;
        for(unsigned int j=0; j<y; j++){
            outVector[i] = myArray[i][j] * myVector[j] + outVector[i];
        }
    }

    printf("out_vect = [\n");
    for(unsigned int i=0; i<x; i++){
        printf("        %d\n", outVector[i]);
    }
    printf("      ] \n\n");

    return;
}
