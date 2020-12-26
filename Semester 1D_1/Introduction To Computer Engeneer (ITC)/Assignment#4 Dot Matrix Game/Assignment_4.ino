/*==== ** Snake Game with LED Dot Matrix  
 *          by Nithi & Raweeroj KMITL
 *  Introduction to Computer Enginerring Class
*/

/*================ Include Lib =================*/
  #include <LedControl.h>
  #include "LinkedList.h"
/*==============================================*/

/*================ Pin Define ==================*/
  #define CS_PIN   10  // SPI SS
  #define CLK_PIN  13  // SPI SCK
  #define DIN_PIN  11  // SPI MOSI
  #define NUM_MAT   5  // Number of Dot Matrix
  #define INTENSITY 8  // LED Intensity

  #define PIN_ANALOG_X  A0
  #define PIN_ANALOG_Y  A1
  #define PIN_A  2
  #define PIN_B  3
  #define PIN_C  4
  #define PIN_D  5
  #define PIN_E  6
  #define PIN_F  7
  #define PIN_K  8

  #define buzzer 12
/*==============================================*/

  /* ประกาศ Class LedControl และ 
     ประกาศ LinkedList 
           snake_x => ตำแหน่งงู X
           snake_y => ตำแหน่งงู Y  
  */
  LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, NUM_MAT);
  LinkedList <int> snake_x, snake_y;

/*=============== Gobla Variable ===============*/
  bool game_status = true;
  int devices = lc.getDeviceCount();
  int address;
  int r = 0, c = 0;
  int move_x = 0, move_y = 0;
  int snake_length = 1;
  int tail_address, tail_x, tail_y;
  int food_x, food_y;
  long last_plot = 0;
/*==============================================*/

/*=============== Setup Function ===============*/
void setup() {
  Serial.begin(115200);
  for (int addr = 0; addr < devices; addr++) {
    lc.shutdown(addr, false);
    lc.setIntensity(addr, INTENSITY);
    lc.clearDisplay(addr);
  }

  random_food();
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  noTone(buzzer);
}
/*==============================================*/

/*================ Loop Function ===============*/
void loop() {
  if (game_status) {
    read_joy_stick();
    show_score();
  }

  /* เงื่อนไขตรงนี้สำหรับ Reset เกมใหม่เมื่อกดปุ่ม F */
  if (!digitalRead(PIN_F)) { 
    game_status = true;
    snake_x.clear();        // ลบค่าใน LinkedList snake_x, snake_y
    snake_y.clear();        
    snake_length = 1;
    move_x = 0;
    move_y = 0;
    r = 0;
    c = 0;
    
    for (int addr = 0; addr < devices; addr++) {
      lc.shutdown(addr, false);
      lc.setIntensity(addr, INTENSITY);
      lc.clearDisplay(addr);
    }

    random_food();
  }
}
/*==============================================*/

/*============ User Define Function ============*/

  /*  (1.) read_joy_stick() : สำหรับอ่านค่าชิล Joy Stick ทั้งจอยและปุ่มกด
   *  (2.) plot()           : สำหรับ plot เพิ่มจุดลงบน LED Dot Matrix ขนาด 8x32 
   *  (3.) delete_plot()    : สำหรับ plot ลบจุดลงบน LED Dot Matrix ขนาด 8x32
   *  (4.) move_snake()     : สำหรับกำหนดให้งูเก็บค่าตำแหน่งและอัปเดตค่าตำแหน่ง
   *  (5.) random_food()    : สำหรับสุ่มจุดเกิดของอาหารงูลงบน LED Dot Matrix ขนาด 8x32
   *  (6.) show_score()     : สำหรับแสดงผลคะแนนบนจออีกจอหนึ่ง
   *  (7.) beep()           : สำหรับส่งเสียงในขณะเดินและกดปุ่ม
  */ 

/*###### READ_JOY_STICK ######*/

void read_joy_stick() {
  int read_r = 0;
  int read_c = 0;

  read_r = analogRead(PIN_ANALOG_X);
  read_c = analogRead(PIN_ANALOG_Y);

  if (read_r >= 1000 && move_x != 1) {
    move_x = -1;
    move_y = 0;
  } else if (read_r >= 0 && read_r < 100 && read_c < 600 && move_x != -1) {
    move_x = 1;
    move_y = 0;
  } else if (read_c >= 1000 && move_y != 1) {
    move_x = 0;
    move_y = -1;
  } else if (read_c >= 0 && read_c < 100 && move_y != -1) {
    move_x = 0;
    move_y = 1;
  }

  /* เงื่อนไขตรงนี้สำหรับการเคลื่อนที่ของงูตามเวลาโดยปกติงูจะเคลื่อนที่ด้วยความเร็ว 1 dot/250 ms 
    แต่หากเรากดปุ่มตรง Joy งูจะเคลื่อนที่เร็วกว่านั้นประมาณ 1 dot/100 ms */
    
  if (millis() - last_plot >= 250) {
    move_snake();
  } else if (millis() - last_plot >= 100 && !digitalRead(PIN_K)) {
    move_snake();
  }
}

