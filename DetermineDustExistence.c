#include "header.h"
#include "unistd.h"

bool DustSensorInterface(bool dustinput, int tick) {
    sleep(tick);
    printf("Dust : %s\n", dustinput ? "Detected" : "Not Detected");
    return dustinput;
}

DustExistence DetermineDustExistence(bool dustexistence) {
    DustExistence dust; 
    dust.exist = dustexistence;
    return dust;
}