#include <LiquidCrystal.h> //include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initialize the interface pins
  
void setup() {
  lcd.begin(16, 2); //set up the LCD's number of columns and rows
  lcd.setCursor(16,0);
  lcd.print("Inaki");
  lcd.setCursor(16,1);
  lcd.print("Cabo Alonso");
}

int cursor = 16;

void loop() {
  if (cursor > 0) {
	cursor = cursor - 1;
    lcd.scrollDisplayLeft();
  }
  
  delay(300);
}