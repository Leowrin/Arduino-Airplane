//HC-12 Momentary Button Send
//Autor Tom Heylen tomtomheylen.com


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int buttonPin = 8;
boolean onOff = 0;
void setup() {
  pinMode(buttonPin, INPUT);
  mySerial.begin(9600);
}

void loop() {
 
  int buttonState = digitalRead(buttonPin);//read button state
  
  if(buttonState == 1){//if button is down
    mySerial.println(1111);//send unique code to the receiver to turn on. In this case 1111
    onOff = 1;//set boolean to 1
  }
  if(buttonState == 0 && onOff == 1){//Verifier to send off signal once
    mySerial.println(0000);//send unique code to the receiver to turn off. In this case 0000
  }
  delay(20);//delay little for better serial communication
}
