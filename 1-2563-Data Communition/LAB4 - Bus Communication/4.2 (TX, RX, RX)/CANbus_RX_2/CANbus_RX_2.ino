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
  String SENDER_ID = "B";
  String RECIVER_ID;
  
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

    String getData(){
      return data;
    }

    int numFlag(){
      int con =0 ;
      for (int i = 0 ; i< data.length() ; i++){
        if (data[i] == '0'){
          con++;
        }
      }
      return con;
    }

    char getValue(int index){
      return data[index];
    }
    
  };

  struct Frame frame[maximumFrame];
  struct Frame askframe[maximumFrame];

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

String src ;
String des ;
String seq ;
String seqAll ;

String ch ;

bool canSend = true;

void loop() {
  if (DataLink.available() > 0){
    ch = DataLink.readStringUntil('\n');
    
    for (int i = 0 ; i < ch.length(); i++){
      if (i == 0) src = ch[i];
      if (i == 3) des = ch[i];
      if (i == 6) seq = ch[i];
      if (i == 8) seqAll = ch[i];
    }
    
    Serial.print(ch);  
    Serial.println("XXX");
    Serial.println("src : " + src);
    Serial.println("des : " + des);
    Serial.println("seq : " + seq);
    Serial.println("seqall : " + seqAll);

    if(des == SENDER_ID){
      // Accept Frame 
      if(seq == String(frame_number)){
        frame[frame_number].data = ch;
        Serial.println(frame[frame_number].data);
        frame_number +=1;
        Serial.print("--> Now. Sent Ask : " + String(frame_number));
        //DataLink.write(String(frame_number));  
      }
    }
  }
  
}
