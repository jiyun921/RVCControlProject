#include "header.h"

bool DustSensorInterface(DustExistence *dust, bool dustinput, int tick) {

    dust->exist = dustinput; // 구조체의 FrontObstacle 업데이트
    printf("Dust: %s\n", dust->exist ? "Detected" : "Not Detected");
    return dust->exist;
    
}