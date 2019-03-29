const int echo = 0;
const int trig = 0;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  digitalRead(trig);

  delayMicroseconds(10);
}
