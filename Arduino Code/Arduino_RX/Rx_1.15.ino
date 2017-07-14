#include <Servo.h>


//Déclaration des servos.
Servo SPitch;
Servo SRightA;
Servo SLeftA;
Servo SYaw;
Servo SRESC;
Servo SLESC;

//Variables
String entry;
String entryA;
String entryB;

byte Pitch;
byte RightA;
byte LeftA;
byte Yaw;
byte RESC;
byte LESC;


void setup() {
//Serial
Serial.begin(9600);
Serial.setTimeout(30);

//servo.attach
SPitch.attach(3);
SRightA.attach(9);
SLeftA.attach(10);
SYaw.attach(11);
SRESC.attach(5);
SLESC.attach(6);
}


void loop() {
if (Serial.available()>1){
  entry = comserial.readString();
  entryA = entry.substring(0,2);
  entryB = entry.substring(2,4);
  entryB = entryB.toInt();
}

switch(entryA){

    case == "A:":
        Pitch=entryB;
    break;

    case == "B:":
        RightA=entryB;
    break;

    case == "C:":
        LeftA=entryB;
    break;

    case == "D:":
        Yaw=entryB;
    break;

    case == "E:":
        RESC=entryB;
    break;

    case == "F:":
        LESC=entryB;
    break;
}



Pitch=map(Pitch,0,99,x,x);
RESC=map(RESC,0,99,16,130);
LESC=map(LESC,0,99,16,130);

}
