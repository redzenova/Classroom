/*====================================================
            Digital Clock with DotMatrix LED
  ===================================================== */


/*===================  Include Lib ====================*/
#include "LedControl.h"
#include "FontLEDClock.h"

/*=================  Define Varible ===================*/
const uint8_t btn[4] = {4, 5, 6, 7};
const uint8_t buzzer = 3;

int8_t MENU = 0;
int8_t SUB_MENU = 1;
int8_t SET_SUB_MENU = 1;
int8_t DATE_SUB_MENU = 1;
int8_t COUNT_MENU = 1;
int8_t ALARM_MENU = 1;
uint8_t swap = 0;

/*=================  Varible Light ===================*/
int8_t brightness = 8;
int8_t x = 2;
int8_t level[5] = {0, 128, 256, 512, 1023};
uint8_t intensity = 8;

/*=============  Define Varible Time =================*/
int8_t  hour  = 20,
        minute = 45,
        second = 0,
        second_set = 0;

int8_t  c_hour  = 1,
        c_minute = 0,
        c_second_set = 0;

int8_t  a_hour  = 13,
        a_minute = 52,
        a_second_set = 0;

uint8_t  S_minute = 0,
         S_sec = 0;

int8_t  day = 29,
        mon = 10;
int     year = 2562;

unsigned long  S_msec        = 0;
unsigned long  millis_msec   = 0;
unsigned long  c_millis_msec = 0;

/*=================  Define State ===================*/
bool save  = true ;
bool StopStart = false ;
bool CountStart = false ;
bool AlarmStart = false ;

bool Lock_menu_btn = false ;
bool Lock_sub_menu_btn = false ;

bool set_time = false;
bool no_beep = false;
bool no_alarm = true;
bool alarmtik = false;

/*=================  Define Screen ===================*/
bool st_state[20] = {0};
uint8_t conf_state = 1;
const char menu_screen[][10]     = {" ", "SET", "STOP", "COUNT", "ALARM", "EXIT"};
const char menu_set_screen[][10] = {" ", "SET_Time", "SET_Date", "SET_Led", "SET_Buzz", "SET_EXIT"};
const char menu_set_time_screen[][20] = {" ", "SET_Time_HR", "SET_Time_MN", "SET_Time_SEC", "SET_Time_EXIT"};
const char menu_set_date_screen[][20] = {" ", "SET_Date_DAY", "SET_Date_MON", "SET_Date_YEAR", "SET_Date_EXIT"};

unsigned long delaytime = 50;
long c_time = 0;

LedControl lc = LedControl(11, 13, 10, 4);

/*=================  Setup Funcetion ===================*/
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(btn[i], INPUT_PULLUP);
  }
  pinMode(buzzer, OUTPUT);

  /*================= Clock Count ===================*/
  noInterrupts();           /* disable all interrupts             */
  TCCR1A  = 0;
  TCCR1B  = 0;
  TCNT1   = 3036;           /* preload timer 65536-16MHz/256/1Hz  */
  TCCR1B |= (1 << CS12);    /* 256 prescaler                      */
  TIMSK1 |= (1 << TOIE1);   /* enable timer overflow interrupt    */
  interrupts();

  int devices = lc.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    lc.shutdown(address, false);
    lc.setIntensity(address, 8);
    lc.clearDisplay(address);
  }
  clocks();
}

ISR(TIMER1_OVF_vect) {
  TCNT1 = 3036;
  second = 0;
  second++;
  if (save == true) {
    second_set += second;
    if (second_set > 59) {
      second_set = 0; minute++;
    }
    if (minute > 59) {
      minute = 0; hour++;
    }
    if (hour > 23) {
      hour = 0;
    }
  }
}

