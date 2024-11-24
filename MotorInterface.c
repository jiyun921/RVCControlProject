#include "header.h"

void MotorInterface(ObstacleLocation *loc, Commands *commands){
    
    if (!loc->FrontObstacle) {
        commands->MotorCommands.MoveForward = true;
    } 
    // 장애물이 있을 때는 회전하거나 후진
    else if (loc->FrontObstacle) {
        if (!loc->LeftObstacle) {
            commands->MotorCommands.TurnLeft = true;
            printf("Turn Left\n");
        } else if (!loc->RightObstacle) {
            commands->MotorCommands.TurnRight = true;
            printf("Turn Right\n");
        } else {
            commands->MotorCommands.TurnBackward = true;
            printf("Turn Backward\n");
        }
    }

}