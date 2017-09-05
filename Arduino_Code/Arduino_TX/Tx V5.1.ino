int pitch;
int lefta;
int righta;
int yaw;
int lesc;
int resc;
int lspeed;
int rspeed;
int speed;
long speedsum;
long avgc;
byte avgspeed;


String data;

void setup() {
Serial.begin(9600);
}


void loop() {
  data = String("");

  //A
  pitch = analogRead(A0);
  if (pitch < 10) {
    data = String("000") ;
  }
    else if (pitch < 100) {
    data = String("00");
    }
      else if (pitch < 1000) {
        data = String("0");
      }
  data = String(data+pitch);

  //B
  lefta = analogRead(A1);
  if (lefta < 10) {
    data = String(data+"000");
  }
    else if (lefta < 100) {
    data = String(data+"00");
    }
      else if (lefta < 1000) {
        data = String(data+"0");
      }
  data = String(data+lefta);

  //C

  //D
  if (digitalRead(2)==HIGH){
    delay(8);
    if (digitalRead(2)==HIGH){
      while (digitalRead(2)==HIGH){
      }
      data = String(data+"0000");
    }
  }
  else if (digitalRead(4)==HIGH){
    delay(8);
    if (digitalRead(4)==HIGH){
      while (digitalRead(4)==HIGH){
      }
      data = String(data+"1023");
    }
  }
  else if (digitalRead(2)==LOW && digitalRead(4)==LOW){
    data = String(data+"511");
  }

  //E
  lesc = analogRead(A6);

//E+
if (lesc < analogRead(A3)){
  lspeed = lesc;
  if (lesc < 10) {
    data = String(data+"000");
  }
    else if (lesc < 100) {
    data = String(data+"00");
    }
      else if (lesc < 1000) {
        data = String(data+"0");
      }
  data = String(data+lesc);
}
else {
  lspeed = analogRead(A3);
  if (analogRead(A3) < 10) {
    data = String(data+"000");
  }
    else if (lesc < 100) {
    data = String(data+"00");
    }
      else if (lesc < 1000) {
        data = String(data+"0");
      }
  data = String(data+analogRead(A3));
}



    //F
    resc = analogRead(A7);

  //F+
if (resc < analogRead(A3)){
  rspeed = resc;
  if (resc < 10) {
    data = String(data+"000");
  }
    else if (resc < 100) {
    data = String(data+"00");
    }
      else if (resc < 1000) {
        data = String(data+"0");
      }
  data = String(data+resc);
}
else{
  rspeed = analogRead(A3);
  if (analogRead(A3) < 10) {
    data = String(data+"000");
  }
    else if (resc < 100) {
    data = String(data+"00");
    }
      else if (resc < 1000) {
        data = String(data+"0");
      }
  data = String(data+analogRead(A3));
}

speedsum = speedsum + ((lspeed + rspeed)/2);
avgc = avgc + 1;
avgspeed = speedsum/avgc;



  Serial.print(data);
  //Serial.print (avgspeed);

  delay (50);

}