void loop() {
  set_led(brightness);
  if (Lock_menu_btn != true) {
    if (digitalRead(btn[3]) == LOW) {
      beep();
      delay(120);
      clear_display();
      if (MENU == 6) MENU = 0;
      if (MENU > 4) MENU = 0;
      MENU++;
    }
    st_state[1] = false;
  }

  if (MENU == 1) {
    SET_Menu();
  }

  if (MENU == 2) {
    STOP_Menu();
  }

  if (MENU == 3) {
    COUNT_Menu();
  }

  if (MENU == 4) {
    ALARM_Menu();
  }

  if (ALARM_MENU == 5) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      clear_display();
      ALARM_MENU = 1;
      MENU = 4;
      st_state[8] = false;
      Lock_menu_btn = false;
    }

  }
}
}

if (MENU == 5) {
  if (digitalRead(btn[1]) == LOW) {
    beep();
    delay(120);
    clear_display();
    MENU = 6;
  }
}

if (MENU == 6) {
  clocks();
  if (no_alarm == false) {
    for (int i = 8 ; i < 23 ; i++) {
      plot(i, 7, 1);
    }
    if (second_set == a_second_set && minute == a_minute && hour == a_hour) {
      alarmtik = true;
      c_time = millis();
      Serial.println("Alarm!!!!!");
    }
  }
  if (no_alarm == true) {
    for (int i = 8 ; i < 23 ; i++) {
      plot(i, 7, 0);
    }
  }
}


/*=================  Screen Display  ===================*/

if (MENU == 1 && st_state[1] == true) {
  screen(menu_set_screen[SUB_MENU]);
}
if (MENU == 1 && st_state[2] == true) {
  screen(menu_set_time_screen[SET_SUB_MENU]);
}
if (MENU == 1 && st_state[6] == true) {
  screen(menu_set_date_screen[DATE_SUB_MENU]);
}
if (MENU == 1 && SUB_MENU == 3 && st_state[3] == true) {
  screen("SET_LED_VAL");
}
if (MENU == 1 && st_state[4] == true) {
  if (no_beep == true) {
    screen("SET_BUZZER_NO");
  }
  if (no_beep == false) {
    screen("SET_BUZZER_YES");
  }
}
if (MENU == 4 && st_state[8] == true && ALARM_MENU == 4) {
  if (no_alarm == true) {
    screen("ALARM_SET_OFF");
  }
  if (no_alarm == false) {
    screen("ALARM_SET_ON");
  }
}
if (MENU == 4 && st_state[8] == true && ALARM_MENU == 5) {
  screen("ALARM_EXIT");
}
if (MENU == 2 && st_state[5] == true) {
  screen("STOPWACTCH");
}
if (MENU == 3 && st_state[7] == true && COUNT_MENU != 4 && COUNT_MENU != 5) {
  countdown();
}
if (MENU == 3 && st_state[7] == true && COUNT_MENU != 4 && COUNT_MENU == 5) {
  screen("COUNT_EXIT");
}
if (MENU == 3 && st_state[7] == true && COUNT_MENU == 4 && CountStart != true) {
  screen("COUNT_START");
}
if (MENU == 3 && st_state[7] == true && COUNT_MENU == 4 && CountStart == true) {
  countdown();
}
if (MENU != 6 && st_state[1] != true && st_state[2] != true && st_state[3] != true
    && st_state[4] != true && st_state[5] != true && st_state[6] != true && st_state[7] != true
    && st_state[8] != true) {
  screen(menu_screen[MENU]);
}

count();

if (alarmtik == true) {
  alarm();
  if (digitalRead(btn[0]) == LOW || digitalRead(btn[1]) == LOW
      || digitalRead(btn[2]) == LOW || digitalRead(btn[3]) == LOW) {
    alarmtik = false;
    no_alarm = true;
  }
  for (int i = 8 ; i < 23 ; i++) {
    plot(i, 7, 0);
  }
}

}


void plot (uint8_t x, uint8_t y, uint8_t value) {
  uint8_t address;
  if (x >= 0 && x <= 7)   {
    address = 3;
  }
  if (x >= 8 && x <= 15)  {
    address = 2;
    x = x - 8;
  }
  if (x >= 16 && x <= 23) {
    address = 1;
    x = x - 16;
  }
  if (x >= 24 && x <= 31) {
    address = 0;
    x = x - 24;
  }

  if (value == 1) {
    lc.setLed(address, y, x, true);
  } else {
    lc.setLed(address, y, x, false);
  }
}


