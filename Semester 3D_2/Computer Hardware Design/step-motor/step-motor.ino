// X Motor
#define m1_dir_PIN  55
#define m1_step_PIN 54

/*
 spec motor = 1.8deg / step
 360 / 1.8 = 200 step is Revolution

*/

#define stepsPerRevolution 200

void setup() {
  pinMode(m1_dir_PIN, OUTPUT);
  pinMode(m1_step_PIN, OUTPUT);

}

void loop() {
  // M1 Direction 
  digitalWrite(m1_dir_PIN, HIGH);

  // Low delay == High speed
  // High delay == Low speed
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(m1_step_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(m1_step_PIN, LOW);
    delayMicroseconds(1000);
  }

  delay(1000);

}
