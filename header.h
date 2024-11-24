#include <stdio.h>
#include <stdbool.h>

// 장애물 위치를 확인
typedef struct {
    bool FrontObstacle;
    bool LeftObstacle;
    bool RightObstacle;
} ObstacleLocation;

typedef struct {
    bool exist;
} DustExistence;

// 모터와 청소기 명령
typedef struct {
    struct {
        bool MoveForward;
        bool TurnLeft;
        bool TurnRight;
        bool TurnBackward;
    } MotorCommands;

    struct {
        bool Clean;
        bool PowerUpCleaning;
    } CleanerCommands;
} Commands;

void Controller();
bool FrontSensorInterface(ObstacleLocation *loc, bool frontinput, int tick);
bool LeftSensorInterface(ObstacleLocation *loc, bool leftinput, int tick);
bool RightSensorInterface(ObstacleLocation *loc, bool rightinput, int tick);
bool DustSensorInterface(DustExistence *dust, bool dustinput, int tick);
void MotorInterface(ObstacleLocation *loc, Commands *commands);
void CleanerInterface(DustExistence *dust, Commands *commands);
