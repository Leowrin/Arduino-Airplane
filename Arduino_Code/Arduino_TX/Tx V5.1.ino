int pitch;
int lefta;
int righta;
int yaw;
int lesc;
int resc;

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
  yaw = analogRead(A3);
  if (yaw < 10) {
    data = String(data+"000");
  }
    else if (yaw < 100) {
    data = String(data+"00");
    }
      else if (yaw < 1000) {
        data = String(data+"0");
      }
  data = String(data+yaw);

  //E
  lesc = analogRead(A6);
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

  //F
  resc = analogRead(A7);
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

  Serial.print(data);

  delay (50);

}
