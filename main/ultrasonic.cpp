/**

*/

#include "Arduino.h"
#include "ultrasonic.h"

static const int pinEcho1 = 0;
static const int pinTrig1 = 0;

static const int pinEcho2 = 0;
static const int pinTrig2 = 0;

static const int pinEcho3 = 0;
static const int pinTrig3 = 0;


void init_ultrasonic() {
  pinMode(pinEcho1, INPUT);
  pinMode(pinTrig1, OUTPUT);

  pinMode(pinEcho2, INPUT);
  pinMode(pinTrig2, OUTPUT);

  pinMode(pinEcho3, INPUT);
  pinMode(pinTrig3, OUTPUT);
}

char check_direction() {
  char direction;
  long gauche = 0;
  long droite = 0;
  long compteur = 0;

  Serial.println("Checking direction...")

  while(compteur < 5000) {
    digitalWrite(pinTrig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig1, LOW);

    digitalWrite(pinTrig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig2, LOW);

    digitalWrite(pinTrig3, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig3, LOW);

    if (digitalRead(pinEcho1) == 1) {
    gauche++;
  }
    if (digitalRead(pinEcho2) == 1) {
    droite++;
  }
    compteur++;
    delayMicroseconds(10);

  }

  return direction;
}
