/**
  * Ultrasonic module
  * Used to detect person postion
*/

#include "Arduino.h"
#include "ultrasonic.h"

static const int pinEcho1 = 6;
static const int pinTrig1 = 7;

static const int pinEcho2 = 4;
static const int pinTrig2 = 5;

// static const int pinEcho3 = 0;
// static const int pinTrig3 = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;


void init_ultrasonic() {
  pinMode(pinEcho1, INPUT);
  pinMode(pinTrig1, OUTPUT);

  pinMode(pinEcho2, INPUT);
  pinMode(pinTrig2, OUTPUT);

  pinMode(12, INPUT);
  // pinMode(pinEcho3, INPUT);
  // pinMode(pinTrig3, OUTPUT);
}

char check_direction() {
  const float pi = 3,1415926535;
  char direction;
  float distance;
  float angle;
  int sensor_dist = 100 ; // Distance between sensors (mm)
  float sound_speed = 0,343; // Speed of sound (mm/µs)
  // long gauche = 0;
  // long droite = 0;
  // long compteur = 0;

  Serial.println("Checking direction...");
  /*
  while(compteur < 5000) {
    digitalWrite(pinTrig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig1, LOW);

    digitalWrite(pinTrig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig2, LOW);

    // digitalWrite(pinTrig3, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(pinTrig3, LOW);

    if (digitalRead(pinEcho1) == 1) {
      gauche++;
    }
    if (digitalRead(pinEcho2) == 1) {
      droite++;
    }
    compteur++;
    delayMicroseconds(10);
  }


  if(gauche > droite) {
    Serial.println("Gauche");
    direction = 'l';
  }
  else {
    Serial.println("Droite");
    direction = 'r';
  }
  Serial.println(gauche);
  Serial.println(droite);
  */

while(digitalRead(12) == 0) {
  Serial.println(digitalRead(12));
}

Serial.println(digitalRead(12));

digitalWrite(pinTrig1, HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig1, LOW);
time1 = pulseIn(pinEcho1, HIGH);

digitalWrite(pinTrig2, HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig2, LOW);
time2 = pulseIn(pinEcho2, HIGH);

d1 = time1 * sound_speed;
d2 = time2 * sound_speed;

distance = sqrt((sq(d1) - sq(d2)) / 4 );
angle = pi - acos((sq(d1) - sq(d2)) / (sensor_dist * sqrt(2*sq(d1) + 2*sq(d2) - sq(sensor_dist))));

Serial.println(distance);
Serial.println(angle);

if(distance < 800) {
  direction = 's';
}
else if (angle > 0,1) {
  direction = 'r';
}
else if(angle < 0,1) {
  direction = 'l';
}
else {
  direction = 'f'
}

delay(10);
return direction;
}
