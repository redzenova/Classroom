/*============================================
    [Final Project]- Autonomous Robot car
             by Raweeroj & Nithi
     Introduction to Computer Engineering
              Date: 25/11/62
      [STATE-1/2]: Start -> Check Point
  ============================================*/
/*================= Define ==================
     L2  L1 CC R1  R2
    [0] [1][2][3] [4]
     |___|__|__|___|
    _/              \_
   |6| In1      In3 |8|
   |7| In2      In4 |9|
   |_|  5       10  |_|
     \_____________/

  LED[2]  [3][4][11]  [12]
  ============================================*/
/*Left Wheel*/
#define enA 5
#define in1 6
#define in2 7

/*Right Wheel*/
#define enB 10
#define in3 8
#define in4 9

/*Right Wheel*/
#define L2_LED 2
#define L1_LED 3
#define CC_LED 4
#define R1_LED 11
#define R2_LED 12

/*============================================*/

/*============== Config-Value ================*/
int Mid_L2 = 834;
int Mid_L1 = 305;
int Mid_CC = 309;
int Mid_R1 = 325;
int Mid_R2 = 334;

int B[5], W[5];

/*====== Speed Control =====*/
float init_motor_speed = 200;

/*====== Drive Control =====*/
float Left_motor = 0;
float Right_motor = 0;
/*============================================*/

/*================= State ====================*/
bool L2 = false;
bool L1 = false;
bool CC = false;
bool R1 = false;
bool R2 = false;
/*============================================*/

bool isForward = false;
bool isRight = false;
bool isLeft = false;
int state = 0;

void setup()
{
  Serial.begin(9600);

  /*======= Initialize Pin ========*/
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(L2_LED, OUTPUT);
  pinMode(L1_LED, OUTPUT);
  pinMode(CC_LED, OUTPUT);
  pinMode(R1_LED, OUTPUT);
  pinMode(R2_LED, OUTPUT);
  
  //กำหนดความเร็วมอเตอร์ และ ตั้งตัวนับเวลาใหม่
  double state_delay = millis();

  // State 1 --> ทางโค้งเป็นมุมไปจนถึง 4 แยก (ซ้ายสำคัญ)
  while (1)
  {
    ROS();

    if (millis() - state_delay > 14000)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;
    }
    else if (L2)
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);

      isLeft = true;
      isRight = false;
    }
    else if (R2 || isRight)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);

      isRight = true;
    }
    else if (L1)
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);

      isRight = false;
    }
    else if (R1)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);
      
      isRight = false;
    }
    else if (CC)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, init_motor_speed);
      
      isRight = false;
    }
    else
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);
    }
  }

  //กำหนดความเร็วมอเตอร์ และ ตั้งตัวนับเวลาใหม่
  init_motor_speed = 200;
  state_delay = millis();

  // State 2 --> จาก 4 แยกผ่านโค้งครึ่งวงกลมไปทางตรงครึ่งนึง (ขวาสำคัญ)
  while (1)
  {
    ROS();

    if (millis() - state_delay > 12000)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;
    }
    else if (R2)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);

      isRight = true;
    }
    else if (L2)
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);

      isLeft = true;
    }
    else if (L1)
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);
    }
    else if (R1)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);
    }
    else if (CC)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, init_motor_speed);
      
      if (isRight)
      {
        isLeft = false;
        isRight = false;
        //break;
      }
    }
    else
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);
    }
  }

  //กำหนดความเร็วมอเตอร์ และ ตั้งตัวนับเวลาใหม่
  init_motor_speed = 100;
  state_delay = millis();

  // State 3 --> จากกึ่งกลางเส้นตรงไปวนรอบสี่เหลี่ยมและหยุดที่ Check Point (รู้จักแค่ขวา)
  while (1)
  {
    ROS();
    
    if (R2)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, 255);

      isRight = true;
    }
    else if (R1)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      analogWrite(enA, 255);
      analogWrite(enB, init_motor_speed);
    }
    else if (CC)
    {
      /* Left Wheel */
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, init_motor_speed);
    }
    else
    {
      /* Left Wheel */
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      /* Right Wheel */
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      analogWrite(enA, init_motor_speed);
      analogWrite(enB, 255);
    }
  }
}

