#include <Servo.h>

// Pin definitions
const int TRIG_PIN  = 10;
const int ECHO_PIN  = 11;
const int SERVO_PIN = 9;

Servo radarServo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  radarServo.attach(SERVO_PIN);
}

void loop() {
  // Sweep 0 -> 180
  for (int angle = 0; angle <= 180; angle += 2) {
    radarServo.write(angle);
    delay(30);  // Let servo settle
    long dist = getDistance();
    // Send: angle,distance
    Serial.print(angle);
    Serial.print(",");
    Serial.println(dist);
  }

  // Sweep 180 -> 0
  for (int angle = 180; angle >= 0; angle -= 2) {
    radarServo.write(angle);
    delay(30);
    long dist = getDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(dist);
  }
}

// Returns distance in cm. Returns 999 if out of range.
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  if (duration == 0) return 999;
  return duration * 0.034 / 2;  // cm
}
