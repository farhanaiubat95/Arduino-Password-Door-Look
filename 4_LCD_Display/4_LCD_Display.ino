#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

void setup() {
 lcd.begin(16, 2);

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hey Everyone");
  lcd.setCursor(0,1);
  lcd.print("IUBAT 2025");

}
