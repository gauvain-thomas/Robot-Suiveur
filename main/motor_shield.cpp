/**
Controls robot's motors with an Arduino motor shield
*/

#include "Arduino.h"
#include "motor_shield.h"

static const int speedMotorLeft = 8;
static const int speedMotorRight = 13;

static const int in1 = 9;
static const int in2 = 10;
static const int in3 = 11;
static const int in4 = 12;

void init_motor_shield() {
  pinMode(speedMotorRight, OUTPUT);
  pinMode(speedMotorLeft, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void forward(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Forward !");
}

void back(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

    // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Back !");
}

void right(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Left !");
}

void left(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Right !");
}

void stop() {
  // Turn off both motors
  analogWrite(speedMotorLeft, 0);
  analogWrite(speedMotorRight, 0);

  Serial.println("Stop !");
}

static int convert_speed(int speed) {
  constrain(speed, 0, 100);
  map(speed, 0, 100, 0, 255);
  return speed;
}
