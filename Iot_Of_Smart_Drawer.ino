#include <Servo.h>
#include <Time.h>
#include <SPI.h>
#include <Client.h>
#include <Ethernet.h>
#include <TimeLib.h>
#include <DS1302RTC.h>
DS1302RTC RTC(4, 3, 2);  
#define DS1302_GND_PIN 33
#define DS1302_VCC_PIN 35
Servo myservo;

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF1, 0x67 };
char server[] = "192.168.23.23"; //접속할 서버 주소 APMSETUP이 실행중인 컴퓨터의 ip

int st = 7;
int dir = 8;
char Sensor = A0; //A0에 센서연결
int Sensor_val;   //센서 ADC값 저장 변수
float distance;   // distance값을 저장할 변수 선언

IPAddress ip(192,168,23,100);     //아두이노에 부여하는 ip (고정ip부여함)
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);
EthernetClient client;

void setup() {
  pinMode(st, OUTPUT);   //step pin
  pinMode(dir, OUTPUT);   //dir pin
  pinMode(9, OUTPUT);   //step pin
  pinMode(10, OUTPUT);   //dir pin
  pinMode(Sensor, INPUT);
  myservo.attach(6);
  Serial.begin(9600);
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);
  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  Ethernet.begin(mac, ip, gateway, subnet);  //Ethernet

  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please run the SetTime");
    Serial.println("example to initialize the tim  e and begin running.");
    Serial.println();
  }
  if (!RTC.writeEN()) {
  Serial.println("The DS1302 is write protected. This normal.");
  Serial.println();
  }
  delay(5000);
}

void loop() {
  tmElements_t tm;
  Serial.print("초기화 후 시간: ");
  Serial.print(RTC.get());

  if (! RTC.read(tm)) {
    Serial.print("  시간 = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", 날짜 (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.print(", 요일 = ");
    Serial.print(tm.Wday);
    Serial.println();
  } 
  else {
    Serial.println("DS1302 read error!  Please check the circuitry.");
    Serial.println();
    delay(9000);
  }
  delay (1000);
  
  if(tm.Minute == 5 && tm.Second == 00)
  {
    stmoter1();
  }
  
  if(tm.Minute == 10 && tm.Second == 00)
  {
    stmoter2();
  }
  if(tm.Minute == 15 && tm.Second == 00)
  {
    stmoter3();
  }
  if(tm.Minute == 20 && tm.Second == 00)
  {
    stmoter4();
  }
  if(tm.Minute == 25 && tm.Second == 00)
  {
    stmoter5();
  }
  if(tm.Minute == 30 && tm.Second == 00)
  {
    stmoter6();
  }
  if(tm.Minute == 35 && tm.Second == 00)
  {
    stmoter7();
  }
  if(tm.Minute == 40 && tm.Second == 00)
  {
    stmoter8();
  }
  if(tm.Minute == 45 && tm.Second == 00)
  {
    stmoter9();
  }
  if(tm.Minute == 50 && tm.Second == 00)
  {
    stmoter10();
  }
  if(tm.Minute == 55 && tm.Second == 00)
  {
    stmoter11();
  }
  if(tm.Minute == 00 && tm.Second == 00)
  {
    stmoter12();
  }
}
