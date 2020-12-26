/*==============================================
 *      Finite State Machine (Traffic Light)
 *          by Nithi & Raweeroj KMITL
 *  Introduction to Computer Enginerring Class
  ==============================================*/
  
/*================ Pin Define ==================*/
#define NS_RD_PIN  7
#define NS_YL_PIN  6
#define NS_GN_PIN  5
#define EW_RD_PIN  4
#define EW_YL_PIN  3
#define EW_GN_PIN  2

#define HM_RD_PIN  8
#define HM_GN_PIN  9

#define NS_SW_PIN  10
#define EW_SW_PIN  11
#define HM_SW_PIN  12

#define goNS   0
#define waitNS 1
#define goEW   2
#define waitEW 3
#define goHM   4
#define waitHM_NS 5
#define waitHM_EW 6
/*==============================================*/

/*================== Varible ===================*/
  int pin[8] = {5, 6, 7, 4, 3, 2, 9, 8};
  int sw[3]  = {10, 11, 12};
  int input = 0, input1, input2, input3;

  unsigned long t1 = 0;

  unsigned currentState = 0;
  unsigned previousState;
/*==============================================*/

/*============================================= State ===============================================*/
struct State {
  unsigned long ST_Out;
  unsigned long Time;
  unsigned long Next[8];
};

typedef const struct State SType;

SType FSM[7] = {
  {B00110010  ,1000 ,{goNS  ,waitHM_NS  ,waitEW  ,waitHM_NS  ,goNS    ,waitHM_NS  ,waitEW  ,waitEW}},
  {B10001010  ,500  ,{goNS  ,goNS       ,goNS    ,goNS       ,goNS    ,goNS       ,goNS    ,goNS}},
  {B10000110  ,1000 ,{goEW  ,waitHM_EW  ,goEW    ,waitHM_EW  ,waitNS  ,waitHM_EW  ,waitNS  ,waitHM_EW}},
  {B01010010  ,500  ,{goEW  ,goEW       ,goEW    ,goEW       ,goEW    ,goEW       ,goEW    ,goEW}},
  {B10010001  ,1000 ,{goHM  ,goHM       ,goEW    ,goEW       ,goNS    ,goNS       ,goNS    ,goNS}},
  {B01010010  ,500  ,{goHM  ,goHM       ,goHM    ,goHM       ,goHM    ,goHM       ,goHM    ,goHM}},
  {B10001010  ,500  ,{goHM  ,goHM       ,goHM    ,goHM       ,goHM    ,goHM       ,goHM    ,goHM}},
};

/*====================================================================================================*/

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(pin[i], OUTPUT);
  }
  for (int j = 0; j < 3; j++) {
    pinMode(sw[j], INPUT_PULLUP);
  }


void loop() {

  /* ---------------- Blink when Humen across -------------- */
  if(previousState == goHM && currentState != goHM){
    long timer;
    for(int i=0;i<4;i++){
      timer = millis();
      digitalWrite(HM_GN_PIN,LOW);
      while(millis()-timer<=120);{
      }
      timer = millis();
      digitalWrite(HM_GN_PIN,HIGH);
      while(millis()-timer<=120);{
      }
    }
  }
  /*-----------------------------------------------------------*/
    
  
  unsigned long temp = FSM[currentState].ST_Out;
  digitalWrite(NS_RD_PIN, !(temp & B10000000));
  digitalWrite(NS_YL_PIN, !(temp & B01000000));
  digitalWrite(NS_GN_PIN, !(temp & B00100000));

  digitalWrite(EW_RD_PIN, !(temp & B00010000));
  digitalWrite(EW_YL_PIN, !(temp & B00001000));
  digitalWrite(EW_GN_PIN, !(temp & B00000100));

  digitalWrite(HM_RD_PIN, !(temp & B00000010));
  digitalWrite(HM_GN_PIN, !(temp & B00000001));

  delay(FSM[currentState].Time);
  
  Serial.println(temp);

  /*================== Input and Change State ======================*/
  /*  อ่านค่า Input ใส่นิเสธเพราะ input เป็น pullup เข้ามา
      ค่าที่อ่านได้จะมีขนาดเป็น 3 bit
      Bit     [3][2][1] => 000 001 010 011 100 101 110 111
      Prefix  [4][2][1] => เมื่อแปลงเป็น base10 จะได้ 8 ค่า คือ 0-7
  */
  input1 = !digitalRead(NS_SW_PIN);
  input2 = !digitalRead(EW_SW_PIN);
  input3 = !digitalRead(HM_SW_PIN);

  input = (input1 * 4) + (input2 * 2) + input3 ;

  previousState = currentState;
  currentState = FSM[currentState].Next[input];
  
  /*Serial.print("State : FSM[");
  Serial.print(currentState);
  Serial.print("].Next[");
  Serial.print(input);
  Serial.println("]");
  */
  /*===============================================================*/
}