/*######   PLOT   ######*/

void plot(int x, int y) {
  int row = x;
  int col = y % 8;

  if (y < 0) {
    address = 1;
    c = 31;
    col = c % 8;
  } else if (y < 8) {
    address = 4;
  } else if (y < 16) {
    address = 3;
  } else if (y < 24) {
    address = 2;
  } else if (y < 32) {
    address = 1;
  } else {
    address = 4;
    col = c = 0;
  }

  if (x < 0) {
    row = r = 7;
  } else if (x > 7) {
    row = r = 0;
  }
  lc.setLed(address, row, col, true);
}

/*###### DELETE_PLOT   ######*/

void delete_plot(int x, int y) {
  int row = x;
  int col = y % 8;

  if (y < 0) {
    address = 1;
    c = 31;
    col = c % 8;
  } else if (y < 8) {
    address = 4;
  } else if (y < 16) {
    address = 3;
  } else if (y < 24) {
    address = 2;
  } else if (y < 32) {
    address = 1;
  } else {
    address = 4;
    col = c = 0;
  }

  if (x < 0) {
    row = r = 7;
  } else if (x > 7) {
    row = r = 0;
  }
  lc.setLed(address, row, col, false);
}

/*######  MOVE_SNAKE   ######*/

void move_snake() {
  /*การทำงานก็คืองูจะเดินแล้วเก็บค่าตำแหน่งลงใน LinkedList*/
  if (move_x || move_y) {
    beep(523, 20);
    snake_x.add(r);
    snake_y.add(c);
  }

  /*อัปเดตค่า r และ c โดยค่ามาจาก read_joy_stick*/
  r += move_x;
  c += move_y;

  /*ทำการ plot ตำแหน่งถัดไป*/
  plot(r, c);

  /* ทำการตรวจสอบว่าตำแหน่ง r และ c ที่ได้ไปตรงกับจุดใดจุดนึงในตัวงูหรือไม่
      (ถ้าตรง) เกมก็จะหยุดลง (ถ้าไม่ตรง) ก็จะออกจาก for แล้วไปต่อ */
  for (int i = 0; i < snake_x.size(); i++) {
    if (snake_x.get(i) == r && snake_y.get(i) == c) {
      game_status = false;
    }
  }

  /* ทำการตรวจสอบว่าตำหน่ง r และ c ตรงกับตำแหน่งของอาหารหรือไม่
      (ถ้าตรง) งูก็ยาวยาวขึ้นหนึ่งจุด และอาหารจะถูก random ใหม่
      (ถ้าไม่ตรง) ก็จะหลุด if นี้ไป                         */
  if (food_x == r && food_y == c) {
    beep(830, 20);
    snake_length++;
    random_food();
  }

  /* ###  shift() จะลบค่าตัวแรกและจพ return ค่าตัวแรกออกมา */
  /* จะเป็นการลบ Linkedlist โดยงูจะเดินไปเลื่อยๆ โดยตรวจสอบจากความยาวงู
     ถ้าเกินก็จะ Shift ข้อมูลใน Linkedlist ออกไปแล้วค่อยรับตำแหน่งมาใหม
     เพื่อที่เวลางูเดินจะได้เป็นวามยาวเดิมก่อนการกินอาหาร จนกว่าจะกินอาหารความยาวงูถึงจะถูกเพิ่มขึ้น
  */
  if (snake_x.size() == snake_length) {
    delete_plot(snake_x.shift(), snake_y.shift());
  }

  /* เก็บเวลาที่ plot ล่าสุดไว้เพื่อที่ครั้งต่อไปจะได้ห่าง 250 ms*/
  last_plot = millis();
}

/*######   RANDOM_FOOD   ######*/

void random_food() {
  bool onSnake = false;
  randomSeed(analogRead(A2));
  food_x = random(8);
  food_y = random(32);

  /* เป็นการตรวจสอบว่าอาหารที่ถูกสุ่มเกิดมาว่าตรงกับส่วนใดส่วนหนึ่งของงูหรือไม่ */
  for (int i = 0; i < snake_x.size(); i++) {
    if (snake_x.get(i) == food_x && snake_y.get(i) == food_y || (food_x == r && food_y == c)) {
      onSnake = true;
    }
  }
    Serial.println("Generate");

  /* ถ้าไม่ตรงก็ plot อาหารจุดนั้นแต่ถ้าตรงจะทำการสุ่มไหม่ */
  if (!onSnake) {
    plot(food_x, food_y);
  } else { 
    random_food();
    Serial.println("Regenerate");
  }
}

