#include<NewPing.h>
#include<AFMotor.h>
#include<SoftwareSerial.h>
#include<stdio.h>

#define TRIG1 A0
#define TRIG2 A2
#define TRIG3 A4
#define ECHO1 A1
#define ECHO2 A3
#define ECHO3 A5
#define RX 13
#define TX 2
#define MAX_DISTANCE 500
  

NewPing sonar1(TRIG1, ECHO1);
NewPing sonar2(TRIG2, ECHO2);
NewPing sonar3(TRIG3, ECHO3);

AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);

SoftwareSerial ble(13, 2);

bool state1 = false;

void setup() {
  // Serial.begin(9600);
  // Serial.println("Hello");
  ble.begin(9600);
  ble.println("Howdy");
  
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG3, OUTPUT);
}

void loop() {
  delay(500);
  
  unsigned int left = sonar1.convert_cm(sonar1.ping_median(3));
  unsigned int straight = sonar2.convert_cm(sonar2.ping_median(3));
  unsigned int right = sonar3.convert_cm(sonar3.ping_median(3));

  if (ble.available()) {
    ble.println("found something");
  }

  if (ble.read() == -1) 
  {
    ble.println("nothing");  
  }
  else 
  {
    ble.println("something");  
  }

  /* while ((straight < 60) && (straight > 25)) {
    // go straight for a couple of seconds without polling
    Serial.print("straight\n");
    Motor1.setSpeed(150);
    Motor1.run(FORWARD);
    Motor2.setSpeed(150);
    Motor2.run(FORWARD);
    state1 = false;
    delay(100);

    straight = sonar2.convert_cm(sonar2.ping_median(3));
  }
  
  while ((straight <= 25) && (straight > 0)) 
  {
    // stop now
    Serial.print("straight stop\n");
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    delay(100);

    straight = sonar2.convert_cm(sonar2.ping_median(3));

    left = sonar1.convert_cm(sonar1.ping_median(3));
    right = sonar3.convert_cm(sonar3.ping_median(3));
  
    if ((left < 60) && (left > 25)) {
      // if right us is triggered
      // turn to where front us is facing where the right was facing and go for a couple of seconds without polling
      Serial.print("right\n");
      Motor1.run(RELEASE);
      Motor2.run(RELEASE);
      delay(1000);
      straight = sonar2.ping_cm();
      while ((straight > 60) || (straight == 0)) {
        Motor1.setSpeed(255);
        Motor1.run(FORWARD);
        Motor2.setSpeed(255);
        Motor2.run(BACKWARD);
        delay(100);
        Motor1.run(RELEASE);
        Motor2.run(RELEASE);
        delay(500);
        straight = sonar2.ping_cm();
      }
      
      break;
    }
    else if ((right < 60) && (right > 25)) {
      // if left us is triggered
      // turn to where front us is facing where the left was facing and go for a couple of seconds without polling
      Serial.print("left\n");
      Motor1.run(RELEASE);
      Motor2.run(RELEASE);
      delay(1000);
      straight = sonar2.ping_cm();
      while ((straight > 60) || (straight == 0)) {
        Motor1.setSpeed(255);
        Motor1.run(BACKWARD);
        Motor2.setSpeed(255);
        Motor2.run(FORWARD);
        delay(100);
        Motor1.run(RELEASE);
        Motor2.run(RELEASE);
        delay(500);
        straight = sonar2.ping_cm();
      }
      
      break;
    }
    else {
      Serial.print("lost\n");
      Motor1.run(RELEASE);
      Motor2.run(RELEASE);
  
      // Bluetooth module code here
    }
  } */

//if (straight <= 200) {
//  Serial.print("straight: ");
//  Serial.println(straight);
//  Serial.print("\n");
//}
//
//if (right <= 200) {
//  Serial.print("right: ");
//  Serial.println(right);
//  Serial.print("\n");
//}
//
//if (left <= 200) {
//  Serial.print("left: ");
//  Serial.println(left);
//  Serial.print("\n");
//}




  if (((straight < 60) && (straight > 25)) || state1) {
    // go straight for a couple of seconds without polling
    // Serial.print("straight\n");
    Motor1.setSpeed(170);
    Motor1.run(FORWARD);
    Motor2.setSpeed(170);
    Motor2.run(FORWARD);
    state1 = false;
    delay(100);
  }
  else if ((straight <= 25) && (straight > 0)) 
  {
    // stop now
    // Serial.print("straight stop\n");
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    delay(100);
  }
  else if ((right < 60) && (right > 25)) {
    // if right us is triggered
    // turn to where front us is facing where the right was facing and go for a couple of seconds without polling
    // Serial.print("right\n");
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    delay(1000);
    straight = sonar2.ping_cm();
    while ((straight > 60) || (straight == 0)) {
      Motor1.setSpeed(220);
      Motor1.run(BACKWARD);
      Motor2.setSpeed(220);
      Motor2.run(FORWARD);
      delay(100);
      Motor1.run(RELEASE);
      Motor2.run(RELEASE);
      delay(500);
      straight = sonar2.ping_cm();
    }
    state1 == true;
  }
  else if ((left < 60) && (left > 25)) {
    // if left us is triggered
    // turn to where front us is facing where the left was facing and go for a couple of seconds without polling
    // Serial.print("left\n");
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    delay(1000);
    straight = sonar2.ping_cm();
    while ((straight > 60) || (straight == 0)) {
      Motor1.setSpeed(220);
      Motor1.run(FORWARD);
      Motor2.setSpeed(220);
      Motor2.run(BACKWARD);
      delay(100);
      Motor1.run(RELEASE);
      Motor2.run(RELEASE);
      delay(500);
      straight = sonar2.ping_cm();
    }
    state1 == true;
  }
  else {
    // Serial.print("lost\n");
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);

    // Bluetooth module code here
  }
}
