#include "header.h"
#include <stdio.h>

Commands Controller(ObstacleLocation *location, DustExistence *dust, int tick) {
    // 센서 인터페이스 호출
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

    printf("forward : %s\n", cmds.MotorCommands.MoveForward ? "true" : "false");
    printf("left : %s\n", cmds.MotorCommands.TurnLeft ? "true" : "false");
    printf("right : %s\n", cmds.MotorCommands.TurnRight ? "true" : "false");
    printf("back : %s\n", cmds.MotorCommands.TurnBackward ? "true" : "false");

    printf("Clean : %s\n", cmds.CleanerCommands.Clean ? "true" : "false");
    printf("Powerup Clean : %s\n", cmds.CleanerCommands.PowerUpCleaning ? "true" : "false");
    
    return cmds;
    
}
