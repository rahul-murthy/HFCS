#include<NewPing.h>
#include<AFMotor.h>
#include<stdio.h>

#define TRIG1 A0
#define TRIG2 A2
#define TRIG3 A4
#define ECHO1 A1
#define ECHO2 A3
#define ECHO3 A5
//#define IR1 A4
//#define IR2 A5
//#define IR3 2
#define MAX_DISTANCE 500
  

NewPing sonar1(TRIG1, ECHO1);
NewPing sonar2(TRIG2, ECHO2);
NewPing sonar3(TRIG3, ECHO3);


AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG3, OUTPUT);
  
//  pinMode(IR1, INPUT);
//  pinMode(IR2, INPUT);
//  pinMode(IR3, INPUT);
}

void loop() {
  delay(100);
  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  unsigned int distance3 = sonar3.ping_cm();
  
//  int leftIR = digitalRead(IR1);
//  int centerIR = digitalRead(IR2);
//  int rightIR = digitalRead(IR3);

  if ((distance2 < 50) && (distance2 > 3)) {
    // go straight for a couple of seconds without polling
    Serial.print("straight");
    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);
    Motor2.run(FORWARD);
//    Motor3.setSpeed(150);
//    Motor3.run(FORWARD);
//    Motor4.setSpeed(150);
//    Motor4.run(FORWARD);
    delay(1500);
  }
  else if ((distance1 < 50) && (distance1 > 3)) {
    // if right us is triggered
    // turn to where front us is facing where the right was facing and go for a couple of seconds without polling
    Serial.print("right");
    Motor1.setSpeed(200);
    Motor1.run(FORWARD);
    Motor2.setSpeed(0);
    Motor2.run(FORWARD);
//    Motor3.setSpeed(200);
//    Motor3.run(FORWARD);
//    Motor4.setSpeed(100);
//    Motor4.run(FORWARD);
    delay(1500);
  }
  else if ((distance3 < 50) && (distance3 > 3)) {
    // if left us is triggered
    // turn to where front us is facing where the left was facing and go for a couple of seconds without polling
    Serial.print("left");
    Motor1.setSpeed(0);
    Motor1.run(FORWARD);
    Motor2.setSpeed(200);
    Motor2.run(FORWARD);
//    Motor3.setSpeed(150);
//    Motor3.run(FORWARD);
//    Motor4.setSpeed(200);
//    Motor4.run(FORWARD);
    delay(1500);
  }
  else {
    Serial.print("lost");
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    Motor3.run(RELEASE);
    Motor4.run(RELEASE);
  }
 }
