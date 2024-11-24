#include "header.h"
#include <stdio.h>

void Controller(ObstacleLocation *location, DustExistence *dust, int tick, bool *result) {
    
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

    // 먼지가 있으면 제거
    if (dust->exist) {
        dust->exist = false; // 먼지 제거
    }

    /// 동작 결정 로직 (세밀하게 고려)
    if (!location->FrontObstacle && !dust->exist) {
        // 장애물이 없고 먼지가 없으면 전진 가능
        *result = true;
    } else if (location->FrontObstacle) {
        // 전방에 장애물이 있는 경우
        if (!location->LeftObstacle && !dust->exist) {
            // 전방에 장애물이 있고, 좌측에 장애물이 없고 먼지도 없으면 좌회전 가능
            *result = true;
        } else if (location->LeftObstacle && !location->RightObstacle && !dust->exist) {
            // 전방 및 좌측에 장애물이 있지만 우측에 장애물이 없고 먼지도 없으면 우회전 가능
            *result = true;
        } else {
            // 전방에 장애물이 있는 경우 전진 불가
            *result = false;
        }
    } else if (dust->exist) {
        // 먼지가 있는 경우 전진 불가, 먼지 제거만 가능
        *result = false;
    }
}
