#include <SoftwareSerial.h>         //*
#include <Servo.h>
SoftwareSerial comserial(2,3);      //*

//Déclaration des servos.
Servo SPitch;
Servo SRightA;
Servo SLeftA;
Servo SYaw;
Servo SRESC;
Servo SLESC;

//variables
String entry;
String entryA;
String entryB;

byte Pitch;
byte RightA;
byte LeftA;
byte Yaw;
byte RESC;
byte LESC;

//
void setup() {
Serial.begin(9600);
Serial.setTimeout(30);

comserial.begin(9600);      //*
comserial.setTimeout(30);   //*

//servo.attach
SPitch.attach(3);
SRightA.attach(9);
SLeftA.attach(10);
SYaw.attach(11);
SRESC.attach(5);
SLESC.attach(6);

}

void loop() {
if (comserial.available()>1){
  entry = comserial.readString();
  entryA = entry.substring(0,2);
  entryB = entry.substring(2,4);
}
  if (entryA=="A:"){
    Pitch=entryB;
  }
  else if (entryA=="B:") {
    RightA=entryB;
  }
/*else if (entryA=="C:") {
    RollC=entryB;
  }*/
  else if (entryA=="D:") {
    Yaw=entryB;
  }
  else if (entryA=="E:") {
    RESC=entryB;
  }
  else if (entryA=="F:") {
    LESC=entryB;
  }

Pitch=map(Pitch,0,99,x,x);

RESC=map(RESC,0,99,16,130);
LESC=map(LESC,0,99,16,130);
}
//* to delete.
