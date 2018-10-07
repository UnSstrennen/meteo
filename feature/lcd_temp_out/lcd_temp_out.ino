#include <LiquidCrystal_I2C.h>

#include <Wire.h>



#include <OneWire.h>

#include <DallasTemperature.h>
OneWire oneWire(5);
DallasTemperature ds(&oneWire);
LiquidCrystal_I2C lcd(0x3F,16,2);  // Устанавливаем дисплей

void setup() {
   lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Temperature:");
 

Serial.begin(9600);
ds.begin();
}
void loop() {
   // Устанавливаем курсор на вторую строку и нулевой символ.
lcd.setCursor(0, 1);
  // Выводим на экран количество секунд с момента запуска ардуины
  lcd.print(ds.getTempCByIndex(0));

ds.requestTemperatures();
Serial.print("Sensor 0: ");
Serial.print(ds.getTempCByIndex(0));
Serial.println("C");
}
