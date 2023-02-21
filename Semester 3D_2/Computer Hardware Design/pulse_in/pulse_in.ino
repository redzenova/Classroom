
int pin = 2;
unsigned long duration;
   

void setup()
{ 
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(pin, INPUT);
}

void loop()
{
    duration = pulseIn(pin, LOW, 45000);
    float time=duration/1000.00;
    Serial.print("DelT=");
    Serial.print(time);
    Serial.println(" ms");
}
