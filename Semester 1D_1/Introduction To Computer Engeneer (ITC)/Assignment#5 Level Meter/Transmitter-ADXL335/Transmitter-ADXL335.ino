/*==============================================
 * (Nano)Measure Angle  <--> (Nano)Monitor Angle
 *          by Nithi & Raweeroj KMITL
 *  Introduction to Computer Enginerring Class
*/

/*================ Include Lib =================*/
  #include <math.h> 
  #include <SoftwareSerial.h>
  
/*==============================================*/
  
/*================ Pin Define ==================*/
  #define buttonPin  8
  #define buzzerPin  6
/*==============================================*/

  SoftwareSerial toMonitor(4,3); //(RX,TX)
  
/*=============== Gobal Variable ===============*/
  double xMax = 400;
  double xMin = 512;
  double yMax = 400;
  double yMin = 512;
  double zMax = 400;
  double zMin = 512;

  /*==== pre-processor ====*/
  int avg(int);
  void AutoCalibrate(int,int,int);


void setup() {
  Serial.begin(9600);
  toMonitor.begin(9600);
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  analogWrite(A4,1023);
  analogWrite(A0,   0);

  double xRaw = avg(A3);
  double yRaw = avg(A2);
  double zRaw = avg(A1);

  double radius;
  double degree;

  double Zavg;
  double Zg;

  /*เป็นการ Calibation ตัว ADXL335 และกำหนดค่า Min/Max*/
  if (digitalRead(buttonPin) == LOW){
    tone(buzzerPin,825,20);
    AutoCalibrate(xRaw, yRaw, zRaw);
  }

  /*คำนวนมุมอันเกิดจากการเปลี่ยนแปลงของค่า Z ที่เปลี่ยนไป*/
    Zavg = (zMax+zMin)/2;
    Zg   = (zMax-((zMax+zMin)/2));

    if(zRaw>=zMin && zRaw<=zMax){
      if(zRaw>=Zavg){           
        radius =  PI - acos((zRaw-Zavg)/Zg) ;
      }
      else{                         
        radius = PI - acos((zRaw-Zavg)/Zg);
      }
      degree = radius*180/PI;
    }

    Serial.print(" Max = ");
    Serial.print(zMax);
    Serial.print(" Min = ");
    Serial.print(zMin);
    Serial.print(" Zavg = ");
    Serial.print(Zavg);
    Serial.print(" Zg = ");
    Serial.print(Zg);
    Serial.print(" Z = ");
    Serial.println(zRaw);
    Serial.println(degree);

    /*เงื่อนไขและการส่งข้อมูลผ่าน Software Serial*/
    if(degree<100){
      toMonitor.print('0');
    }
    if(degree<10){
      toMonitor.print('0');
    }
    toMonitor.println(degree);
    delay(500);
  
}

/*ฟังก์ชัน average ค่าข้อมูลในตอนอ่านค่า*/
int avg(int x){
  long sum = 0;
  analogRead(x);
  delay(1);
  for(int i=0; i<10 ; i++){
    sum += analogRead(x);
  }
  return sum/10;
}

/*ฟังก์ชันตรววจสอบและเก็บค่า Min/Max ของเเต่ละแกน */
void AutoCalibrate(int xRaw, int yRaw, int zRaw)
{
  Serial.println("Calibrate");
  if (xRaw < xMin)
  {
    xMin = xRaw;
  }
  if (xRaw > xMax)
  {
    xMax = xRaw;
  }
  
  if (yRaw < yMin)
  {
    yMin = yRaw;
  }
  if (yRaw > yMax)
  {
    yMax = yRaw;
  }
 
  if (zRaw < zMin)
  {
    zMin = zRaw;
  }
  if (zRaw > zMax)
  {
    zMax = zRaw;
  }
}
