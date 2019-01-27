#include <LiquidCrystal_I2C.h

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT); 

}

void loop() { 
  // put your main code here, to run repeatedly:
  boolean knopkastate = digitalRead(3);
if (knopkastate == 1)
{ lcd.noBacklight(); 
  set.backlight(knopka.state);
}
}
