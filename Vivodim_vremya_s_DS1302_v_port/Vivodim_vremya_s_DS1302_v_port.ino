
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1302,6,7,8);
void setup() {
    delay(300);
    Serial.begin(9600);
    time.begin();
}
void loop(){
    if(millis()%1000==0){ // если прошла 1 секунда
      Serial.println(time.gettime("d-m-Y, H:i:s, D")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
    }
}
