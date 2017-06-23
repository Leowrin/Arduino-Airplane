#include <SoftwareSerial.h>
SoftwareSerial comserial(2,3);

void setup() {
Serial.begin(9600);
Serial.setTimeout(30);

comserial.begin(9600);
comserial.setTimeout(30);
}

void loop() {
if (comserial.available()>1){
  String entry = comserial.readString();
  String entryA = entry.substring(0,2);
  String entryB = entry.substring(2,4);
  if (entryA=="A:"){
    
  }
  }
}
