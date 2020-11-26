#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;

/* Initialize */
#define NUM_CYCLE 5
#define NUM_SAMPLE 4

float S[NUM_SAMPLE];

/*DAC speed (Hz)*/
#define defaultFreq 1700

/*freq0 : frequency of carrier sine wave (Hz)*/
#define freq0 400

/*A[0]-A[3] : ASK Amplitude (0,5] (V)*/
const float A[4] = {1, 2, 3, 4};

/*S_DAC : Amplitude (12bit) of sine wave at 0,90,180,270*/
uint16_t S_DAC[4] = {500, 1000, 500, 0};
int delay0;

/* Allocate some space for the string */
char inData[20];

void setup() {
  Serial.begin(115200);

  dac.begin(0x62); // set to default
  delay0 = ((1000000 / freq0)/NUM_SAMPLE - 100);
  // delay for sampling period of sine
  // (Tsine – delayfrom DAC processing speed)
  Serial.flush(); // for clear buffer serial

}

void loop() {
  if (Serial.available() > 0) {
 
    /*use a cycle loop receive inData : message input */
    int i = 0;
    delay(5);
    while (Serial.available()) {
      inData[i] = Serial.read();
      i++;
    }

    /*use a cycle loop i for send data 8 bits*/
    for (int j = 0; j < i-1; j++)
    {
      /* use a cycle loop k for 1 ASK signal element (2 bit)
            - map inData[i] to tmp (2 bit)
            - from LSB to MSB
      */
      for (int k = 7; k >= 0; k -= 2)
      {
        /* &3 00, 01, 10, 11*/
        uint8_t temp = inData[j] & 3;
        /*use a cycle loop sl to send 5 cycle/baud*/
        for (int cycle = 0; cycle < NUM_CYCLE; cycle++)
        {
          Serial.println("=== Data Sented! ===");
          /*use a cycle loop s to send 4 sample/cycle*/
          for (int sample = 0; sample < NUM_SAMPLE; sample++)
          {
            dac.setVoltage(S_DAC[sample] * A[temp], false);
            Serial.print("[");
            Serial.print(sample);
            Serial.print("] ");
            Serial.println(S_DAC[sample] * A[temp]);
            delayMicroseconds(delay0);
          }
        }
        inData[j] = inData[j] >> 2;
      }
    }
    /* for don't send */
    dac.setVoltage(0, false);
  }

}
