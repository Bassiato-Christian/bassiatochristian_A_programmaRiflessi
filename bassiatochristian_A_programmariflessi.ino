#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 8, 9, 10, 11);
int pinBottone = 2;
int pinLed = 6;
int pinBuzzer = 7;
int delayLed = 0;
int delayBuzzer = 0;
int reazioneLed = 0;
int reazioneBuzzer = 0;
String svuotaSeriale = "";

void setup()
{
  lcd.begin(16, 2);
  pinMode(pinBottone,INPUT);
  digitalWrite(pinBottone,HIGH);
  pinMode(pinLed,OUTPUT);
  pinMode(pinBuzzer,OUTPUT);
}

void loop()
{
  delayLed = random(1000,7000);
  delayBuzzer = random(1000,7000);
  lcd.setCursor(0,0);
  lcd.print("Premi il bottone");
  lcd.setCursor(2,1);
  lcd.print("per iniziare");
  while(digitalRead(pinBottone) == HIGH);
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Gioco partito!");
  lcd.setCursor(1,1);
  lcd.print("Attento al Led");
  delay(delayLed);
  digitalWrite(pinLed,HIGH);
  reazioneLed = millis();
  while(digitalRead(pinBottone) == HIGH);
  digitalWrite(pinLed,LOW);
  reazioneLed = millis() - reazioneLed;
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Tempo Led:");
  lcd.setCursor(5,1);
  lcd.print(reazioneLed);
  lcd.setCursor(9,1);
  lcd.print("ms");
  delay(5000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Gioco partito!");
  lcd.setCursor(0,1);
  lcd.print("Attento al Buzz!");
  delay(delayBuzzer);
  tone(pinBuzzer, 1000);
  reazioneBuzzer = millis();
  while(digitalRead(pinBottone) == HIGH);
  reazioneBuzzer = millis() - reazioneBuzzer;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Tempo Buzzer");
  lcd.setCursor(5,1);
  lcd.print(reazioneBuzzer);
  lcd.setCursor(9,1);
  lcd.print("ms");
  tone(pinBuzzer, 1000, 1);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Led:");
  lcd.setCursor(5,0);
  lcd.print(reazioneLed);
  lcd.setCursor(9,0);
  lcd.print("ms");
  lcd.setCursor(0,1);
  lcd.print("Buzzer:");
  lcd.setCursor(8,1);
  lcd.print(reazioneBuzzer);
  lcd.setCursor(12,1);
  lcd.print("ms");
  delay(5000);
  while(digitalRead(pinBottone) == HIGH);
}
