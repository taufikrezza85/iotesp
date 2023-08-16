void setup(){
  Serial.begin(9600);
  pinMode(22,OUTPUT);
  pinMode(34,INPUT);
}

void loop(){

  float value1 = analogRead(34);

  Serial.print ("Value:");
  Serial.println(value1);
  
  if(value1>512){
    digitalWrite(22,HIGH);
  }
  else{
    digitalWrite(22,LOW);
  }
}
