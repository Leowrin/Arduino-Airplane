//HC-12 Useful Functions and Operators Send
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
    mySerial.println("test123");//send a string on button press
  }
  delay(200);//delay little for better serial communication
}