void clear_display() {
  for (uint8_t address = 0; address < 4; address++) {
    lc.clearDisplay(address);
  }
}

void print_tiny_char(uint8_t x, uint8_t y, char c)
{
  uint8_t dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') )  c &= 0x1F;              /* A-Z maps to 1-26  */
  else if (c >= '0' && c <= '9')                        c  = (c - '0') + 32;
  else if (c == ' ' )                                   c  =  0;                /* space             */
  else if (c == '.' )                                   c  = 27;                /* full stop         */
  else if (c == ':' )                                   c  = 28;                /* colon             */
  else if (c == '\'')                                   c  = 29;                /* single quote mark */
  else if (c == '!' )                                   c  = 30;                /* single quote mark */
  else if (c == '?' )                                   c  = 31;                /* question mark     */

  for (uint8_t col = 0; col < 3; col++)
  {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (uint8_t row = 0; row < 5; row++)
    {
      if (dots & (16 >> row))     plot(x + col, y + row, 1);
      else                      plot(x + col, y + row, 0);
    }
  }
}

void clocks()
{
  print_tiny_char( 2, 1,  hour / 10 + '0'); //print hour
  print_tiny_char( 6, 1,  hour % 10 + '0');
  print_tiny_char(12, 1, minute / 10 + '0'); //print minute
  print_tiny_char(16, 1, minute % 10 + '0');
  print_tiny_char(22, 1, second_set / 10 + '0'); //print second
  print_tiny_char(26, 1, second_set % 10 + '0');

  // blink : for each minute
  if (second_set % 2 != 0)
  {
    plot(10, 2, 0);
    plot(10, 4, 0);
    plot(20, 2, 0);
    plot(20, 4, 0);
  }
  else
  {
    plot(10, 2, 1);
    plot(10, 4, 1);
    plot(20, 2, 1);
    plot(20, 4, 1);
  }
}

void countdown()
{

  print_tiny_char( 2, 1, c_hour / 10 + '0'); //print hour
  print_tiny_char( 6, 1, c_hour % 10 + '0');
  print_tiny_char(12, 1, c_minute / 10 + '0'); //print minute
  print_tiny_char(16, 1, c_minute % 10 + '0');
  print_tiny_char(22, 1, c_second_set / 10 + '0'); //print second
  print_tiny_char(26, 1, c_second_set % 10 + '0');

  // blink : for each minute
  if (c_second_set % 2 != 0)
  {
    plot(10, 2, 0);
    plot(10, 4, 0);
    plot(20, 2, 0);
    plot(20, 4, 0);
  }
  else
  {
    plot(10, 2, 1);
    plot(10, 4, 1);
    plot(20, 2, 1);
    plot(20, 4, 1);
  }
}

void count() {
  if (CountStart != false) {
    if (millis() - c_millis_msec > 1000) {
      c_millis_msec = millis();
      c_second_set--;

      if (c_second_set < 0) {
        c_second_set = 59;
        c_minute--;
      }

      if (c_minute < 0) {
        c_minute = 59;
        c_hour--;
      }

      if (c_second_set == 0 && c_minute == 0 && c_hour == 0) {
        c_second_set = swap;
        clear_display();
        CountStart = false;
      }
    }
  }
}

void set_led(int x) {
  int devices = lc.getDeviceCount();
  for (int address = 0; address < devices; address++) {
    lc.setIntensity(address, x);
  }
}

void beep() {
  if (no_beep != true) {
    tone(buzzer, 625, 20);
  }
}

void alarm() {
  if (millis - c_time > 500) {
    c_time = millis();
    tone(buzzer, 625, 20);
  }
  if (millis - c_time > 200) {
    c_time = millis();
    tone(buzzer, 2100, 20);
  }
  if (millis - c_time > 100) {
    c_time = millis();
    tone(buzzer, 4100, 20);
  }
  c_time = millis();
}
