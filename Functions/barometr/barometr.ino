#include <Wire.h> 
#include <BMP085.h>
 
BMP085 dps = BMP085();    
 
long Temperature = 0, Pressure = 0;
 
void setup(void) { 
  Serial.begin(9600); 
  Wire.begin(); 
  delay(1000);
  dps.init();  
}          
 
void loop(void) { 
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
 
  Serial.print("Pressure(mm Hg):"); 
  float pressure_mm_hg = Pressure / 133.3;
  float rounded_pressure = round(pressure_mm_hg * 10);
  rounded_pressure /= 10;
  Serial.print(rounded_pressure);      //Выводим давление в мм.рт ст
  Serial.print("Temp:"); 
  Serial.println(Temperature*0.1);   // Температуру в градусах Цельсия
  delay(2000); 
}
