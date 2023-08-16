void setup(){
  Serial.begin(9600);
  pinMode(22,OUTPUT);
  pinMode(34,INPUT);
}

void loop(){

  float value1 = analogRead(34);

  Serial.print ("Value:");
  Serial.println(value1);
  
  
}
