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

  bool enteredSenderID = false;
  bool enteredReciverID = false;
  String Sender_ID ;
  String Reciver_ID;

  SoftwareSerial DataLink(RX_PIN, TX_PIN);

  /* Frame design */
  const uint8_t maximumFrame  = 20 ;     //Maximum Frame per 1 round to sent : more Frame more Memory!!
  uint8_t frameSize           = 16 ;
  uint8_t frame_number        = 0 ;
  
  struct Frame { 
    int seq         = 0 ;
    int seqAll      = 0 ;
    String flag         = ":" ;
    String src_address  = " " ;
    String dst_address  = " " ;
    String data         = " " ;

    String getFrame(){
      return src_address + flag + dst_address + flag + String(seq) + flag + String(seqAll) + flag + data + flag;
    }
  };

  struct Frame frame[maximumFrame];

  
  /* Data */
  String payload = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+12ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+1234567890-=";
  

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
              for (int j = 0; j < frameSize ; j++){
                tmp += data[j+i];
              }
            frame[frame_number].data = tmp;
            frame[frame_number].src_address = src;
            frame[frame_number].dst_address = dst;
            frame[frame_number].seq = count;
            frame[frame_number].seqAll = len+1;
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
        frame[frame_number].seqAll = len+1;
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

  //Set Sender ID
  Serial.println("Enter Your ID : ");
  while (!enteredSenderID) {
    if (Serial.available()) {
      SENDER_ID = Serial.readStringUntil('\n');
      Serial.println("--> My Id : " + SENDER_ID);
      enteredSenderID = true;
    }
  }

  //Set Reciever ID
  Serial.println("Enter Reciver ID : ");
  while (!enteredReciverID) {
    if (Serial.available()) {
      RECIVER_ID = Serial.readStringUntil('\n');
      Serial.println("--> Reciver Id : " + RECIVER_ID);
      if(RECIVER_ID != SENDER_ID){
        enteredReciverID = true;
      } else {
        Serial.println("ID is invalid! please enter again : ");
      }
      
    }
  }
  Serial.println("============================");
}

/*======================| @LOOP Function |======================*/

bool canSend = true;
long timer = 0;
uint8_t askFrame = 0 ;

String ch ;

void loop() {

   if (canSend) {
    MakeFrame(payload, SENDER_ID, RECIVER_ID);
    
    String data = frame[askFrame].getFrame();
    
    for (int i = 0; i < data.length(); i++) {
      DataLink.write(data[i]);
    }
    canSend = false;
   }

   if (DataLink.available() > 0){
    ch = DataLink.readStringUntil('\n');

    Serial.println("Asl request : " + ch);
   
   }
}
