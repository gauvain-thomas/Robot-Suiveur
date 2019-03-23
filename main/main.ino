/**

*/

#include "motor_shield.h"
#include "ultrasonic.h"
#include "obstacle_detection.h"

void setup() {
  Serial.begin(9600); //Set Serial port communication to 9600 bauds

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
      stop():
  }

  delay(1000);
}
