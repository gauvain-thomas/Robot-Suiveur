const int pinIRDown = 0;
const int pinIRUp = 0;
const int pinContactSensor = 0;

const int in1 = 8;
const int in2 = 9;
const int speedMotor = 10;

void setup() {
  pinMode(pinIRDown, INPUT);
  pinMode(pinIRUp, INPUT);
}

void loop() {
  bool down = digitalRead(pinIRDown);
  bool up = digitalRead(pinIRUp);
  while( !(down && !up) ) {
    if(!down) {
      table_up();      
    }
    else {
      table_down();
    }
    delay(100);
  }

  delay(100);
}


void table_up() {
  Serial.println("UP");
  analogWrite(speedMotor, 255);

  // turn on motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
}

void table_down() {
  Serial.println("DOWN");
  analogWrite(speedMotor, 255);

  // turn on motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
}
