#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
bool online = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT); 
  lcd.init();
  lcd.backlight();
  lcd.display();
}

void loop() { 
  // put your main code here, to run repeatedly:
  boolean knopkastate = digitalRead(3);
if (knopkastate == 1)
{
 online = !online;
 lcd.setBacklight(online);
 delay(3);
}
}
