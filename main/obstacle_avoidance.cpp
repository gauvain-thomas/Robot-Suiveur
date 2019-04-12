/**
Infrared obstacle detection module
*/

#include "Arduino.h"
#include "obstacle_avoidance.h"
#include "motor_shield.h"

static const int pinIRLeft;
static const int pinIRRight;


void init_obstacle_avoidance() {
  pinMode(pinIRLeft, INPUT);
  pinMode(pinIRRight, INPUT);
}

void avoid_obstacles() {
  static bool leftObstacle;
  static bool rightObstacle;

  leftObstacle = digitalRead(pinIRLeft);
  rightObstacle = digitalRead(pinIRRight);

  if(!leftObstacle && rightObstacle) { // Obstacle on left
    while(leftObstacle) {
      right();
    }
    stop();

  }

  else if(leftObstacle && !rightObstacle) { // Obstacle on right
    while(rightObstacle) {
      left();
    }
    stop();
  }

  // else if(!leftObstacle && !rightObstacle) { //Obstacles on both sides
  //
  // }
}
