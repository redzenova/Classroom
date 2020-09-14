/*==================| LAB4 - Bus Communication |==================
  Subject: 01076007 Data Communication
  Student: Nattapon Sukthaworn
           Raweeroj Thongdee
  Date Create: 10/09/2020 
 ================================================================*/

/*======================| Library Require |======================*/
    #include <SoftwareSerial.h>


/*====================| Control and Setting |====================*/
  #define TX_PIN                  11
  #define RX_PIN                  10
  #define Monitor_Buadrate        115200
  #define Communication_Buadrate  57600
    
  SoftwareSerial DataLink(RX_PIN, TX_PIN);
  


/*======================| Define Function |======================*/

void flushData(){
  while(DataLink.available())
    uint8_t tmp = DataLink.read();
}


/*======================| @SETUP Function |======================*/

void setup() {
  Serial.begin(Monitor_Buadrate);
  DataLink.begin(Communication_Buadrate);

}

/*======================| @LOOP Function |======================*/

void loop() {
  char Data[] = "Computer Engineering";
  for (int i=0; Data[i] != '\0' ; i++){
    DataLink.write(Data[i]);
    delay(10);
    flushData();
  }
  delay(500);
  DataLink.write('\n');

}
