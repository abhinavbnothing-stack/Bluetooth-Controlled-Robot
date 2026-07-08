/*
  Bluetooth Controlled Robot
  Components: Arduino Uno, HC-05 Bluetooth Module,
  L298N Motor Driver, 2x DC Motors
  Author: Abhinav B
*/

#include <SoftwareSerial.h>

// HC-05 Bluetooth Module
// RX = Pin 10, TX = Pin 11
SoftwareSerial BTSerial(10, 11);

// Motor Pins
int ENA = 9;  int IN1 = 2;  int IN2 = 3;
int ENB = 6;  int IN3 = 4;  int IN4 = 5;

int driveSpeed = 150;
char command;

void setup() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  BTSerial.begin(9600);
  Serial.begin(9600);
  stopBot();
}

// Movement Functions
void moveForward() {
  analogWrite(ENA, driveSpeed);
  analogWrite(ENB, driveSpeed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  Serial.println("Forward");
}

void moveBackward() {
  analogWrite(ENA, driveSpeed);
  analogWrite(ENB, driveSpeed);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
  Serial.println("Backward");
}

void turnLeft() {
  analogWrite(ENA, 0);
  analogWrite(ENB, driveSpeed);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  Serial.println("Left");
}

void turnRight() {
  analogWrite(ENA, driveSpeed);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  Serial.println("Stop");
}

// Main Loop
void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();
    Serial.print("Command received: ");
    Serial.println(command);

    switch (command) {
      case 'F': moveForward();  break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft();     break;
      case 'R': turnRight();    break;
      case 'S': stopBot();      break;
    }
  }
}
