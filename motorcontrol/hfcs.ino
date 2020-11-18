#include<NewPing.h>
#include<AFMotor.h>
#include<stdio.h>

#define TRIG1 A3
//#define TRIG2 A3
#define ECHO1 A2
//#define ECHO2 A2
#define MAX_DISTANCE 100
  

NewPing sonar1(TRIG1, ECHO1);
//NewPing sonar2(TRIG2, ECHO2);


AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  //pinMode(ECHO2, INPUT);
  //pinMode(TRIG2, OUTPUT);
}

void loop() {
  delay(50);
  unsigned int distance1 = sonar1.ping_cm();
  //unsigned int distance2 = sonar2.ping_cm();

  Serial.println(distance1);
  //Serial.println(distance2);

  if ((distance1 <= 50) && (distance1 != 0)) {
    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);
    Motor2.run(FORWARD);
    Motor3.setSpeed(150);
    Motor3.run(FORWARD);
    Motor4.setSpeed(150);
    Motor4.run(FORWARD);
  }
  else {
    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);
    Motor2.run(BACKWARD);
    Motor3.setSpeed(150);
    Motor3.run(BACKWARD);
    Motor4.setSpeed(150);
    Motor4.run(FORWARD);
  }
 }
