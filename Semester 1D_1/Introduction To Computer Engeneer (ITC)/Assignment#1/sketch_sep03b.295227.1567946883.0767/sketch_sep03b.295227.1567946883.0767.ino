#define btn1 10
#define btn2 11
#define btn3 12
#define led1 2
#define led2 3
#define led3 4
#define pressed LOW

long Time_start[3] = {0};
long Delay[3] = {0};
bool isBtn1 = false,
     isBtn2 = false,
     isBtn3 = false,
     stat = false;

void setup() {
  Serial.begin(115200);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int ReadSwitch = digitalRead(btn1);

  if (ReadSwitch == pressed && !isBtn3) {
    Serial.println("Pressed Right Switch.");
    delay(250);
    if (!isBtn1) {
      Time_start[0] = millis();
      digitalWrite(led1, HIGH);
      isBtn1 = true;
      Delay[0] = 3000;
    } else {
      digitalWrite(led1, LOW);
      isBtn1 = false;
    }
  }

  ReadSwitch = digitalRead(btn2);
  if (ReadSwitch == pressed && !isBtn1 && !isBtn3) {
    Serial.println("Pressed Center Switch.");
    delay(250);
    Time_start[1] = millis();
    digitalWrite(led2, HIGH);
    isBtn2 = true;
    Delay[1] = 2000;
  }

  ReadSwitch = digitalRead(btn3);
  if (ReadSwitch == HIGH) {
    Serial.println("Pressed Left Switch.");
    delay(250);
    if (!isBtn3) {
      Time_start[2] = millis();
      digitalWrite(led3, HIGH);
      isBtn3 = true;
      Delay[2] = 3000;
    } else {
      digitalWrite(led3, LOW);
      isBtn3 = false;
    }
  }

  if (isBtn1 && millis() - Time_start[0] > Delay[0]) {
    digitalWrite(led1, LOW);
    isBtn1 = false;
  }
  if (isBtn2) {
    if (millis() - Time_start[1] > 500 && Delay[1] > 0) {
      if (stat) {
        digitalWrite(led2, HIGH);
        stat = false;
      } else {
        digitalWrite(led2, LOW);
        if (Delay[1] > 1000) {
          stat = true;
        }
      }
      Time_start[1] = millis();
      Delay[1] -= 500;
    }
  }
  if (isBtn3 && millis() - Time_start[2] > Delay[2]) {
    digitalWrite(led3, LOW);
    isBtn3 = false;
  }
}
