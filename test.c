#include "unity.h"
#include "header.h"
#include "test.h"

void setUp(void) {
    // 테스트 시작 전 설정
}

void tearDown(void) {
    // 테스트 종료 후 설정
}

void test1(void) {
    // Test 1: 장애물이 없고 먼지가 없을 때 전진 여부 테스트
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {false};
    int tick = 5;

    Commands cmds = Controller(&location, &dust, tick);

    TEST_ASSERT_TRUE(cmds.MotorCommands.MoveForward);
}
void test2(void) {
    // Test 2: 장애물이 앞쪽에 있고 먼지가 있을 때 좌회전 여부 테스트 
    ObstacleLocation location = {true, false, false};
    DustExistence dust = {false};
    int tick = 5;

    Commands cmds = Controller(&location, &dust, tick);

    TEST_ASSERT_TRUE(cmds.MotorCommands.TurnLeft);
    
}

void test3(void) {
    // Test 3: 장애물이 없고 먼지가 있을 때 청소 세기 강화 여부 테스트  
    ObstacleLocation location = {false, false, false};
    DustExistence dust = {true};
    int tick = 5;

    Commands cmds = Controller(&location, &dust, tick);

    TEST_ASSERT_TRUE(cmds.CleanerCommands.PowerUpCleaning);
    
}


// void test2(void) {
//     // Test 2: 장애물이 앞쪽에 있을 때 좌회전 여부 테스트
//     ObstacleLocation location = {true, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test3(void) {
//     // Test 3: 먼지가 있고 전진 시 먼지가 제거되는지 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(result);
// }

// void test4(void) {
//     // Test 4: 장애물이 앞측, 좌측, 우측에 있을 때 뒤로 돌기 테스트
//     ObstacleLocation location = {true, true, true};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool moveBackward = false;
//     Controller(&location, &dust, tick, &moveBackward);

//     TEST_ASSERT_TRUE(moveBackward);
// }

// void test5(void) {
//     // Test 5: 장애물이 앞측, 좌측에 있을 때 우회전 여부 테스트
//     ObstacleLocation location = {true, true, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test6(void) {
//     // Test 6: 장애물이 없고 먼지가 있을 때 전진 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test7(void) {
//     // Test 7: 장애물이 없고 먼지가 없을 때 오른쪽 회전 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool turnRight = false;
//     Controller(&location, &dust, tick, &turnRight);

//     TEST_ASSERT_TRUE(turnRight);
// }

// void test8(void) {
//     // Test 8: 장애물이 없고 먼지가 없을 때 좌회전 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test9(void) {
//     // Test 9: 장애물이 우측에 있을 때 우회전 여부 테스트
//     ObstacleLocation location = {true, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test10(void) {
//     // Test 10: 전진 후 좌회전 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool moveForward = false;
//     bool turnLeft = false;
//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_TRUE(moveForward);

//     Controller(&location, &dust, tick, &turnLeft);
//     TEST_ASSERT_TRUE(turnLeft);
// }

// void test11(void) {
//     // Test 11: 먼지가 있고 우회전 시 먼지 제거 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(result);
// }

// void test12(void) {
//     // Test 12: 장애물이 앞에 있으면 좌회전 하는 테스트
//     ObstacleLocation location = {true, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test13(void) {
//     // Test 13: 장애물이 없고 먼지가 있을 때 후진 안 함 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool moveBackward = false;
//     Controller(&location, &dust, tick, &moveBackward);

//     TEST_ASSERT_FALSE(moveBackward);
// }

// void test14(void) {
//     // Test 14: 장애물이 우측에 있을 때 좌회전 가능 여부 테스트
//     ObstacleLocation location = {false, true, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test15(void) {
//     // Test 15: 장애물이 없고 먼지가 없을 때 전진 및 청소 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool moveForward = false;
//     bool clean = false;

//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_TRUE(moveForward);
//     TEST_ASSERT_FALSE(dust.exist);
// }

