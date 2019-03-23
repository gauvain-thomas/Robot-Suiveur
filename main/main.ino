/**
  Following robot code, check readme.md file for further informations
*/

#include "motor_shield.h"
#include "ultrasonic.h"
#include "obstacle_detection.h"

char direction;

void setup() {
  Serial.begin(9600); //Set Serial port communication to 9600 bauds

  init_motor_shield();
  // init_obstacle_detection();
  init_ultrasonic();

  Serial.println("Ready to go !");
}

void loop() {
  direction = check_direction();

  switch (direction) {
    case 'f':
      forward();
      break;
    case 'b':
      back();
      break;
    case 'r':
      right();
      break;
    case 'l':
      left();
    default:
      stop();
  }

  delay(1000);
}
