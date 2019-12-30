#include <DS1302.h>
DS1302 rtc(4, 3, 2);
 
void setup()
{
  //초기화
 rtc.halt(false); 
 rtc.writeProtect(false); 
 Serial.begin(9600); 
 //rtc.setDOW(MONDAY); //요일설정
 //rtc.setTime(8, 49, 00); // 24시간형식(시간,분,초)
 //rtc.setDate(19, 12, 2019); // (날짜,달,년도)
}
 
void loop(){
 Serial.print(rtc.getDOWStr()); //날짜
 Serial.print(" ");
 
 Serial.print(rtc.getDateStr()); //요일
 Serial.print(" -- ");
 
 Serial.println(rtc.getTimeStr()); //시간
 
 delay (1000);
}
