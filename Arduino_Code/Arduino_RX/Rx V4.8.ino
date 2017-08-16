#include <Servo.h>
//bite

//Déclaration des servos.
Servo SPitch;
Servo SRightA;
Servo SLeftA;
Servo SYaw;
Servo SLESC;
Servo SRESC;

//Variables
String entry;
String entryA;

int Pitch;
int RightA;
int LeftA;
int Yaw;
int LESC;
int RESC;


void setup() {
//Serial
Serial.begin(9600);
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
if (Serial.available()>1){
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


}
