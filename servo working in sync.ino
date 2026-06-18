//360-degree Radar
/*
  Servo A  (Pin 9)  + Sensor A (Triger 10, Echo 11) →  0–180
  Servo B  (Pin 6)  + Sensor B (Trigger 4,  Echo 5)  →  180–360
*/

#include <Servo.h>

const int a_pin = 9;
const int trigger_a = 10;
const int echo_a = 11;

const int b_pin = 6;
const int trigger_b = 4;
const int echo_b = 5;

Servo servoA;
Servo servoB;

const int step  = 2;    
const int pause = 30;   

void setup() {
  Serial.begin(9600);

  servoA.attach(a_pin);
  servoB.attach(b_pin);

  pinMode(trigger_a, OUTPUT); 
  pinMode(echo_a, INPUT);
  pinMode(trigger_b, OUTPUT);
  pinMode(echo_b, INPUT);
}

void loop()
 {

  for (int i = 0; i <= 180; i += step)
  {
    moveandread(a);
  }

  for (int i = 180; i >= 0; i -= step) 
  {
    moveandread(i);
  }
}

void moveandread(int x) {
  servoA.write(x);
  servoB.write(x);  
                     
  delay(pause);

  long distA = getdistance(trigger_a, echo_a);
  long distB = getdistance(trigger_b, echo_b);

  // Sensor A
  Serial.print("A,");
  Serial.print(x);
  Serial.print(",");
  Serial.println(distA);

  // Sensor B
  Serial.print("B,");
  Serial.print(180 + x);
  Serial.print(",");
  Serial.println(distB);
}

// Returns distance in cm
long getdistance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  long distance = pulseIn(echo, HIGH, 10000); 
  if (distance == 0) return 999;
  return distance * 0.034 / 2;
}
