#include "header.h"
#include <stdio.h>

// Controller 함수
void Controller(ObstacleLocation *location, DustExistence *dust, int tick) {

    // SensorInterface 함수 호출
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

}
