#include <Arduino.h>

  
  unsigned long aktualnyCzas = 0;
  unsigned long zapisanyCzas1 = 0;
  unsigned long zapisanyCzas2 = 0;
  unsigned long czasTrzymaniaLED1;
  unsigned long czasTrzymaniaLED2;
  unsigned long czasMigniecia;
  const uint8_t LED1 = 4;
  int przycisk1 = 7;
  const int LED2 = 3;
  int przycisk2 = 5;
  const int interwal = 1000;
  #define CZAS_DO_WYLACZENIA_DIODY 2000
  #define MIGNIECIE 300

void setup() {
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(przycisk1,INPUT_PULLUP);
  pinMode(przycisk2,INPUT_PULLUP);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
}

void loop() {

digitalRead(przycisk1);
digitalRead(przycisk2);
aktualnyCzas = millis();



if(digitalRead(przycisk1) == LOW)
{
  digitalWrite(LED1,HIGH);
  zapisanyCzas1 = millis();
}

else if(isTimeOfDiode1HighValueElasped())
{
  digitalWrite(LED1, LOW);
}

if(digitalRead(przycisk1) == LOW)
{
  digitalWrite(LED1,HIGH);
  czasTrzymaniaLED1 = millis();
}
else if(digitalRead(przycisk1) == HIGH && czasTrzymaniaLED1 > 3000)
{

  
  digitalWrite(LED1,HIGH);
  czasMigniecia = millis();
  }
  if(digitalRead(przycisk1) == HIGH && czasMigniecia > MIGNIECIE)
  {
  digitalWrite(LED1,LOW);
  }
}


if(digitalRead(przycisk2) == LOW)
{
  digitalWrite(LED2,HIGH);
  zapisanyCzas2 = millis();
}

else if(digitalRead(przycisk2) == HIGH && aktualnyCzas - zapisanyCzas2 > CZAS_DO_WYLACZENIA_DIODY)
{
  digitalWrite(LED2, LOW);
}

}


boolean isTimeOfDiode1HighValueElasped(){
  return digitalRead(przycisk1) == HIGH && isTimeHigherThanExpected();
}

boolean isTimeHigherThanExpected(){
  return aktualnyCzas - zapisanyCzas1 > CZAS_DO_WYLACZENIA_DIODY;
}