#include<math.h>

double geoMittel(double zahl1, double zahl2){
    if (zahl1 > 0 && zahl2 > 0){
        double res = sqrt(zahl1 * zahl2);
        return res;
    }
    else {
        return -1;
    }
}