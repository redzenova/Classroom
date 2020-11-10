#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;
int delay0;

#define defaultFreq 1700  //dac speed
#define freq0       500  // sine wave frequency

const int len = 8; //8 16 32
float     zeta[len]; 
float     S[len];     
uint16_t  S_DAC[len];


void setup() {
  Serial.print("Start ... ");
  Serial.begin(115200);
  dac.begin(0x62); //default: A
  //dac.begin(0x64); //A2
  //dac.begin(0x60); //A0
  Wire.setClock(3400000);
  
  
  delay0 = (((1000000/freq0 - 1000000/defaultFreq) /len) - 90) ;  //delay for period of sine
  Serial.print("Delay0 is ");
  Serial.println(delay0);
  
  for(int i =0; i < len ; i++){
    zeta[i] = 360 / len * i;
  }

  for(int i = 0; i < len; i++){
    float radian = zeta[i]*PI/180;
    S[i] = sin(radian);
    S_DAC[i] = (uint16_t)map(S[i]*1000,-1000,1000,0,4095);
    Serial.print(i);
    Serial.print(": ");
    Serial.print(S[i]);
    Serial.print(" ");
    Serial.println(S_DAC[i]);
  }
  
}

void loop() {
  for(int i=0; i<len; i++){
    dac.setVoltage(S_DAC[i], false, 400000);
    delayMicroseconds(delay0);
  }
}
