/**
  Following robot code, check readme.md file for further informations
*/

#include "motor_shield.h"
#include "ultrasonic.h"
#include "obstacle_avoidance.h"

char direction;

void setup() {
  Serial.begin(9600); //Set Serial port communication to 9600 bauds

  // Initializing modules
  //init_motor_shield();
  //init_obstacle_avoidance();
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
      while(direction == 'r') {
       right();
       direction = check_direction();
       delay(200); 
      }
      break;
    case 'l':
      while(direction == 'l') {
        left();
        direction = check_direction();
        delay(200);
      }
    default:
      stop();
  }
  delay(500);
}
