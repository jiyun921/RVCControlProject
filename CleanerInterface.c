#include "header.h"

void CleanerInterface(Commands *commands){

    if (commands->CleanerCommands.PowerUpCleaning) {
        printf("Cleaner : PowerUp\n");
    }
    else if (commands->CleanerCommands.Clean) {
        printf("Cleaner : ON\n");
    }
    else {
        printf("Cleaner : OFF\n");
    }

}