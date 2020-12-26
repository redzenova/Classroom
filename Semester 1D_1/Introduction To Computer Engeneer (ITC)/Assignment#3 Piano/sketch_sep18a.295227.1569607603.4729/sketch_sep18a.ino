#include <StackArray.h>
#include <LinkedList.h>

const int pin_toggle = 9;
const int pin_key[8] = {7,8,10,12,6,4,2,3};
const int melody[8] = {262,294,330,349,392,440,493,523};
const int pin_led[2] = {13,11};
const int pin_buzzer = 5;
const bool pressed = false;

bool record = false;

long index_note;
long index_duration;
long count_duration;

StackArray <int> key;
LinkedList <int> note;
LinkedList <int> duration;

void setup() {
  Serial.begin(115200);

  for(int i = 0;i < 8;i++){
    pinMode(pin_key[i], INPUT_PULLUP);
  }
  pinMode(pin_toggle, INPUT_PULLUP);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_led[0], OUTPUT);
  pinMode(pin_led[1], OUTPUT);

  digitalWrite(pin_led[0], LOW);
  digitalWrite(pin_led[1], HIGH);
}

void loop() {
  toggle();
  piano();
  play_record();
}

int piano() {
  int Count = 0;
  int Note = 0;

  for(int i = 0;i < 8;i++) {
    if(digitalRead(pin_key[i]) == pressed){
      key.push(i);
    }
  }

  Count = key.count();

  while(!key.isEmpty ()) {
    Note += melody[key.pop()];
  }
  
  Note /= Count;

  if(record && Count) {
    if(note.size() == 0) {
      note.add(Note);
      duration.add(millis());
    }

    if(note.size() > 0 && note.get(note.size() - 1) != Note) {
      duration.set(duration.size() - 1, millis() - duration.get(duration.size() - 1));
      duration.add(millis());
      note.add(Note);
    }
      Serial.println(duration.get(0));

    tone(pin_buzzer ,Note ,200);
  }else if(note.size() > 0 && note.get(note.size() - 1) != 0) {
    duration.set(duration.size() - 1, millis() - duration.get(duration.size() - 1));
    duration.add(millis());
    note.add(0);
  }
}

void toggle(){
  if(digitalRead(pin_toggle) == pressed) {
    delay(150);

    record = !record;

    digitalWrite(pin_led[0], record);
    digitalWrite(pin_led[1], !record);

    if(record) {
      note.clear();
      duration.clear();
    }else {
      duration.set(duration.size() - 1, millis() - duration.get(duration.size() - 1));
      index_note = 0;
      index_duration = 0;
      count_duration = 0;
    }
  }
}

void play_record() {
  long last_song;

  if(!record) {
    if(count_duration <= duration.get(index_duration)) {
      Serial.println(duration.get(0));
      tone(pin_buzzer ,note.get(index_note) ,200);
      count_duration++;
    }else{
      index_duration++;
      index_note++;
      if(note.get(index_note) == 0) {
        count_duration = 0;
      }else {
        count_duration = -500;
      }
    }
    
    if(index_duration < duration.size()) {
      last_song = millis();
    }

    if(millis() - last_song > 3000) {
      count_duration = 0;
      index_duration = 0;
      index_note = 0;
    }
  }
}
