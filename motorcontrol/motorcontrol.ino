#include <AFMotor.h>

// used pins:   3-8, 11-12
// unused pins: 0-1(BT), 2, 9-10 (use only when necessary), 13-19

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // min speed: 200
  // max speed: 255
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(5000);
//  motor1.run(BACKWARD);
//  motor2.run(BACKWARD);
//  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);
//  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(10000);
}
