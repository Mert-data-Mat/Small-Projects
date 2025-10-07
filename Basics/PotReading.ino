void setup() {
  Serial.begin(9600);     // open Serial Monitor at 9600 baud
  delay(200);             // give Serial time to start (helps on UNO R4)
}

void loop() {
  int potValue = analogRead(A0);  // range 0–1023
  Serial.println(potValue);
  delay(1000);                     // print every 0.1s
}