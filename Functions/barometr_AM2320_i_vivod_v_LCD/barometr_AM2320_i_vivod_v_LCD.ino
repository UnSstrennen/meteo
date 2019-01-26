

#include <LiquidCrystal_I2C.h>

#include <Wire.h>  
#include <BMP085.h> 
#include <AM2320.h>
AM2320 th;   
BMP085 dps = BMP085();    

#include <OneWire.h>

#include <DallasTemperature.h>
OneWire oneWire(5);
DallasTemperature ds(&oneWire); 
  
long Temperature = 0, Pressure = 0; 
  LiquidCrystal_I2C lcd(0x27,20,4); 
void setup() {
  // put your setup code here, to run once:
    Wire.begin();
  delay(1000); 
  dps.init(); 
  lcd.begin(); 
   lcd.setCursor(0, 0);
   lcd.backlight();
     lcd.begin();                     
  lcd.backlight();// Включаем подсветку дисплея
ds.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  dps.getPressure(&Pressure);  
  dps.getTemperature(&Temperature); 
   lcd.setCursor(0, 2);
  lcd.print("Davleniye:");  
  lcd.print(Pressure/133.3);    //Выводим давление в мм.рт ст 
  delay(2000);
      th.Read();
     lcd.setCursor(13, 1);
     lcd.print("VL:"); 
      lcd.print(int(th.h)); 
      lcd.print("% "); 
      lcd.setCursor(0, 0);
      lcd.print("Tin:");
      lcd.print(th.t); 
      lcd.setCursor(0, 1);
ds.requestTemperatures();
lcd.print("Tout: ");
lcd.print(ds.getTempCByIndex(0));
lcd.println("C");
  delay(200);  
  delay(200);
}
