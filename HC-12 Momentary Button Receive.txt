//HC-12 Momentary Button Receive
//Autor Tom Heylen tomtomheylen.com


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int ledPin = 13;

void setup() {
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
   
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    if(input == 1111){//if on code is received
      digitalWrite(ledPin, HIGH);//turn LED on
    }
    if(input == 0000){//if off code is received
      digitalWrite(ledPin, LOW);//turn LED off
    }
  }
  mySerial.flush();//clear the serial buffer for unwanted inputs     
  
  delay(20);//delay little for better serial communication
 
}
