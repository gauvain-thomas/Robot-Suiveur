const int echo = 8;
const int trig = 9;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  digitalRead(echo);
  delayMicroseconds(10);
}
