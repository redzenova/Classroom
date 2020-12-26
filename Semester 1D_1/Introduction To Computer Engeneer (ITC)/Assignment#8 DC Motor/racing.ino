#define enA 5
#define enB 10
#define in1 6
#define in2 7
#define in3 8
#define in4 9

enum Direction {FORWARD = 0, LEFT, RIGHT, STOP};

void setup()
{
  Serial.begin(9600);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
}
void loop()
{
    Serial.println("FORWARD");
    go(Direction::FORWARD);
    Serial.println("STOP");
    go(Direction::STOP);
    Serial.println("RIGHT");
    go(Direction::RIGHT);
    Serial.println("STOP");
    go(Direction::STOP);
}

void go(byte dt) {
  switch (dt) {
    case Direction::FORWARD:
      // Left Wheel
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 200);

      // Right Wheel
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 200);
      
      delay(800);

      break;
    case Direction::RIGHT:
      // Left Wheel
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 200);

      // Right Wheel
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 200);

      delay(250);

      break;
    case Direction::STOP:
      // Left Wheel
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      // Right Wheel
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      delay(500);

      break;
  }
}