void loop()
{
  SetColor();  //ฟังก์ชั่น รับ-ปรับค่ากลางของ sensor เพื่อแยกขาว - ดำ
}

/*
  Setcolor() เป็นฟังก์ชันที่ให้ผู้ใช้งานเชื่อมต่อตัวหุ่นยนต์กับโปรแกรม Arduino IDE 
  แล้วสั่งผ่าน Serial เพื่อควบคุมการทำงานของ sensor ทั้ง 5 ตัวโดย
  สั่ง B -> เก็บค่าแสงที่อ่านได้ของสีดำไปเก็บในตัวแปร B[x]
  สั่ง W -> เก็บค่าแสงสีขาวที่อ่านได้ไปเก็บไว้ในตัวแปร W[x]
  สั่ง C -> คำนวนหาค่าตรงกลางเพื่อแยกขาวดำโดย (W[x] + B[x]) / 2 + 10
*/

void SetColor()
{
  if (Serial.available() > 0)
  {
    int command = Serial.read();

    if (command == 'B')
    {
      B[0] = analogRead(A4);
      B[1] = analogRead(A3);
      B[2] = analogRead(A2);
      B[3] = analogRead(A1);
      B[4] = analogRead(A0);

      Serial.print(analogRead(A4));
      Serial.print(" ");
      Serial.print(analogRead(A3));
      Serial.print(" ");
      Serial.print(analogRead(A2));
      Serial.print(" ");
      Serial.print(analogRead(A1));
      Serial.print(" ");
      Serial.println(analogRead(A0));

      Serial.println("Set Black.");
    }
    else if (command == 'W')
    {
      W[0] = analogRead(A4);
      W[1] = analogRead(A3);
      W[2] = analogRead(A2);
      W[3] = analogRead(A1);
      W[4] = analogRead(A0);

      Serial.print(analogRead(A4));
      Serial.print(" ");
      Serial.print(analogRead(A3));
      Serial.print(" ");
      Serial.print(analogRead(A2));
      Serial.print(" ");
      Serial.print(analogRead(A1));
      Serial.print(" ");
      Serial.println(analogRead(A0));

      Serial.println("Set White.");
    }
    else if (command == 'C')
    {
      Mid_L2 = (W[0] + B[0]) / 2 + 10;
      Mid_L1 = (W[1] + B[1]) / 2 + 10;
      Mid_CC = (W[2] + B[2]) / 2 + 10;
      Mid_R1 = (W[3] + B[3]) / 2 + 10;
      Mid_R2 = (W[4] + B[4]) / 2 + 10;

      Serial.println(Mid_L2);
      Serial.println(Mid_L1);
      Serial.println(Mid_CC);
      Serial.println(Mid_R1);
      Serial.println(Mid_R2);
      Serial.println("Change Middle.");
    }
  }
}

/*
  ROS() เป็นฟังก์ชันที่จะแสดงผลหลอด LED เมื่อ sensor เจอสีดำ
*/
void ROS()
{
  if (analogRead(A4) > Mid_L2)
  {
    digitalWrite(L2_LED, HIGH);
    L2 = true;
  }
  else
  {
    digitalWrite(L2_LED, LOW);
    L2 = false;
  }

  if (analogRead(A3) > Mid_L1)
  {
    digitalWrite(L1_LED, HIGH);
    L1 = true;
  }
  else
  {
    digitalWrite(L1_LED, LOW);
    L1 = false;
  }

  if (analogRead(A2) > Mid_CC)
  {
    digitalWrite(CC_LED, HIGH);
    CC = true;
  }
  else
  {
    digitalWrite(CC_LED, LOW);
    CC = false;
  }

  if (analogRead(A1) > Mid_R1)
  {
    digitalWrite(R1_LED, HIGH);
    R1 = true;
  }
  else
  {
    digitalWrite(R1_LED, LOW);
    R1 = false;
  }

  if (analogRead(A0) > Mid_R2)
  {
    digitalWrite(R2_LED, HIGH);
    R2 = true;
  }
  else
  {
    digitalWrite(R2_LED, LOW);
    R2 = false;
  }
}
