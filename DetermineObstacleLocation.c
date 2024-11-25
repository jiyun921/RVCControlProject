#include "header.h"
#include "unistd.h"


bool FrontSensorInterface(bool FrontSensorInput, int tick) {sleep(tick); printf("Front Obstacle : %s\n",FrontSensorInput ? "Detected" : "Not Detected"); return FrontSensorInput;}
bool LeftSensorInterface(bool LeftSensorInput, int tick) {sleep(tick); printf("Left Obstacle : %s\n", LeftSensorInput ? "Detected" : "Not Detected"); return LeftSensorInput;}
bool RightSensorInterface(bool RightSensorInput, int tick) {sleep(tick); printf("Right Obstacle : %s\n", RightSensorInput ? "Detected" : "Not Detected"); return RightSensorInput;}

ObstacleLocation DetermineObstacleLocation(bool FrontObstacle, bool LeftObstacle, bool RightObstacle) {
    ObstacleLocation loc;
    loc.FrontObstacle = FrontObstacle;
    loc.LeftObstacle = LeftObstacle;
    loc.RightObstacle = RightObstacle;
    return loc; 
}



