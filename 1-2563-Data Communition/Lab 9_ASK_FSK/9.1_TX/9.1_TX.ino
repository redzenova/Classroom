#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;

/* Setting */
#define NUM_CYCLE 5
#define NUM_SAMPLE 4

/* DAC speed (Hz) */
#define defaultFreq 1700

/* frequency of carrier sine wave (Hz)*/
#define freq0 1000

/* A[0]-A[3] : ASK Amplitude [0,5] (v) */ float A[4] = {0, 1.5, 2, 3};

/* S_DAC : Amplitude(12bit) of sine wave at 0,90,180,270 */
uint16_t S_DAC[NUM_SAMPLE] = {0, 90, 180, 270};

/* Sample */
float S[NUM_SAMPLE];

int delay0;
char inData[40];

void setup() {
  Serial.begin(115200);
  Serial.flush();

  dac.begin(0x62);

  /* delay for sampling period of sine
     Tsine - delayform DAC procesing speed
  */
  delay0 = (1000000/freq0 - 1000000/defaultFreq)/4;
  
  for (int i = 0; i < NUM_SAMPLE; i++)
  {
    S[i] = sin(DEG_TO_RAD * 360.0 / NUM_SAMPLE * i);
    S_DAC[i] = S[i] * 4096.5 + 4096.5;
    Serial.print(S[i]);
    Serial.print(" ");
    Serial.print(S_DAC[i]);
    Serial.println();
  }
}

void loop() {
  if(Serial.available() > 0){

    /* [Loop] receieve inData : message input */
    int i = 0;
    delay(5);
    while (Serial.available()){
      inData[i] = Serial.read();
      i++;
    }

    /* [Loop]  for send data 8 bits */
    for (int j = 0; j < i; j++){
      for (int k = 7; k >= 0; k -= 2){
        /* 00 , 01, 10, 11 */
        uint8_t tmp = inData[j] & B0011;
        /* [Loop] to send 5 cycle/baud */
        for (int cycle = 0; cycle < NUM_CYCLE; cycle++){
          /* [Loop] to send 4 sample/buad */
          for (int sample = 0; sample < NUM_SAMPLE; sample++){
            dac.setVoltage((((int16_t)S_DAC[sample] - 4096) * A[tmp]) + 4096, false);
            /* Sampling delay */
            delayMicroseconds(delay0);
          }
        }
        inData[j] = inData[j] >> 2;
      }
    }
    /* for don't send data */
    dac.setVoltage(0 , false);
    
  }

}
