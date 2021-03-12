//Acelerómetro
/*
 * 0º -> x = 340 y = 341 z = 408
 * 90 -> x = 281 y = 345 z = 357
 * 180º -> x = 350 y = 345 z = 288
 * 270º -> x = 419 y = 341 z = 355
 */

//LCD
#include <LiquidCrystal.h> //include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initialize the interface pins

int PIN_X = A3;
int PIN_Y = A4;
int PIN_Z = A5;

float x = 0;
float y = 0;
float z = 0;

float xA = 0;
float yA = 0;
float zA = 0;


float zero = 1024/2; //Vs/2
float sensitivity = 330; //300mV/g
float escala = (sensitivity*(1024/3.3))/1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_Z, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(PIN_X);
  y = analogRead(PIN_Y);
  z = analogRead(PIN_Z);

  xA = map(x, 265, 402, -90, 90);
  yA = map(y, 265, 402, -90, 90);
  zA = map(z, 265, 402, -90, 90);

  xA = RAD_TO_DEG * (atan2(-yA, -zA) + PI);
  yA = RAD_TO_DEG * (atan2(-xA, -zA) + PI);
  zA = RAD_TO_DEG * (atan2(-yA, -xA) + PI);
  
  x = (x - zero)/escala;
  y = (y - zero)/escala;
  z = (z - zero)/escala;
  
  Serial.print("Angulo: ");
  Serial.print(" X: ");
  Serial.print(xA);
  Serial.print(" Y: ");
  Serial.print(yA);
  Serial.print(" Z: ");
  Serial.println(zA);
  Serial.print("Aceleración: ");
  Serial.print(" X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.println(z);

  lcd.setCursor(0,0);
  lcd.print("X:");
  lcd.print(xA);
  lcd.print("Y:");
  lcd.print(yA);

  delay(1000);
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}