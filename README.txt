
### 빌드 및 실행환경에 대한 설명

1. 개발 환경
   - 프로그래밍 언어: C
   - IDE: Visual Studio Code
   - 운영 체제: macOS

2. 필요한 소프트웨어
   - 컴파일러: GCC
   - 기타 요구사항: 표준 C 라이브러리, Unity 테스트 프레임워크 (unity.h, unity.c, unity_internals.h)

3. 프로젝트 구조
   ```
   .
├── CleanerInterface.c
├── Controller.c
├── DetermineDustExistence.c
├── DetermineObstacle.c
├── MotorInterface.c
├── main.c
├── test.c
├── test.h
├── header.h
├── unity.h
├── unity.c
├── unity_internals.h
   ```

4. 설치 및 실행 방법
   - 컴파일:
     프로젝트 루트 디렉토리에서 터미널을 열고 다음 명령어를 실행합니다:
     ```
     gcc -o robot_vacuum main.c test.c Controller.c DetermineObstacle.c DetermineDustExistence.c MotorInterface.c CleanerInterface.c
     ```

   - 실행:
     컴파일이 완료되면 다음 명령어로 프로그램을 실행합니다:
     ```
     ./robot_vacuum
     ```

5. 테스트 방법
   - `test.c` 파일에는 31개의 테스트 케이스 함수가 포함되어 있습니다.
   - Unity 프레임워크 (unity.h, unity.c, unity_internals.h)를 사용하여 테스트를 진행합니다.
   - 테스트 실행 시, PASS/FAILED 여부를 출력합니다.


