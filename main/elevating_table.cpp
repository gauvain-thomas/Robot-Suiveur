/**
  *
*/

#include "Arduino.h"
#include "elevating_table.h"

static const int pinIR1 = 0;
static const int pinIR2 = 0;
static const int pinContactSensor = 0;

void init_elevating_table() {
  pinMode(pinIR1, INPUT);
  pinMode(pinIR2, INPUT);
}

void update_table() {
  bool = digitalRead(pinIR2);
  bool = digitalRead(pinIR1);
}
