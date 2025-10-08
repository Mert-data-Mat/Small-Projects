//HC-SR04 code for messing around
const int trigPin = 9;   // or 5 for ESP32
const int echoPin = 10;  // or 18 for ESP32

long duration;
float distance_cm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a 10 µs pulse to trigger and we can ping more but
  // only at close range (around 1 meter on my tests)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse width from echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance in cm
  distance_cm = duration * 0.034 / 2;
  if (distance_cm <= 3) Serial.print("APPROACHING MINIMUM DISTANCE\n"); //It can measure untile the 2.4 cm at least at mine.
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(2000);
}

