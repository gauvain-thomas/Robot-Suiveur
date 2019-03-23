/**
Controls robot's motors with an Arduino motor shield
*/

#include "Arduino.h"
#include "motor_shield.h"

static const int speedMotorLeft = 0;
static const int speedMotorRight = 0;


static void setup() {
  pinMode(speedMotorRight, OUTPUT);
  pinMode(speedMotorLeft, OUTPUT);
}

void forward(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // digitalWrite();
  // digitalWrite();

  Serial.println("Forward !");
}

void back(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // digitalWrite();
  // digitalWrite();

  Serial.println("Back !");
}

void right(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // digitalWrite();
  // digitalWrite();

  Serial.println("Left !");
}

void left(int speed=100) {
  speed = convert_speed(speed);

  // Set speed of both motors
  analogWrite(speedMotorLeft, speed);
  analogWrite(speedMotorRight, speed);

  // digitalWrite();
  // digitalWrite();

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
