#include "header.h"

void MotorInterface(Commands *commands){

    if (commands->MotorCommands.MoveForward) {
        printf("Move Forward\n");
    }
    else if (commands->MotorCommands.TurnLeft) {
        printf("Turn Left\n");
    }
    else if (commands->MotorCommands.TurnRight) {
        printf("Turn Right\n");
    }
    else {
        printf("Turn Backward\n");
    }
    

}