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

Commands Controller(ObstacleLocation *location, DustExistence *dust, int tick);

bool FrontSensorInterface(bool FrontSensorInput, int tick);
bool LeftSensorInterface(bool LeftSensorInput, int tick);
bool RightSensorInterface(bool RightSensorInput, int tick);
bool DustSensorInterface(bool dustinput, int tick);
ObstacleLocation DetermineObstacleLocation(bool FrontObstacle, bool LeftObstacle, bool RightObstacle);
DustExistence DetermineDustExistence(bool dustexistence); 
void MotorInterface(Commands *commands);
void CleanerInterface(Commands *commands);
