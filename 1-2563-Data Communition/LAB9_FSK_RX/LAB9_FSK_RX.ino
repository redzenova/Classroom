#ifndef cbi
#define cbi(sfr, bit)(_SFR_BYTE(sfr)&=~_BV(bit)) 
#endif
#ifndef sbi
#define sbi(sfr, bit)(_SFR_BYTE(sfr)|=_BV(bit))
#endif

//edit this number
#define r_slope 400

void setup() {
  sbi(ADCSRA, ADPS2); // this for increase analogRead speed
  cbi(ADCSRA,ADPS1);
  cbi(ADCSRA,ADPS0);
  Serial.begin(115200);
  Serial.flush();
}

int prev = 0;
int count = 0;

uint16_t baud_check = 0;
uint16_t data = 0;
uint16_t bit_check = -1;

bool check_amp = false;
bool check_baud = false;

uint32_t baud_begin = 0;

void loop() {
  int tmp = analogRead(A3);
//  if ( tmp > 20 )
//  Serial.println(tmp); //debug slope
  if ( tmp > r_slope and prev < r_slope and !check_amp ) // check amplitude
  {
    check_amp = true; // is first max amplitude in that baud
    if ( !check_baud )
    {
      baud_begin = micros();
      bit_check++;
    }
  }

  if(tmp < r_slope and check_baud) {
    if (micros() - baud_begin > 9900 ) // full baud
    {
      uint16_t last = (((count - 1) / 5) & 3) << (bit_check * 2);;  // shift data
      data |= last;                                                 // add two new bits in data
      baud_check++;
      Serial.println(data);
      if (baud_check == 4) // 8 bits
      {
        Serial.print((char)data);
        data = 0;
        baud_check = 0;
        bit_check = -1;
      }
      check_baud = false;
      count = 0;
    }
  }
  
  if(tmp > r_slope and check_amp) {
    count++;
    check_baud = true;
    check_amp = false;
  }
  prev = tmp;
}
