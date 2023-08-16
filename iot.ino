#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

//declare buzer pin
const int buzer=2;

void setup() {
  pixels.begin();

  Serial.begin(9600);
  
  //CODING BY MOHAMAD NOH
  pinMode(34, INPUT);
  pinMode(36, INPUT);
	
  pinMode(buzer,OUTPUT); //set pinMode for buzer
	
 

}

void loop() {
   int ultra = ultrasonic(12,27);
  int light1 = analogRead(36);
	
  //CODING ADD BY MOHAMAD NOH
  int analogpin34 = analogRead(34);
	
  digitalWrite(buzer,HIGH); // active buzer
  
  //added display value ultrasonic & light sensor
  Serial.print("ultrasonic:");
  Serial.print(ultra);
  Serial.print("light:");
  Serial.println(light);
}
