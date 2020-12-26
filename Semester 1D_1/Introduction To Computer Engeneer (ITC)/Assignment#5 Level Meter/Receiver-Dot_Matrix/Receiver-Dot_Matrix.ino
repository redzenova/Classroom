/*==============================================
 * (Nano)Monitor Angle  <--> (Nano)Measure Angle
 *          by Nithi & Raweeroj KMITL
 *  Introduction to Computer Enginerring Class
*/

/*================ Include Lib =================*/
  #include <LedControl.h>
  #include <SoftwareSerial.h>
  #include "FontLEDClock.h"
  
/*==============================================*/

/*================ Pin Define ==================*/
  #define CS_PIN   11  // SPI SS
  #define CLK_PIN  13  // SPI SCK
  #define DIN_PIN  9  // SPI MOSI
  #define NUM_MAT   4  // Number of Dot Matrix
  #define INTENSITY 8  // LED Intensity
/*==============================================*/
  LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, NUM_MAT);
  SoftwareSerial toMeasure(4,3); //(RX,TX)

  
void setup() {
  /*buadrate HW&SW Serial Setup*/
  Serial.begin(9600);
  toMeasure.begin(9600);

  /*Setting LED Dot Matrix 8x32*/
  int devices=lc.getDeviceCount();  
  for(int address=0;address<devices;address++) {
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
}

int i=3;
int buff;

void loop() {
  if(i<0){
    i=5;
  }
  
  /*ทำการแสดงผลออกทาง Dot Matrix ทีละตัวอักสร
    โดยจะทำการเปลี่ยน Address ของ LED ไปด้วย
    โดยวนซ้ำ 5 รอบ ตามฟอเเมท xxx.xx ของข้อมูลที่ส่งมา
    เป็นทศนิยม 2 หลัก แต่แสดงผลแค่ xxx.x 
  */
  if(toMeasure.available()){
    /*รับค่าจาก Software Serial จากอีกบอร์ด*/
    buff = toMeasure.read() ;
    if(buff!='.' && buff!='\n'){
      
      for(int col=0;col<5;col++){
        lc.setColumn(i,col+2,myfont[31 + buff -'0'][col]);
      } 

      lc.setLed(0,7,0,1);
      i--;
    }
  }
}
