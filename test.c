#include "header.h"
#include "test.h"
#include <stdio.h>

void test1() {
    // Test 1: 장애물이 없고 먼지가 없을 때 전진 여부 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (moveForward) {
        printf("Test 1 성공!\n");
    } else {
        printf("Test 1 실패..\n");
    }
}

void test2() {
    // Test 2: 장애물이 앞쪽에 있을 때 좌회전 여부 테스트
    ObstacleLocation location = {true, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (turnLeft) {
        printf("Test 2 성공!\n");
    } else {
        printf("Test 2 실패..\n");
    }
}

void test3() {
    // Test 3: 먼지가 있고 전진 시 먼지가 제거되는지 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;
    
    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (!dust.exist && moveForward) {
        printf("Test 3 성공!\n");
    } else {
        printf("Test 3 실패..\n");
    }
}

void test4() {
    // Test 4: 장애물이 앞에 있을 때 전진 안 함 테스트
    ObstacleLocation location = {false, false, true};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (!moveForward) {
        printf("Test 4 성공!\n");
    } else {
        printf("Test 4 실패..\n");
    }
}

void test5() {
    // Test 5: 장애물이 앞측, 좌측에 있을 때 우회전 여부 테스트
    ObstacleLocation location = {true, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnRight = false;
    Controller(&location, &dust, tick, &turnRight);

    if (turnRight) {
        printf("Test 5 성공!\n");
    } else {
        printf("Test 5 실패..\n");
    }
}

void test6() {
    // Test 6: 장애물이 없고 먼지가 있을 때 전진 여부 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (moveForward) {
        printf("Test 6 성공!\n");
    } else {
        printf("Test 6 실패..\n");
    }
}

void test7() {
    // Test 7: 장애물이 있고 먼지가 없을 때 전진 여부 테스트
    ObstacleLocation location = {false, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (!moveForward) {
        printf("Test 7 성공!\n");
    } else {
        printf("Test 7 실패..\n");
    }
}

void test8() {
    // Test 8: 장애물이 없고 먼지가 없을 때 좌회전 여부 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (turnLeft) {
        printf("Test 8 성공!\n");
    } else {
        printf("Test 8 실패..\n");
    }
}

void test9() {
    // Test 9: 장애물이 우측에 있을 때 우회전 여부 테스트
    ObstacleLocation location = {true, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool turnRight = false;
    Controller(&location, &dust, tick, &turnRight);

    if (turnRight) {
        printf("Test 9 성공!\n");
    } else {
        printf("Test 9 실패..\n");
    }
}

void test10() {
    // Test 10: 전진 후 좌회전 여부 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnLeft = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnLeft);

    if (moveForward && turnLeft) {
        printf("Test 10 성공!\n");
    } else {
        printf("Test 10 실패..\n");
    }
}

void test11() {
    // Test 11: 먼지가 있고 우회전 시 먼지 제거 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool turnRight = false;
    Controller(&location, &dust, tick, &turnRight);

    if (!dust.exist && turnRight) {
        printf("Test 11 성공!\n");
    } else {
        printf("Test 11 실패..\n");
    }
}

void test12() {
    // Test 12: 장애물이 앞에 있으면 좌회전 안 함 테스트
    ObstacleLocation location = {true, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (!turnLeft) {
        printf("Test 12 성공!\n");
    } else {
        printf("Test 12 실패..\n");
    }
}

void test13() {
    // Test 13: 좌측 장애물, 우측 장애물 모두 있을 때 우회전 안 함 테스트
    ObstacleLocation location = {true, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnRight = false;
    Controller(&location, &dust, tick, &turnRight);

    if (!turnRight) {
        printf("Test 13 성공!\n");
    } else {
        printf("Test 13 실패..\n");
    }
}

void test14() {
    // Test 14: 장애물이 우측에 있을 때 좌회전 가능 여부 테스트
    ObstacleLocation location = {false, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (turnLeft) {
        printf("Test 14 성공!\n");
    } else {
        printf("Test 14 실패..\n");
    }
}

void test15() {
    // Test 15: 장애물이 있을 때 전진하지 않고 우회전 여부 테스트
    ObstacleLocation location = {false, true, true};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnRight = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnRight);

    if (!moveForward && turnRight) {
        printf("Test 15 성공!\n");
    } else {
        printf("Test 15 실패..\n");
    }
}

void test16() {
    // Test 16: 장애물이 전방에 있을 때 좌회전 및 전진 여부 테스트
    ObstacleLocation location = {true, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false, moveForward = false;
    Controller(&location, &dust, tick, &turnLeft);
    Controller(&location, &dust, tick, &moveForward);

    if (turnLeft && !moveForward) {
        printf("Test 16 성공!\n");
    } else {
        printf("Test 16 실패..\n");
    }
}

void test17() {
    // Test 17: 먼지가 없고 장애물이 없을 때 회전 및 전진 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false, moveForward = false;
    Controller(&location, &dust, tick, &turnLeft);
    Controller(&location, &dust, tick, &moveForward);

    if (turnLeft && moveForward) {
        printf("Test 17 성공!\n");
    } else {
        printf("Test 17 실패..\n");
    }
}

void test18() {
    // Test 18: 먼지가 있으면 전진하지 않고 먼지만 제거하는지 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (!dust.exist && !moveForward) {
        printf("Test 18 성공!\n");
    } else {
        printf("Test 18 실패..\n");
    }
}

void test19() {
    // Test 19: 장애물이 있는 경우 전진하지 않고 회전 테스트
    ObstacleLocation location = {false, false, true};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnRight = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnRight);

    if (!moveForward && turnRight) {
        printf("Test 19 성공!\n");
    } else {
        printf("Test 19 실패..\n");
    }
}

void test20() {
    // Test 20: 먼지가 없으면 전진할 수 있는지 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (moveForward) {
        printf("Test 20 성공!\n");
    } else {
        printf("Test 20 실패..\n");
    }
}

void test21() {
    // Test 21: 장애물이 왼쪽에 있을 때 좌회전 안 함 테스트
    ObstacleLocation location = {false, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (!turnLeft) {
        printf("Test 21 성공!\n");
    } else {
        printf("Test 21 실패..\n");
    }
}

void test22() {
    // Test 22: 전진하지 않으면 회전 시 전진 여부
    ObstacleLocation location = {false, false, true};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnLeft = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnLeft);

    if (!moveForward && turnLeft) {
        printf("Test 22 성공!\n");
    } else {
        printf("Test 22 실패..\n");
    }
}

void test23() {
    // Test 23: 전진하면서 좌회전
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnLeft = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnLeft);

    if (moveForward && turnLeft) {
        printf("Test 23 성공!\n");
    } else {
        printf("Test 23 실패..\n");
    }
}

void test24() {
    // Test 24: 먼지가 있으면 전진하고 먼지 제거 후 좌회전
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool moveForward = false, turnLeft = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnLeft);

    if (!dust.exist && moveForward && turnLeft) {
        printf("Test 24 성공!\n");
    } else {
        printf("Test 24 실패..\n");
    }
}

