#include "header.h"
#include "unistd.h"

// FrontSensorInterface 구현
bool FrontSensorInterface(ObstacleLocation *loc, bool frontinput, int tick) {

    loc->FrontObstacle = frontinput; // 구조체의 FrontObstacle 업데이트
    printf("Front Obstacle: %s\n", loc->FrontObstacle ? "Detected" : "Not Detected");
    sleep(tick);
    return loc->FrontObstacle;
    
}


// LeftSensorInterface 구현
bool LeftSensorInterface(ObstacleLocation *loc, bool leftinput, int tick) {
    loc->LeftObstacle = leftinput; // 구조체의 LeftObstacle 업데이트
    printf("Left Obstacle: %s\n", loc->LeftObstacle ? "Detected" : "Not Detected");
    sleep(tick);
    return loc->LeftObstacle;
}

// RightSensorInterface 구현
bool RightSensorInterface(ObstacleLocation *loc, bool rightinput, int tick) {
    loc->RightObstacle = rightinput; // 구조체의 RightObstacle 업데이트
    printf("Right Obstacle: %s\n", loc->RightObstacle ? "Detected" : "Not Detected");
    sleep(tick);
    return loc->RightObstacle;
}

