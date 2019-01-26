#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <BMP085.h>
BMP085 dps = BMP085();
long Temperature = 0, Pressure = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
 void setup(void) {
  Wire.begin();
  delay(1000);
  dps.init();
  lcd.init();
  lcd.backlight();
}
void loop(void) {
  dps.getPressure(&Pressure);
  float pressure_mm_hg = Pressure / 133.3;
  lcd.setCursor(0, 3);
  lcd.print("Davleniye: ");
  lcd.print(pressure_mm_hg);    //Выводим давление в мм.рт ст
  delay(2000);
}
