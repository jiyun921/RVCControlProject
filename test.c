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
    // Test 1: 장애물 없고 먼지 없을때 move forward 해야함 
    int tick = 5;

    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);

    TEST_ASSERT_TRUE(cmds.MotorCommands.MoveForward);
}

void test2(void) {
    // Test 2: 장애물 없고 먼지 없을때 clean 해야함 
    int tick = 5;

    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.CleanerCommands.Clean);
}

void test3(void) {
    // Test 3: 장애물 없고 먼지 없을 때 powerupcleaning 안해야함  
    int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
}

void test4(void) {
    // Test 4: 장애물 없고 먼지 있을 때 clean 해야함  
   int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.CleanerCommands.PowerUpCleaning);
  
}

void test5(void) {
    // Test 5: 장애물 없고 먼지 있을 때 powerupclean 해야함  
    int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.CleanerCommands.PowerUpCleaning);
  
}

void test6(void) {
    // Test 6: 장애물 앞에만 있고 먼지 없을 때 moveforward 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.MoveForward);
    
}

void test7(void) {
    // Test 7: 장애물 앞에만 있고 먼지 없을 때 turn left 해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.TurnLeft);
    
}

void test8(void) {
    // Test 8: 장애물 앞에만 있고 먼지 없을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
   
}

void test9(void) {
    // Test 9: 장애물 앞에만 있고 먼지 없을 때 powerupcleaning 안해야함  
   int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
   
}

void test10(void) {
    // Test 10: 장애물 앞에만 있고 먼지 있을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
    
}

void test11(void) {
    // Test 11: 장애물 앞에만 있고 먼지 있을 때 powerupcleaning 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
    
}

void test12(void) {
    // Test 12: 장애물 앞쪽,왼쪽에 있고 먼지 없을 때 moveforward 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.MoveForward);
    
}

void test13(void) {
    // Test 13: 장애물 앞쪽,왼쪽에 있고 먼지 없을 때 turn left 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.TurnLeft);
   
}

void test14(void) {
    // Test 14: 장애물 앞쪽,왼쪽에 있고 먼지 없을 때 turn right 해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.TurnRight);
    
}

void test15(void) {
    // Test 15: 장애물 앞쪽,왼쪽에 있고 먼지 없을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
    
}

void test16(void) {
    // Test 16: 장애물 앞쪽,왼쪽에 있고 먼지 없을 때 powerupcleaning 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
    
}

void test17(void) {
    // Test 17: 장애물 앞쪽,왼쪽에 있고 먼지 있을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
   
}

void test18(void) {
    // Test 18: 장애물 앞쪽,왼쪽에 있고 먼지 있을 때 powerupcleaning 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
    
}

void test19(void) {
    // Test 19: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 moveforward 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.MoveForward);
    
}

void test20(void) {
    // Test 20: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 turn left 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.TurnLeft);
   
}

void test21(void) {
    // Test 21: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 turn right 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.TurnRight);
    
}

void test22(void) {
    // Test 22: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 turn backward 해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.TurnBackward);
   
}

void test23(void) {
    // Test 23: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
    
}

void test24(void) {
    // Test 24: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 없을 때 powerupcleaning 안해야함  
   int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
   
}

void test25(void) {
    // Test 25: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 있을 때 clean 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.Clean);
   
}

void test26(void) {
    // Test 26: 장애물 앞쪽,왼쪽,오른쪽에 있고 먼지 있을 때 powerupcleaning 안해야함  
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = true;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.CleanerCommands.PowerUpCleaning);
   
}

void test27(void) {
    // Test 27: 장애물 앞쪽,오른쪽에 있고 먼지 없을 때 turn left 해야함   
    int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.TurnLeft);
  
}

void test28(void) {
    // Test 28: 장애물 앞쪽,오른쪽에 있고 먼지 없을 때 turn right 안해야함   
   int tick = 5;
    
    bool frontsensorinput = true;
    bool leftsensorinput = false;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_FALSE(cmds.MotorCommands.TurnRight);
   
}

void test29(void) {
    // Test 29: 장애물 왼쪽,오른쪽에 있고 먼지 없을 때 moveforward 해야함   
    int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = true;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.MoveForward);

}

void test30(void) {
    // Test 30: 장애물 왼쪽에 있고 먼지 없을 때 moveforward 해야함   
    int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = true;
    bool rightsensorinput = false;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.MoveForward);
    
}

void test31(void) {
    // Test 31: 장애물 오른쪽에 있고 먼지 없을 때 moveforward 해야함   
   int tick = 5;
    
    bool frontsensorinput = false;
    bool leftsensorinput = false;
    bool rightsensorinput = true;
    bool dustsensorinput = false;

    // 센서 인터페이스
    bool frontObstacle = FrontSensorInterface(frontsensorinput, tick);
    bool leftObstacle = LeftSensorInterface(leftsensorinput, tick);
    bool rightObstacle = RightSensorInterface(rightsensorinput, tick);
    bool dustexistence = DustSensorInterface(dustsensorinput, tick);
    
    // Obstacle Location, Dust Existence 데이터 생성
    ObstacleLocation loc = DetermineObstacleLocation(frontObstacle, leftObstacle, rightObstacle);
    DustExistence dust = DetermineDustExistence(dustexistence);
    
    Commands cmds = Controller(&loc, &dust, tick);
    TEST_ASSERT_TRUE(cmds.MotorCommands.MoveForward);
 
}


