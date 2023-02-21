// Constants
const int coinpin = 2;
const int ledpin = 13;

// Variables
volatile int pulse = 0;

boolean bInserted = false;

// Coin counter
int count = 0;

int coin1  = 0;
int coin2  = 0;
int coin5  = 0;
int coin10 = 0;



// Setup
void setup() {
 
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, FALLING);
  pinMode(ledpin, OUTPUT);
 
}

// Main loop
void loop() {
 
  if( bInserted  ){
     bInserted = false;
     digitalWrite(ledpin, HIGH);  
     delay(1000);
  }else{
   
  // Turn off LED
  digitalWrite(ledpin, LOW);
  
  } 

//  Serial.print("C1: ");
//  Serial.print(coin1);
//  Serial.print(" C2: ");
//  Serial.print(coin2);
//  Serial.print(" C5: ");
//  Serial.print(coin5);
//  Serial.print(" C10: ");
//  Serial.println(coin10);
//  delay(500);
}

// Interrupt
void coinInterrupt(){
  pulse++ ;
  bInserted = true;
  
 Serial.print( "ME TUNG " );
 Serial.print( pulse );
 Serial.println( " BAHT" );
}
