#include "header.h"
#include <stdio.h>
#include "unistd.h"

Commands Controller(ObstacleLocation *location, DustExistence *dust, int tick) {

    sleep(tick);
    Commands cmds = {
        .MotorCommands = {false, false, false, false},
        .CleanerCommands = {false, false} // 기본적으로 청소기 비활성화
    };

    //Controller에서 MoveForward, TurnLeft, TurnRight, TurnBackward
    if (!location->FrontObstacle) {
        cmds.MotorCommands.MoveForward = true;
    } 
    else {
        if (!location->LeftObstacle) {
            cmds.MotorCommands.TurnLeft = true;
        } else if (!location->RightObstacle) {
            cmds.MotorCommands.TurnRight = true;
        } else {
            cmds.MotorCommands.TurnBackward = true;
        }
    }
    sleep(tick);

    // Controller에서 Clean, PowerUpCleaning
    if(cmds.MotorCommands.MoveForward){
        if(dust->exist){
            cmds.CleanerCommands.Clean = true;
            cmds.CleanerCommands.PowerUpCleaning = true;
           
        }
        else{
            cmds.CleanerCommands.PowerUpCleaning = false;
            cmds.CleanerCommands.Clean = true;
           
        }
    }else{
        cmds.CleanerCommands.Clean = false;
        cmds.CleanerCommands.PowerUpCleaning = false;
    }

    // MoveForward, TurnLeft, TurnRight, TurnBackward에서 MotorInterface
    MotorInterface(&cmds);
    // Clean, PowerupCleaning에서 CleanerInterface
    CleanerInterface(&cmds);

    return cmds;
    
}
