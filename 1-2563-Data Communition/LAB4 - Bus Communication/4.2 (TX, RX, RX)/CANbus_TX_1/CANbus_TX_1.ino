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
  #define Monitor_Buadrate        9600
  #define Communication_Buadrate  57600
    
  String SENDER_ID = " ";
  String RECIVER_ID = " ";

  SoftwareSerial DataLink(RX_PIN, TX_PIN);

  /* Frame design */
  const uint8_t maximumFrame  = 20 ;     //Maximum Frame per 1 round to sent : more Frame more Memory!!
  uint8_t frameSize           = 8 ;
  uint8_t frame_number        = 0 ;
  
  struct Frame { 
    uint8_t seq         = 0 ;
    String flag         = "@$" ;
    String src_address  = " " ;
    String dst_address  = " " ;
    String data         = " " ;

    String getFrame(){
      return flag + src_address + dst_address + seq  + data + flag ;
    }
  };

  struct Frame frame[maximumFrame];

  
  /* Data */
  String payload = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+1234567890-=";
  

/*======================| Define Function |======================*/

void flushData(){
  while(DataLink.available())
    uint8_t tmp = DataLink.read();
}

void MakeFrame(String data, String src, String dst){
  frame_number = 0;
  int len = 0;
  int count = 0;
  int nowIndex = 0;

  len = data.length()/frameSize;

  String tmp = "";
  
 for (int i = 0; i < data.length(); i++){
  //Serial.print(i);
      if(count != len){
          if (i%frameSize == 0){
              for (int j = 0; j < 8 ; j++){
                tmp += data[j+i];
              }
            frame[frame_number].data = tmp;
            frame[frame_number].src_address = src;
            frame[frame_number].dst_address = dst;
            frame[frame_number].seq = count;
            frame_number += 1;
          //Serial.println(tmp);
          tmp = "";
          count++;
          }
      }

      else{
        nowIndex = i+frameSize-1;
        while(data[nowIndex] != '\0'){
          tmp += data[nowIndex];
          nowIndex++;
        }
        frame[frame_number].data = tmp;
        frame[frame_number].src_address = src;
        frame[frame_number].dst_address = dst;
        frame[frame_number].seq = count;
        //Serial.println(tmp);
        count++;
        frame_number = count;
        break;
      }
 }

}

/*======================| @SETUP Function |======================*/

void setup() {
  Serial.begin(Monitor_Buadrate);
  DataLink.begin(Communication_Buadrate);

  while(SENDER_ID == " "){
    Serial.println("Enter ID : ");
    if(Serial.available()){
        SENDER_ID = Serial.readStringUntil('\n');
        Serial.println("My ID is : " + SENDER_ID);
    }
    delay(1000);
  }

  while(RECIVER_ID == " "){
    Serial.println("Reciver ID : ");
    if(Serial.available()){
        RECIVER_ID = Serial.readStringUntil('\n');
        Serial.println("Reciver is : " + RECIVER_ID);
    }
    delay(1000);
  }

  MakeFrame(payload, SENDER_ID, RECIVER_ID);

  for (int i=0; i < frame_number; i++){
    Serial.println(frame[i].getFrame());
  }

}

/*======================| @LOOP Function |======================*/
int8_t  SN = 0;
boolean canSend = true;

void loop() {


//  if(DataLink.available()){   //WaitForEvent();
//    
//  }
//  
//
//
//  
//  String Data = frame.getFrame();
//  for (int i=0; Data[i] != '\0' ; i++){
//    DataLink.write(Data[i]);
//    delay(10);
//    flushData();
//  }
//  delay(500);
//  DataLink.write('\n');

}
