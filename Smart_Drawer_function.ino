void print2digits(int number) {
  if (number >= 0 && number < 10)
  {
    Serial.write('0');
  }
  Serial.print(number);
}

void stmoter1()   //서랍 첫번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 3500; x++) //1100 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);          
  }
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);                     
  }
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 3500; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}


void stmoter2()   //서랍 두번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 2500; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴

  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 2500; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}

void stmoter3()   //서랍 세번째 칸
{  
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 1500; x++) //1100 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 1500; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

//void 함수
}


void stmoter4()   //서랍 네번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 3500; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 2200; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 3500; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 2200; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}

void stmoter5()   //서랍 다섯번째 칸
{
  // 스텝모터가 서랍의 위치로 이동  
  digitalWrite(dir, LOW);

  for(int x = 0; x < 2400; x++) //1100 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 2200; x++) //2200 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 2400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 2200; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
 
//void 함수
}


void stmoter6()   //서랍 여섯번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
 
  digitalWrite(dir, LOW);

  for(int x = 0; x < 1300; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 2400; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 1300; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 2400; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}

void stmoter7()   //서랍 일곱번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 3400; x++) //1100 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 4500; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179);  
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 3400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 4500; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}


void stmoter8()   //서랍 여덟번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  
  digitalWrite(dir, LOW);

  for(int x = 0; x < 2400; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 4500; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 2400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 4500; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}

void stmoter9()   //서랍 아홉번째 칸
{
  // 스텝모터가 서랍의 위치로 이동

  digitalWrite(dir, LOW);

  for(int x = 0; x < 1400; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 4500; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 1400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 4500; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}


void stmoter10()   //서랍 열번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 3400; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 6600; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 3400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 6600; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}

void stmoter11()   //서랍 열한번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 2400; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 6600; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 2400; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 6600; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}


void stmoter12()   //서랍 열두번째 칸
{
  // 스텝모터가 서랍의 위치로 이동
  digitalWrite(dir, LOW);

  for(int x = 0; x < 1600; x++) //1200 1칸
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, LOW);

  for(int x = 0; x < 6400; x++) //2500 1칸
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  // 서브모터가 서랍을 열었다가 다시 돌아옴  
  
  myservo.write(1); 
  delay(500);  
  myservo.write(179); 
  /*
  
  for(int pos = 150; pos>=1; pos-=1)     //다시 서보모터가 원상태로 돌아갑니다.
  {                                
    myservo.write(pos);                                   
  } 
  
  for(int pos = 1; pos < 151; pos += 1)  //서보모터가 천천히 돌아가며 서랍을 엽니다.
  {                                  
    myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.                   
  } 
  */
  delay(1000);
  // 거리센서가 거리값을 측정하고, 10cm초과로 거리가 1분동안 유지될 시 메시지를 보냄
  Sensor_val = map(analogRead(Sensor), 0, 1023, 0, 5000);  //전압값으로 변경
  distance = (24.61/(Sensor_val-0.1696))*1000;//CM 거리값으로 변경

  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.23" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(5000); //3초에 한번씩 센서 리딩

  digitalWrite(dir, HIGH);

  for(int x = 0; x < 1600; x++)
  {
    digitalWrite(st, HIGH);
    delayMicroseconds(700);
    digitalWrite(st, LOW);
    delayMicroseconds(700);
  }
  delay(1000);

  digitalWrite(10, HIGH);

  for(int x = 0; x < 6400; x++)
  {
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
  }
  delay(1000);
  
//void 함수
}
