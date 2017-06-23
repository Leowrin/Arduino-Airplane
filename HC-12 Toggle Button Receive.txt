//HC-12 Toggle button Receive
//Autor Tom Heylen tomtomheylen.com


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int ledPin = 13;
unsigned long last = millis();//set timer

void setup() {
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  boolean ledState = digitalRead(ledPin);//check if the LED is turned on or off. Returns 1 or 0
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    

    if(millis() - last > 250){//if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 1234){//if LED is off and button code is ok
          digitalWrite(ledPin, HIGH);
      }else if(ledState == 1 && input == 1234){//if LED is on and button code is ok
          digitalWrite(ledPin, LOW);
      }
      
    }
    
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
  delay(20);//delay little for better serial communication
 
}
