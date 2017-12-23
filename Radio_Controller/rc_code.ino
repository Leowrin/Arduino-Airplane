#define bps 2400

boolean comstate;
int pitch;
int lefta;
int righta;
int yaw;
int lesc;
int resc;
int besc;
long timeA;
long timeB;


String entry;
String data;


void setup() {
  Serial.begin(bps);
  Serial.setTimeout(8);
  delay(2000);
}


void loop() {
data="";
entry="";
timeA=0;
timeB=0;

//pitch, A
pitch = analogRead(A0);
if (pitch < 10) {
  data = String(data+"000"+pitch);
} else if (pitch < 100) {
  data = String(data+"00"+pitch);
} else if (pitch < 1000) {
  data = String(data+"0"+pitch);
} else {
  data = String(data+pitch);
}

//leftaileron, B
lefta = analogRead(A1);
if (lefta < 10) {
  data = String(data+"000"+lefta);
} else if (lefta < 100) {
  data = String(data+"00"+lefta);
} else if (lefta < 1000) {
  data = String(data+"0"+lefta);
} else {
  data = String(data+lefta);
}

//yaw
if (digitalRead(4)==HIGH){
  delay(1);
  if (digitalRead(4)==HIGH){
    data = String(data+"0000");
}} else if (digitalRead(2)==HIGH){
  delay(1);
  if (digitalRead(2)==HIGH){
    data = String(data+"1023");
  }} else {
  data=String(data+"0512");
}

//Both ESCs
besc = analogRead(A3);
//left ESC
lesc = analogRead(A6);
if (besc < lesc){
  lesc = besc;
}
if (lesc < 10) {
  data = String(data+"000"+lesc);
} else if (lesc < 100) {
  data = String(data+"00"+lesc);
} else if (lesc < 1000) {
  data = String(data+"0"+lesc);
} else {
  data = String(data+lesc);
}

//right ESC
resc = analogRead(A7);
if (besc < resc){
  resc = besc;
}
if (resc < 10) {
  data = String(data+"000"+resc);
} else if (resc < 100) {
  data = String(data+"00"+resc);
} else if (resc < 1000) {
  data = String(data+"0"+resc);
} else {
  data = String(data+resc);
}




Serial.print(data);


//delay(200); //replaced with next lines
timeA = millis();
while(Serial.available()<=1){
  timeB = millis();
  if ((timeB-timeA)>150){
    break;
  }
}if (Serial.available()>1){
  entry = Serial.readString();
  comstate=true;
  //data process, soon batterie voltage display
  timeA = millis();
  timeB = 0;
  while((timeB-timeA)<100){
    timeB = millis();
  }
}else{
  comstate=false;
  //data process, soon alarm ?
  timeA = millis();
  timeB = 0;
  while((timeB-timeA)<50){
    timeB = millis();
  }
}

}
