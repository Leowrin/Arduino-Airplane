boolean comstate;
int pitch;
int lefta;
int righta;
int yaw;
int lesc;
int resc;
long timeA;
long timeB;
long timeC;
float lescm;
float rescm;


String entry;
String data;


void setup() {

  Serial.begin(2400);     //2400 [baud/sec] pour une meilleure portée
  Serial.setTimeout(8);
  delay(2000);          //attente du condo

}


void loop() {
//Assiniation des variables, remises à 0.
data="";
entry="";
timeA=0;
timeB=0;
timeC=0;

//pitch, A
//Faire Monter / Déscendre
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

//moteurs
lescm = analogRead(A6)/1023;  //A6 pot gauche
rescm = analogRead(A7)/1023;  //A7 pot droite

lesc = lescm*analogRead(A3);
resc = rescm*analogRead(A3);

if (lesc < 10) {
  data = String(data+"000"+lesc);
} else if (lesc < 100) {
  data = String(data+"00"+lesc);
} else if (lesc < 1000) {
  data = String(data+"0"+lesc);
} else {
  data = String(data+lesc);
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
delay(100);

/*




//delay(200); //replaced with next lines
timeA = millis();
while(Serial.available()<=1){
  timeB = millis();
  timeC = timeB-timeA;
  if (timeC>150){
    break;
  }timeC=0;
}if (Serial.available()>1){
  entry = Serial.readString();
  comstate=true;
  //data process, soon batterie voltage display
  timeA = millis();
  timeB = 0;
  while(timeC<100){
    timeB = millis();
    timeC = timeB-timeA;
  }
}else{
  comstate=false;
  //data process, soon alarm ?
  timeA = millis();
  timeB = 0;
  while(timeC<100){
    timeB = millis();
    timeC = timeB-timeA;
  }
}
switch (comstate) {
  case 1:
  digitalWrite(7,HIGH);
  break;
  case 0:
  digitalWrite(7,LOW);
  break;
}*/
}
