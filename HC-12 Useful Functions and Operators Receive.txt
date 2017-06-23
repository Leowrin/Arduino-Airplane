//HC-12 Useful Functions and Operators Receive
//Autor Tom Heylen tomtomheylen.com

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  
  if(mySerial.available() > 1){
    
    String input = mySerial.readString();//read string
    Serial.println(input);
    
    String first4 = input.substring(0,4);//first 4 characters
    Serial.println(first4);
    
    String last = input.substring(4);//all characters after the 4th character
    Serial.println(last);
    
    int integer = last.toInt();//Convert to integer
    Serial.println(integer);
  }
  delay(20);
}
/*
//here are more operators and functions

    Serial.parseInt()// read serial input and convert to integer
    Serial.parseFloat()// read serial input and convert to float
    Serial.read() - '0'; // deduct ascii value of '0' to find numeric value of 
    
    isAlphaNumeric()// it's alphanumeric
    isAlpha()// it's alphabetic
    isAscii()// it's ASCII
    isWhitespace()// it's whitespace
    isControl()// it's a control character
    isDigit()// it's a numeric digit
    isGraph()// it's a printable character that's not whitespace
    isLowerCase()// it's lower case
    isPrintable()// it's printable
    isPunct()// it's punctuation
    isSpace()// it's a space character
    isUpperCase()// it's upper case
    isHexadecimalDigit()// it's a valid hexadecimaldigit (i.e. 0 - 9, a - F, or A - F) 

*/
