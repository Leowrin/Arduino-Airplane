#include <SoftwareSerial.h>
SoftwareSerial comserial(2,3);

String Pitch;
String LeftA;
String RightA;
String Yaw;
String RightM;
String LeftM;



void setup() {
Serial.begin(9600);


comserial.begin(9600);
}

void loop() {
//A
int pitch = map(analogRead(A0),0,1023,0,99);
Pitch = String("A:");
Pitch = String(Pitch+pitch);
Serial.print(Pitch);

//B
int lefta = map(analogRead(A1),0,1023,0,99);
LeftA = String("B:");
LeftA = String(LeftA+lefta);
Serial.print(LeftA);

//C
int yaw = map(analogRead(A3),0,1023,0,99);
Yaw = String("D:");
Yaw = String(Yaw+yaw);
Serial.print(Yaw);

//D
int rightm = map(analogRead(A6),0,1023,0,99);
RightM = String("E:");
RightM = String(RightM+rightm);
Serial.print(RightM);

//E
int leftm = map(analogRead(A7),0,1023,0,99);
LeftM = String("F:");
LeftM = String(LeftM+leftm);
Serial.print(LeftM);

}
