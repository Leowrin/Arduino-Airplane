int pitch;
int lefta;
int righta;
int yaw;
int rightm;
int leftm;

String data;

void setup() {
Serial.begin(9600);
}


void loop() {
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
  rightm = analogRead(A6);
  if (rightm < 10) {
    data = String(data+"000");
  }
    else if (rightm < 100) {
    data = String(data+"00");
    }
      else if (rightm < 1000) {
        data = String(data+"0");
      }

  data = String(data+rightm );

  //F
  leftm = analogRead(A7);
  if (leftm < 10) {
    data = String(data+"000");
  }
    else if (leftm < 100) {
    data = String(data+"00");
    }
      else if (leftm < 1000) {
        data = String(data+"0");
      }

  data = String(data+leftm);

  Serial.print(data);

  delay (50);

}
