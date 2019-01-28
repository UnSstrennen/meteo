#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <iarduino_RTC.h>
#include <AM2320.h>
#include <BMP085.h>
iarduino_RTC time(RTC_DS1302, 6, 7, 8);
AM2320 th;
BMP085 dps = BMP085();
long Temperature = 0, Pressure = 0;
bool online = 1;
LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup(void) {
  Wire.begin();
  pinMode(3, INPUT); 
  dps.init();
  lcd.init();
  lcd.backlight();
  lcd.display();
  time.begin();
}
void loop(void) {
  boolean knopkastate = digitalRead(3);
  if (knopkastate == 1)
  {
  online = !online;
  lcd.setBacklight(online);
  delay(10);
  }
  dps.getPressure(&Pressure);
  float pressure_mm_hg = Pressure / 133.3;
  float rounded_pressure = round(pressure_mm_hg * 10);
  rounded_pressure /= 10;
  lcd.setCursor(0, 2);
  lcd.print("Davleniye:   ");
  lcd.print(rounded_pressure);    //Выводим давление в мм.рт ст
  th.Read();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(th.t);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Vlazhnost:   ");
  lcd.print(th.h);
  lcd.print("%");
  lcd.setCursor(0, 3);
  lcd.print(time.gettime("d-m-Y,H:i,D")); // выводим время
}
