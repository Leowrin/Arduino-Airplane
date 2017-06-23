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

Serial.print("\t");
//B
int lefta = map(analogRead(A1),0,1023,0,99);
LeftA = String("B:");
LeftA = String(LeftA+lefta);
Serial.print(LeftA);

Serial.print("\t");
//C
int righta = map(analogRead(A2),0,1023,0,99);
RightA = String("C:");
RightA = String(RightA+righta);
Serial.print(RightA);

Serial.print("\t");
//D
int yaw = map(analogRead(A3),0,1023,0,99);
Yaw = String("D:");
Yaw = String(Yaw+yaw);
Serial.print(Yaw);

Serial.print("\t");
//E
int rightm = map(analogRead(A6),0,1023,0,99);
RightM = String("E:");
RightM = String(RightM+rightm);
Serial.print(RightM);

Serial.print("\t");
//F
int leftm = map(analogRead(A7),0,1023,0,99);
LeftM = String("F:");
LeftM = String(LeftM+leftm);
Serial.print(LeftM);



//sc=String(sv);
//comserial.print(sc);
Serial.println();
}
