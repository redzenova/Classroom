#define a0min 0
#define a0max 1000
#define a1min 0
#define a1max 2000
#define a2min 0
#define a2max 3000
#define a3min 0
#define a3max 4000

#define r_slope 500

int sum = 0;
int Max = 0;
int prev = 0;
int check = false;
int output = -1;
int count = 0;

void setup() {
  Serial.begin(115200);
  Serial.flush();
}

uint8_t last = 0;
uint8_t last2 = 0;
uint8_t bitC = 0;
void loop() {
  int tmp = analogRead(A0); // read signal from analog pin
  if (tmp - prev > r_slope && check == false) {
    Max = 0;
    check = true;  // change check status is true
  }
  if (tmp > Max) { // update max value
    Max = tmp;
  }
  if (Max - tmp > r_slope) { // check for falling signal
    if (check == true) {
      if (a0min < Max && Max <= a0max) {
        Serial.println("00");
        last = 0;
        count++;
      }
      else if (a1min < Max && Max <= a1max) {
        Serial.println("01");
        last = 1;
        count++;
      }
      else if (a2min < Max && Max <= a2max) {
        Serial.println("10");
        last = 2;
        count++;
      }
      else if (a3min < Max && Max <= a3max) {
        Serial.println("11");
        last = 3;
        count++;
      }

      if (count == 5) {
        last2 |= last << (bitC * 2);
        bitC++;
        if (bitC == 4) {
          Serial.print((char)last2);
          last2 = 0;
          bitC = 0;
        }
        count = 0;
      }

    }
    check = false;  // change check status is false
  }
  prev = tmp;  // assign temp value to previous=
}
