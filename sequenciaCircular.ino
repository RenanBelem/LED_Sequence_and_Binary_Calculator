int x = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(x + 2, HIGH);
  delay(1000);
  digitalWrite(x + 2, LOW);
  x = (x + 1) % 3;
}
