#include <Servo.h>
#include <LiquidCrystal.h> //include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initialize the interface pins

Servo myservo; 

float val = 0;
int analogPin = A0;


void setup()
{
  lcd.begin(16, 2); //set up the LCD's number of columns and rows
  myservo.attach(9);
}

void loop()
{
  val = analogRead(analogPin);
  val = val*5/1023;
  Serial.println(val);
  
  lcd.setCursor(0,0);
  lcd.print("Voltaje: ");
  lcd.print(val);
  
  lcd.setCursor(0,1);
  
  float angle = map(val, 0, 5, 0, 180);
  lcd.print("Grados: ");
  lcd.print(angle);
  
  myservo.write(angle);
  
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}