#include "header.h"
#include "unistd.h"

bool FrontSensorInterface(ObstacleLocation *loc, bool frontinput, int tick) {
    loc->FrontObstacle = frontinput;
    printf("Front Obstacle: %s\n", loc->FrontObstacle ? "Detected" : "Not Detected");
    // sleep(tick);
    return loc->FrontObstacle;
    
}

bool LeftSensorInterface(ObstacleLocation *loc, bool leftinput, int tick) {
    loc->LeftObstacle = leftinput;
    printf("Left Obstacle: %s\n", loc->LeftObstacle ? "Detected" : "Not Detected");
    // sleep(tick);
    return loc->LeftObstacle;
}

bool RightSensorInterface(ObstacleLocation *loc, bool rightinput, int tick) {
    loc->RightObstacle = rightinput;
    printf("Right Obstacle: %s\n", loc->RightObstacle ? "Detected" : "Not Detected");
    // sleep(tick);
    return loc->RightObstacle;
}

