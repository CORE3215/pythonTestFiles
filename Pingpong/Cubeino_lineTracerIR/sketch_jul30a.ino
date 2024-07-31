#include <Servo.h>
#include "Cubeino.h"
#include <SoftwareSerial.h>

#define GCUBE_TOTAL 2  // 이 프로젝트에 사용할 전체 큐브의 숫자
SoftwareSerial myCubeSerial (2, 3); // 2:RX, 3:TX for uART 보드 제조사에 맞게 핀번호 변경하여 사용

unsigned int l_count=0;
unsigned int left=0;
unsigned int right=0;

void setup() {
  Serial.begin(115200);
  myCubeSerial.begin(115200);
  Serial.println("start");

  wait_for_first_cube_connected(myCubeSerial);
  wait_for_all_cube_connected(GCUBE_TOTAL, myCubeSerial);

  Serial.println("all connected");
}

void loop() {
  left = analogRead(A2);
  right = analogRead(A3);

  Serial.print("left: ");
  Serial.print(left);
  Serial.print("  right: ");
  Serial.println(right);

  if(left < 100 & right< 100) {
    send_multi_cube_speed(GCUBE_TOTAL, -30, 30, 0, 0, 0, 0, 0, 0, myCubeSerial);
  }
  else if(left > 100) {
    send_multi_cube_speed(GCUBE_TOTAL, 11, 38, 0, 0, 0, 0, 0, 0, myCubeSerial);
  }
  else if(right > 100) {
    send_multi_cube_speed(GCUBE_TOTAL, -38, -11, 0, 0, 0, 0, 0, 0, myCubeSerial);
  }
  else{
    send_multi_cube_speed(GCUBE_TOTAL, 0, 0, 0, 0, 0, 0, 0, 0, myCubeSerial);
  }
}
