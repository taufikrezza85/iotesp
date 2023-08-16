//change pin LDR for light sensor
//library: MakerKit, Adafruit_NeoPixel
//taufik

#include <MakerKit.h>

#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xcc0000);
    pixels.setPixelColor(1, 0xcc0000);
    pixels.setPixelColor(2, 0xcc0000);
    pixels.setPixelColor(3, 0xcc0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  } else {
    pixels.setPixelColor(0, 0x000000);
    pixels.setPixelColor(1, 0x000000);
    pixels.setPixelColor(2, 0x000000);
    pixels.setPixelColor(3, 0x000000);
    pixels.setPixelColor(4, 0x000000);
    pixels.show();
    pixels.show();

  }
}

#define BLYNK_TEMPLATE_ID           "TMPL6TisPkja6"
#define BLYNK_DEVICE_NAME           "demo140823"
#define BLYNK_AUTH_TOKEN            "Hr-hTiTKME5xAZbiwEn2aZeeH_DrFGPc"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "HUAWEI-B315-7C2A";
char pass[] = "18DMA9MTRQL";


int value1;
int value2;
int value3;
//declare buzer pin
const int buzer=2;


BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3333ff);
    pixels.setPixelColor(1, 0x3333ff);
    pixels.setPixelColor(2, 0x3333ff);
    pixels.setPixelColor(3, 0x3333ff);
    pixels.setPixelColor(4, 0x3333ff);
    pixels.show();
    pixels.show();

  } else {
    pixels.setPixelColor(0, 0x000000);
    pixels.setPixelColor(1, 0x000000);
    pixels.setPixelColor(2, 0x000000);
    pixels.setPixelColor(3, 0x000000);
    pixels.setPixelColor(4, 0x000000);
    pixels.show();
    pixels.show();

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
	
  int ultra = ultrasonic(12,27);
  int light1 = analogRead(36);
  //CODING ADD BY MOHAMAD NOH
  int analogpin34 = analogRead(34);
	
  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V21, analogRead(36));
  
  //added display value ultrasonic & light sensor
  Serial.print("ultrasonic:");
  Serial.print(ultra);
  Serial.print("light:");
  Serial.println(light);
  
  //added light pixels ===============
	pixels.setPixelColor(0, 0xffffff);
    pixels.setPixelColor(1, 0xffffff);
    pixels.setPixelColor(2, 0xffffff);
    pixels.setPixelColor(3, 0xffffff);
    pixels.setPixelColor(4, 0xffffff);
    pixels.show();
    pixels.show();
 //====================================== 
 
 digitalWrite(buzer,HIGH); // active buzer
}


void setup() {
  pixels.begin();

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //CODING BY MOHAMAD NOH
  pinMode(34, INPUT);
  pinMode(36, INPUT);
  pinMode(buzer,OUTPUT); //set pinMode for buzer
  Timer1.setInterval(300, Timer1_TimerEvent);

}

void loop() {
  Blynk.run();
  Timer1.run();
}