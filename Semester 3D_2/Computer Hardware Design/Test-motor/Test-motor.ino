 // Defin pins
 
int driverPUL1 = 7;    // PUL- pin
int driverDIR1 = 6;    // DIR- pin

int driverPUL2 = 8;    // PUL- pin
int driverDIR2 = 9;    // DIR- pin
 
// Variables
 
int pd1 = 10;       // Pulse Delay period
boolean setdir1 = HIGH; // Set Direction

int pd2 = 10 ;       // Pulse Delay period
boolean setdir2 = HIGH; // Set Direction
 
void setup() {
 
  pinMode (driverPUL1, OUTPUT);
  pinMode (driverDIR1, OUTPUT);

  pinMode (driverPUL2, OUTPUT);
  pinMode (driverDIR2, OUTPUT);
}
 
void loop() {
    digitalWrite(driverDIR1,setdir1);
    digitalWrite(driverPUL1,HIGH);
    delayMicroseconds(pd1);
    digitalWrite(driverPUL1,LOW);
    delayMicroseconds(pd1);
    
    digitalWrite(driverDIR2,setdir2);
    digitalWrite(driverPUL2,HIGH);
    delayMicroseconds(pd2);
    digitalWrite(driverPUL2,LOW);
    delayMicroseconds(pd2);
 
}
