#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4); // จอกว้าง 16 ตัวอักษร 2 บรรทัด รหัสประจำตัว 0x3F


int pin = 9;

unsigned long duration;    

int count = 0;
int x=0 ;


void setup() {
  lcd.begin();

  // initialize serial communications at 9600 bps:

  Serial.begin(9600);

  pinMode(pin, INPUT);

}
void print2digits(int number){
  if(number >= 0 && number < 10)
  lcd.print("0");
  lcd.print(number);
}


void loop() {

  
    duration = pulseIn(pin, HIGH, 1000000);

    float time=duration/1000.00;

    Serial.print("DelT=");

    Serial.print(time);

    Serial.println(" ms");

    if (time > 2){

      count = count + 1;

    Serial.println(count);

    }

    if (time ==0){
      
      if (count > 0 &&count < 2){
        x=x+1;
        lcd.clear();
        lcd.setCursor(7,1);
         print2digits(x);
          lcd.setCursor(10,1);
        lcd.print("Bath");
          
            
        }
         if (count > 1 &&count < 3){
        x=x+2;
        lcd.clear();
        lcd.setCursor(7,1);
         print2digits(x);
          lcd.setCursor(10,1);
        lcd.print("Bath");
        
            
        }

       if (count > 4 &&count < 6){
        x=x+5;
        lcd.clear();
        lcd.setCursor(7,1);
         print2digits(x);
          lcd.setCursor(10,1);
        lcd.print("Bath");
          
          
        }

      if (count > 7){  //&&count < 11
        x=x+10;
        lcd.clear();
        lcd.setCursor(7,1);
        print2digits(x);
        lcd.setCursor(10,1);
        lcd.print("Bath");
        
          

        }

     count=0;


    }
    }
