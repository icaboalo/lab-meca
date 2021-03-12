//LCD
#include <LiquidCrystal.h> //include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initialize the interface pins

float sensor = 0.0;
float temp = 0.0;
float volt = 0.0;

int PIN = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(PIN); //10 mV/ºC

  temp = ((sensor*50.0)/(1023.0));
  volt = (sensor*5)/1023.0;
  Serial.print("Sensor: ");
  Serial.print(sensor);
  Serial.print("  Voltaje: ");
  Serial.print(volt);
  Serial.print("  Temperatura: ");
  Serial.println(temp);
  
  lcd.setCursor(0,0);
  lcd.print("temp: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("volt: ");
  lcd.print(volt);

  delay(1000);
}