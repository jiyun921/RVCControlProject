#include "header.h"

void CleanerInterface(DustExistence *dust, Commands *commands){
    
    if(commands->MotorCommands.MoveForward){
        if(dust->exist){
            commands->CleanerCommands.Clean = true;
            commands->CleanerCommands.PowerUpCleaning = true;
            printf("Cleaner : PowerUP\n");
        }
        else{
            commands->CleanerCommands.PowerUpCleaning = false;
            commands->CleanerCommands.Clean = true;
            printf("Cleaner : ON\n");
        }

    }else{
        commands->CleanerCommands.Clean = false;
        commands->CleanerCommands.PowerUpCleaning = false;
        printf("Cleaner : OFF\n");
    }


}