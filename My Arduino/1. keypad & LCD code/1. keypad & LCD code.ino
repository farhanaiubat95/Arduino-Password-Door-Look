
#include <LiquidCrystal.h>
LiquidCrystal lcd (8,9,10,11,12,13);
#include <Keypad.h>
const byte ROWS=4;
const byte COLS=4;
char keys [ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  byte rowpins[ROWS]={0,1,2,3};
  byte colPins[COLS]={4,5,6,7};
  keypad kpd=Keypad(makeKeymap(keys),rowPins.colPins,ROWS,COLS);
void setup() {
  for(int k=8;k<14;k++)
  {pinMode(k,OUTPUT);
  }
  lcd.begin(16,2);
  lcd.print("Enter Password--");
}

void loop() {
  char key=kpd.getKey();
  if(key!= NO_KEY)
  {
    lcd.print("Wrong Password..");
    lcd.print("Try again--");
  }

}
