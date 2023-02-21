// X Motor
#define m1_dir_PIN  55
#define m1_step_PIN 54
#define m1_en_PIN   38

// Y Motor
#define m2_dir_PIN  61
#define m2_step_PIN 60
#define m2_en_PIN   56

// Z Motor
#define m3_dir_PIN  48
#define m3_step_PIN 46
#define m3_en_PIN   62

// E0 Motor
#define m4_dir_PIN  28
#define m4_step_PIN 26
#define m4_en_PIN   24

// E1 Motor
#define m5_dir_PIN  34
#define m5_step_PIN 36
#define m5_en_PIN   30

#define stepsPerRevolution 200

void setup() {
  pinMode(m1_dir_PIN, OUTPUT);
  pinMode(m1_step_PIN, OUTPUT);
  pinMode(m1_en_PIN, OUTPUT);

  pinMode(m2_dir_PIN, OUTPUT);
  pinMode(m2_step_PIN, OUTPUT);
  pinMode(m2_en_PIN, OUTPUT);

  pinMode(m3_dir_PIN, OUTPUT);
  pinMode(m3_step_PIN, OUTPUT);
  pinMode(m3_en_PIN, OUTPUT);

  pinMode(m4_dir_PIN, OUTPUT);
  pinMode(m4_step_PIN, OUTPUT);
  pinMode(m4_en_PIN, OUTPUT);

  pinMode(m5_dir_PIN, OUTPUT);
  pinMode(m5_step_PIN, OUTPUT);
  pinMode(m5_en_PIN, OUTPUT);

  //digitalWrite(m1_en_PIN, LOW);
}

void loop() {
  // M1 Direction clockwise
  digitalWrite(m1_dir_PIN, HIGH);
  digitalWrite(m2_dir_PIN, LOW);
  digitalWrite(m3_dir_PIN, HIGH);
  digitalWrite(m4_dir_PIN, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(m1_step_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(m1_step_PIN, LOW);
    delayMicroseconds(1000);
//
//    digitalWrite(m2_step_PIN, HIGH);
//    delayMicroseconds(250);
//    digitalWrite(m2_step_PIN, LOW);
//    delayMicroseconds(250);
//
//    digitalWrite(m3_step_PIN, HIGH);
//    delayMicroseconds(250);
//    digitalWrite(m3_step_PIN, LOW);
//    delayMicroseconds(250);
//
//    digitalWrite(m4_step_PIN, HIGH);
//    delayMicroseconds(250);
//    digitalWrite(m4_step_PIN, LOW);
//    delayMicroseconds(250);
  }

  delay(1000);

}
