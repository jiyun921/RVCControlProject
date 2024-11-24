#include "header.h"

void MotorInterface(ObstacleLocation *loc, Commands *commands){
    
    if (!loc->FrontObstacle) {
        commands->MotorCommands.MoveForward = true;
    } 
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