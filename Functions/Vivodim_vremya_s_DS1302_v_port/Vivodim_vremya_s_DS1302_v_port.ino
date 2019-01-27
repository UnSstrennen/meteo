#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1302,6,7,8);
void setup() {
    delay(300);
    Serial.begin(9600);
    time.begin();
}
void loop(){
      Serial.println(time.gettime("d-m-Y,H:i,D")); // выводим время
}
