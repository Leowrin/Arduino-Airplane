//HC-12 Toggle button Send
//Autor Tom Heylen tomtomheylen.com


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int buttonPin = 8;

void setup() {
  pinMode(buttonPin, INPUT);
  mySerial.begin(9600);
}

void loop() {
 
  int buttonState = digitalRead(buttonPin);
  
  if(buttonState == 1){//if button is down
    mySerial.println(1234);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
}

