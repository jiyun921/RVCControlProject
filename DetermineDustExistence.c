#include "header.h"

bool DustSensorInterface(DustExistence *dust, bool dustinput, int tick) {

    dust->exist = dustinput; 
    printf("Dust: %s\n", dust->exist ? "Detected" : "Not Detected");
    return dust->exist;
    
}