/*######   SHOW_SCORE   ######*/

 /* Score ตรงนี้ก็จะเป็นการ plot เลข 0-99 ที่ล่ะหลัก
    ใน LED Dot Matrix 8x8 ที่แสดงคะแนน */
    
void show_score() {
  int score = snake_length - 1;
  if (score / 10 != 1) {
    lc.setLed(0, 1, 6, true);
  } else {
    lc.setLed(0, 1, 6, false);
  }
  if (score / 10 != 1 && score / 10 != 4) {
    lc.setLed(0, 2, 6, true);
  } else {
    lc.setLed(0, 2, 6, false);
  }
  lc.setLed(0, 3, 6, true);
  if (score / 10 != 1 && score / 10 != 2 && score / 10 != 3 && score / 10 != 7) {
    lc.setLed(0, 1, 5, true);
  } else {
    lc.setLed(0, 1, 5, false);
  }
  if (score / 10 != 5 && score / 10 != 6) {
    lc.setLed(0, 3, 5, true);
  } else {
    lc.setLed(0, 3, 5, false);
  }
  if (score / 10 != 1 && score / 10 != 7) {
    lc.setLed(0, 1, 4, true);
  } else {
    lc.setLed(0, 1, 4, false);
  }
  if (score / 10 != 1 && score / 10 != 7 && score / 10 != 0) {
    lc.setLed(0, 2, 4, true);
  } else {
    lc.setLed(0, 2, 4, false);
  }
  lc.setLed(0, 3, 4, true);
  if (score / 10 == 0 || score / 10 == 2 || score / 10 == 6 || score / 10 == 8) {
    lc.setLed(0, 1, 3, true);
  } else {
    lc.setLed(0, 1, 3, false);
  }
  if (score / 10 != 2) {
    lc.setLed(0, 3, 3, true);
  } else {
    lc.setLed(0, 3, 3, false);
  }
  if (score / 10 != 1 && score / 10 != 4 && score / 10 != 7) {
    lc.setLed(0, 1, 2, true);
    lc.setLed(0, 2, 2, true);
  } else {
    lc.setLed(0, 1, 2, false);
    lc.setLed(0, 2, 2, false);
  }
  lc.setLed(0, 3, 2, true);


  if (score % 10 != 1) {
    lc.setLed(0, 5, 6, true);
  } else {
    lc.setLed(0, 5, 6, false);
  }
  if (score % 10 != 1 && score % 10 != 4) {
    lc.setLed(0, 6, 6, true);
  } else {
    lc.setLed(0, 6, 6, false);
  }
  lc.setLed(0, 7, 6, true);
  if (score % 10 != 1 && score % 10 != 2 && score % 10 != 3 && score % 10 != 7) {
    lc.setLed(0, 5, 5, true);
  } else {
    lc.setLed(0, 5, 5, false);
  }
  if (score % 10 != 5 && score % 10 != 6) {
    lc.setLed(0, 7, 5, true);
  } else {
    lc.setLed(0, 7, 5, false);
  }
  if (score % 10 != 1 && score % 10 != 7) {
    lc.setLed(0, 5, 4, true);
  } else {
    lc.setLed(0, 5, 4, false);
  }
  if (score % 10 != 1 && score % 10 != 7 && score % 10 != 0) {
    lc.setLed(0, 6, 4, true);
  } else {
    lc.setLed(0, 6, 4, false);
  }
  lc.setLed(0, 7, 4, true);
  if (score % 10 == 0 || score % 10 == 2 || score % 10 == 6 || score % 10 == 8) {
    lc.setLed(0, 5, 3, true);
  } else {
    lc.setLed(0, 5, 3, false);
  }
  if (score % 10 != 2) {
    lc.setLed(0, 7, 3, true);
  } else {
    lc.setLed(0, 7, 3, false);
  }
  if (score % 10 != 1 && score % 10 != 4 && score % 10 != 7) {
    lc.setLed(0, 5, 2, true);
    lc.setLed(0, 6, 2, true);
  } else {
    lc.setLed(0, 5, 2, false);
    lc.setLed(0, 6, 2, false);
  }
  lc.setLed(0, 7, 2, true);
}

/*######   BEEP   ######*/

void beep(int note, int duration){
  tone(buzzer, note, duration);
}
