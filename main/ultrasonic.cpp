/**
  * Ultrasonic module
  * Used to detect person postion
*/

#include "Arduino.h"
#include "ultrasonic.h"

// Ultrasonic sensors pins
static const int pinEcho1 = 6;
static const int pinTrig1 = 7;

static const int pinEcho2 = 4;
static const int pinTrig2 = 5;

// static const int pinEcho3 = 0;
// static const int pinTrig3 = 0;


static unsigned long time1 = 0;
static unsigned long time2 = 0;
// static unsigned long time3 = 0;

static int interval = 20; // Time betweel each wave (µs)

static long time_sync; // Delay (µs)

float moyenne = 0;
long iter = 0;

void init_ultrasonic() {
  /*** Initialize ultrasonic module***/

  pinMode(pinEcho1, INPUT);
  pinMode(pinTrig1, OUTPUT);

  pinMode(pinEcho2, INPUT);
  pinMode(pinTrig2, OUTPUT);

  // pinMode(12, INPUT);
  // pinMode(pinEcho3, INPUT);
  // pinMode(pinTrig3, OUTPUT);

  sync();
  delay(8000);
}

static void sync() {
  /*** Synchronize robot's Arduino with beacon's Arduino ***/
  Serial.println("Sync");
  long time = 0;
  while(time == 0) {
    digitalWrite(pinTrig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig1, LOW);
    time = pulseIn(pinEcho1, HIGH, 12500);
    Serial.print("Sync : ");
    Serial.println(time);
  }
  time_sync = micros();
  Serial.print("SYNC : ");
  Serial.println(time_sync);
}

char check_direction() {
  const float pi = 3.1415926535;
  char direction;
  float distance;
  float angle;
  int sensor_dist = 100 ; // Distance between sensors (mm)
  float sound_speed = 0.343; // Speed of sound (mm/µs)

  // Serial.println("Checking direction...");

  while( (micros() - time_sync) % interval) {}
  digitalWrite(pinTrig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig1, LOW);
  time1 = pulseIn(pinEcho1, HIGH);

  while( (micros() - time_sync) % interval) {}
  digitalWrite(pinTrig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig2, LOW);
  time2 = pulseIn(pinEcho2, HIGH);

  Serial.println(iter);
  if(iter < 200) {
    moyenne += time1*sound_speed;
    iter++;
  }
  else {
    moyenne = moyenne/iter;
    Serial.print("Distance : ");
    Serial.println(moyenne);
    moyenne = 0;
    iter = 0;
    delay(5000);
  }
/*
  while( (micros() - time_sync) % interval) {}
  digitalWrite(pinTrig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig1, LOW);
  time3 = pulseIn(pinEcho1, HIGH);
*/

}
