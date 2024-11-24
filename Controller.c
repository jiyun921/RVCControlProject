#include "header.h"
#include <stdio.h>

void Controller(ObstacleLocation *location, DustExistence *dust, int tick, bool *result) {
    
    FrontSensorInterface(location, location->FrontObstacle, tick);
    LeftSensorInterface(location, location->LeftObstacle, tick);
    RightSensorInterface(location, location->RightObstacle, tick);
    DustSensorInterface(dust, dust->exist, tick);

    Commands cmds = {
        .MotorCommands = {false, false, false, false},
        .CleanerCommands = {false, false} // 기본적으로 청소기 비활성화
    };

    MotorInterface(location, &cmds);
    CleanerInterface(dust, &cmds);


    if (!location->FrontObstacle && !dust->exist) {
        *result = true; 
    } else if (location->FrontObstacle && !location->LeftObstacle) {
        *result = true; 
    } else if (location->FrontObstacle && location->LeftObstacle && !location->RightObstacle) {
        *result = true; 
    } else {
        *result = false; 
    }
}

