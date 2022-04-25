#include<stdio.h>
#include<string.h>  
#include "vehicle.h"

void vehiclePrint(vehicle *selected_vehicle){
    printf("%s", selected_vehicle->name);
    printf("%d", selected_vehicle->power);
    printf("%f", selected_vehicle->displacement);
    printf("%d", selected_vehicle->max_speed);
    return;
}

void main() {
    vehicle vehicle1;
    strcpy( vehicle1.name, "BMW_G20" );
    vehicle1.power = 134;
    vehicle1.displacement = 1.998;
    vehicle1.max_speed = 238;

    vehiclePrint(&vehicle1);
    return;
}
