//SoftwareSerial version. usefull debug.

//MAY NOT WORK PROPERLY DUE TO CONFLICT BETWEEN <Servo.h> AND <SoftwareSerial.h> LIBRARY!!!!


#include <Servo.h>
#define bps 2400
#include <SoftwareSerial.h>
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


String data;
String entryA;


SoftwareSerial mySerial(2, 3); //RX, TX
void setup() {
//Serial
Serial.begin(bps);
Serial.setTimeout(40);
mySerial.begin(bps);
mySerial.setTimeout(40);

//servo.attach
SPitch.attach(3);
SRightA.attach(9);
SLeftA.attach(10);
SYaw.attach(11);
SLESC.attach(5);
SRESC.attach(6);


}

void loop() {

if(mySerial.available() > 1){
   data = mySerial.readString();

   entryA = data.substring(0,4);
   Pitch = entryA.toInt();

   entryA = data.substring(4,8);
   LeftA = entryA.toInt();

   entryA = data.substring(8,12);
   Yaw = entryA.toInt();

   entryA = data.substring(12,16);
   LESC = entryA.toInt();

   entryA = data.substring(16,20);
   RESC = entryA.toInt();




   Pitch=map(Pitch,0,1023,0,180);
   LeftA=map(LeftA,0,1023,0,180);
   RightA=map(LeftA,0,1023,0,180);
   Yaw=map(Yaw,0,1023,0,180);
   LESC=map(LESC,0,1023,40,180);
   RESC=map(RESC,0,1023,40,180);

   SPitch.write(Pitch);

   SLeftA.write(LeftA);

   SRightA.write(RightA);

   SYaw.write(Yaw);

   SLESC.write(RESC);

   SRESC.write(LESC);

 }






}
