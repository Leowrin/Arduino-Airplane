#include <Servo.h>
#define bps 2400
//bite

//Déclaration des servos juteux.
Servo SPitch;
Servo SRightA;
Servo SLeftA;
Servo SYaw;
Servo SLESC;
Servo SRESC;

//Variables
boolean comstate;
int Pitch;
int RightA;
int LeftA;
int Yaw;
int LESC;
int RESC;
long timeA;
long timeB;
long timeC;
long timeD;

String entry;
String entryA;
String data;


void setup() {
//Serial
Serial.begin(bps);
Serial.setTimeout(45);

//servo.attach
SPitch.attach(3);
SRightA.attach(9);
SLeftA.attach(10);
SYaw.attach(11);
SLESC.attach(5);
SRESC.attach(6);
}


void loop() {
//var reset
entry="05120512051200000000";
timeA = 0;
timeB = 0;


timeA = millis();
while(Serial.available()<=1){
  timeB = millis();
  timeC = timeB-timeA;
  if (timeC>120){
    break;
  }timeC = 0;
  //reduction de code, enlever le if
}if (Serial.available()>1){
   entry = Serial.readString();

   entryA = entry.substring(0,4);
   Pitch = entryA.toInt();

   entryA = entry.substring(4,8);
   LeftA = entryA.toInt();

   entryA = entry.substring(8,12);
   Yaw = entryA.toInt();

   entryA = entry.substring(12,16);
   LESC = entryA.toInt();

   entryA = entry.substring(16,20);
   RESC = entryA.toInt();
 }
Pitch=map(Pitch,0,1023,0,0);
LeftA=map(LeftA,0,1023,0,0);
RightA=map(LeftA,0,1023,0,0);
Yaw=map(Yaw,0,1023,0,0);
LESC=map(LESC,0,1023,0,0);
RESC=map(RESC,0,1023,0,0);

SPitch.write(Pitch);

SLeftA.write(LeftA);

SRightA.write(RightA);

SYaw.write(Yaw);

SLESC.write(RESC);

SRESC.write(LESC);


//future data process, battery voltage check aso..
data = "123";


timeB = 0;
timeA = millis();
while(timeC < 90){
  timeB = millis();
  timeC = timeB-timeA;
}
Serial.print(data);


}
