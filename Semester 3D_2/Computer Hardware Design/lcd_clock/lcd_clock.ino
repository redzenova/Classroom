#include <Wire.h> 

#include <LiquidCrystal_I2C.h> //ประกาศ Library ของจอ I2C
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

byte num0[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};

byte num1[] = {
  B00000,
  B00000,
  B01111,
  B10001,
  B11101,
  B01101,
  B00001,
  B01110
};

byte num2[] = {
  B10000,
  B10000,
  B10101,
  B10111,
  B10101,
  B10001,
  B10001,
  B01110
};

byte num3[] = {
  B00000,
  B00000,
  B11011,
  B11111,
  B10101,
  B10001,
  B11001,
  B11001
};

byte num4[] = {
  B00000,
  B00001,
  B00001,
  B01110,
  B10000,
  B10110,
  B10100,
  B01111
};

byte num5[] = {
  B00000,
  B00001,
  B00101,
  B01110,
  B10000,
  B10110,
  B10100,
  B01111
};

byte num6[] = {
  B00000,
  B10000,
  B10110,
  B01001,
  B00001,
  B11001,
  B10001,
  B01110
};

byte num7[] = {
  B00001,
  B00001,
  B00001,
  B11011,
  B11111,
  B10101,
  B11001,
  B11001
};

byte num8[] = {
  B00000,
  B00001,
  B01101,
  B10011,
  B10000,
  B10011,
  B10101,
  B11011
};

byte num9[] = {
  B00001,
  B00001,
  B11001,
  B10111,
  B10100,
  B10010,
  B11001,
  B11001
};


void setup() {
  lcd.begin();
}

void loop() {
  show_clock();
}

void show_clock(){
  lcd.createChar(0, num2);
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.createChar(1, num3);
  lcd.setCursor(1,0);
  lcd.write(1);
  lcd.setCursor(2,0);
  lcd.print(":");
  lcd.createChar(2, num5);
  lcd.setCursor(3,0);
  lcd.write(2);
  lcd.createChar(3, num9);
  lcd.setCursor(4,0);
  lcd.write(3);
 }
