#define buzzer 11
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;


const int pin7segment[8] = {2,3,4,5,6,7,8,9};
const int dice7segment[7] = {14,123,95,206,221,253};
const int pinSwitch[2] = {10,12};
const bool pressed = LOW;
int Dice;
int randomDice;
long current,start;

void setup() {
  Serial.begin(115200);

  for(int i = 0;i < 8;i++) {
    pinMode(pin7segment[i], OUTPUT);
  }

  pinMode(pinSwitch[0], INPUT_PULLUP);
  pinMode(pinSwitch[1], INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
    
  displayDice(Dice = 1);
}

void loop() {
  randomSeed(analogRead(A5));
  current = millis();
  handle_button(pinSwitch[0]);
  handle_button(pinSwitch[1]);
}

void handle_button(int pin) {
  bool ReadSwitch = digitalRead(pin);
  if(ReadSwitch == pressed) {
    beep(d, 20);
    delay(150);
    if(pin == pinSwitch[0]) {
      if(randomDice) {
        randomDice = 0;
        analogWrite(A0, 0);
        analogWrite(A1, 0);
        displayDice(Dice = 1);
      }else{
        if(Dice < 6) {
          displayDice(++Dice);
        }else{
          Dice = 1;
          displayDice(Dice);
        }
      }
    }else{
      if(randomDice) {
        clear_status();
      }
      randomDice = random(1, 7);
      int multiply = 10;
      for(int i = 1;i <= 20;i++){
        displayDice(random(1, 7));
        delay(1*multiply*i);
        beep(cH, 20);
      }
      displayDice(randomDice);
      delay(210);
      start = millis();
      show_status();
    }
  }else if(randomDice){
    if(current - start < 2000){
      show_status();
    }else{
      start = current;
    }
  }
}

void show_status() {
  if(Dice == randomDice) {
    analogWrite(A1, 1024);

    for(int i = 0;i < 8;i++){
      digitalWrite(pin7segment[i], LOW);
    }

    if(current - start >= 1000){
      displayDice(randomDice);
    }else if(current - start >= 875) {
      digitalWrite(pin7segment[0], HIGH);
      digitalWrite(pin7segment[4], HIGH);
    }else if(current - start >= 750) {
      digitalWrite(pin7segment[1], HIGH);
      digitalWrite(pin7segment[5], HIGH);
    }else if(current - start >= 625) {
      digitalWrite(pin7segment[2], HIGH);
      digitalWrite(pin7segment[7], HIGH);
    }else if(current - start >= 500) {
      digitalWrite(pin7segment[0], HIGH);
      digitalWrite(pin7segment[4], HIGH);
    }else if(current - start >= 375) {
      digitalWrite(pin7segment[0], HIGH);
      digitalWrite(pin7segment[4], HIGH);
    }else if(current - start >= 250) {
      digitalWrite(pin7segment[1], HIGH);
      digitalWrite(pin7segment[5], HIGH);
    }else if(current - start >= 125) {
      digitalWrite(pin7segment[2], HIGH);
      digitalWrite(pin7segment[7], HIGH);
    }else if(current - start >= 0) {
      digitalWrite(pin7segment[0], HIGH);
      digitalWrite(pin7segment[4], HIGH);
    }
  }else{
    analogWrite(A0, 1024);

    for(int i = 0;i < 8;i++){
      digitalWrite(pin7segment[i], LOW);
    }

    if(current - start <= 375) {
      if(current - start >= 0) {
        digitalWrite(pin7segment[7], HIGH);
      }
      if(current - start >= 125) {
        digitalWrite(pin7segment[6], HIGH);
      }
      if(current - start >= 250) {
        digitalWrite(pin7segment[2], HIGH);
      }
    }else if(current - start <= 750) {
      if(current - start >= 375) {
        digitalWrite(pin7segment[1], HIGH);
      }
      if(current - start >= 500) {
        digitalWrite(pin7segment[6], HIGH);
      }
      if(current - start >= 625) {
        digitalWrite(pin7segment[5], HIGH);
      }
    }else if(current - start <= 1500) {
      digitalWrite(pin7segment[1], HIGH);
      digitalWrite(pin7segment[2], HIGH);
      digitalWrite(pin7segment[5], HIGH);
      digitalWrite(pin7segment[6], HIGH);
      digitalWrite(pin7segment[7], HIGH);
    }else{
      displayDice(randomDice);
    }
  }
}

void clear_status() {
  analogWrite(A0, 0);
  analogWrite(A1, 0);
}

void displayDice(int num) {
  for(int i = 0;i < 8;i++){
    digitalWrite(pin7segment[i], bitRead(dice7segment[num - 1],i));
  }
}

void beep(int note, int duration)
{
  tone(buzzer, note, duration);
}