void test25() {
    // Test 25: 장애물이 없고 먼지가 있으면 전진하며 먼지 제거
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (!dust.exist && moveForward) {
        printf("Test 25 성공!\n");
    } else {
        printf("Test 25 실패..\n");
    }
}

void test26() {
    // Test 26: 장애물이 없고 먼지가 없으면 전진만 하기
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false;
    Controller(&location, &dust, tick, &moveForward);

    if (moveForward) {
        printf("Test 26 성공!\n");
    } else {
        printf("Test 26 실패..\n");
    }
}

void test27() {
    // Test 27: 장애물이 없고 먼지가 있을 때 좌회전
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (turnLeft) {
        printf("Test 27 성공!\n");
    } else {
        printf("Test 27 실패..\n");
    }
}

void test28() {
    // Test 28: 장애물 왼쪽에 있을 때 좌회전 안함
    ObstacleLocation location = {false, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnLeft = false;
    Controller(&location, &dust, tick, &turnLeft);

    if (!turnLeft) {
        printf("Test 28 성공!\n");
    } else {
        printf("Test 28 실패..\n");
    }
}

void test29() {
    // Test 29: 장애물이 우측에 있을 때 회전 여부
    ObstacleLocation location = {false, true, false};
    DustExistence dust = {false};
    int tick = 5;

    bool turnRight = false;
    Controller(&location, &dust, tick, &turnRight);

    if (turnRight) {
        printf("Test 29 성공!\n");
    } else {
        printf("Test 29 실패..\n");
    }
}

void test30() {
    // Test 30: 장애물 없을 때 전진과 좌회전
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    bool moveForward = false, turnLeft = false;
    Controller(&location, &dust, tick, &moveForward);
    Controller(&location, &dust, tick, &turnLeft);

    if (moveForward && turnLeft) {
        printf("Test 30 성공!\n");
    } else {
        printf("Test 30 실패..\n");
    }
}