// void test16(void) {
//     // Test 16: 장애물이 없고 먼지가 있을 때 먼지 제거 후 전진 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(result);
// }

// void test17(void) {
//     // Test 17: 먼지가 없고 장애물이 없을 때 회전 및 전진 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool turnLeft = false;
//     bool moveForward = false;

//     Controller(&location, &dust, tick, &turnLeft);
//     TEST_ASSERT_TRUE(turnLeft);

//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_TRUE(moveForward);
// }

// void test18(void) {
//     // Test 18: 장애물이 없고 먼지가 없을 때 청소기 동작 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool clean = false;
//     Controller(&location, &dust, tick, &clean);

//     TEST_ASSERT_TRUE(clean);
// }

// void test19(void) {
//     // Test 19: 장애물이 없고 먼지가 있을 때 먼지 제거 후 전진 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool moveForward = false;
//     Controller(&location, &dust, tick, &moveForward);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(moveForward);
// }

// void test20(void) {
//     // Test 20: 먼지가 없으면 전진할 수 있는지 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test21(void) {
//     // Test 21: 장애물이 없고 먼지가 있을 때 청소 및 전진 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool clean = false;
//     bool moveForward = false;
//     Controller(&location, &dust, tick, &clean);
//     Controller(&location, &dust, tick, &moveForward);

//     TEST_ASSERT_TRUE(clean);
//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(moveForward);
// }

// void test22(void) {
//     // Test 22: 먼지가 있으면 전진하며 먼지 제거 여부 테스트
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool moveForward = false;
//     Controller(&location, &dust, tick, &moveForward);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(moveForward);
// }

// void test23(void) {
//     // Test 23: 전진하면서 좌회전
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool moveForward = false;
//     bool turnLeft = false;

//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_TRUE(moveForward);

//     Controller(&location, &dust, tick, &turnLeft);
//     TEST_ASSERT_TRUE(turnLeft);
// }

// void test24(void) {
//     // Test 24: 먼지가 있으면 전진하고 먼지 제거 후 좌회전
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool moveForward = false;
//     bool turnLeft = false;

//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(moveForward);

//     Controller(&location, &dust, tick, &turnLeft);
//     TEST_ASSERT_TRUE(turnLeft);
// }

// void test25(void) {
//     // Test 25: 장애물이 없고 먼지가 있으면 전진하며 먼지 제거
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_FALSE(dust.exist);
//     TEST_ASSERT_TRUE(result);
// }

// void test26(void) {
//     // Test 26: 장애물이 없고 먼지가 없으면 전진만 하기
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test27(void) {
//     // Test 27: 장애물이 없고 먼지가 있을 때 좌회전
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test28(void) {
//     // Test 28: 장애물이 앞과 좌측에 있지만 먼지가 있을 때 우회전 후 먼지 제거 테스트
//     ObstacleLocation location = {true, true, false};
//     DustExistence dust = {true};
//     int tick = 5;

//     bool turnRight = false;
//     bool dustRemoved = false;

//     Controller(&location, &dust, tick, &turnRight);
//     if (turnRight) {
//         dust.exist = false; // 먼지 제거
//         dustRemoved = true;
//     }

//     TEST_ASSERT_TRUE(turnRight);
//     TEST_ASSERT_TRUE(dustRemoved);
// }

// void test29(void) {
//     // Test 29: 장애물이 우측에 있을 때 회전 여부
//     ObstacleLocation location = {false, true, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool result = false;
//     Controller(&location, &dust, tick, &result);

//     TEST_ASSERT_TRUE(result);
// }

// void test30(void) {
//     // Test 30: 장애물 없을 때 전진과 좌회전
//     ObstacleLocation location = {false, false, false};
//     DustExistence dust = {false};
//     int tick = 5;

//     bool moveForward = false;
//     bool turnLeft = false;

//     Controller(&location, &dust, tick, &moveForward);
//     TEST_ASSERT_TRUE(moveForward);

//     Controller(&location, &dust, tick, &turnLeft);
//     TEST_ASSERT_TRUE(turnLeft);
// }
