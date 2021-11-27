#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

DHT dht(6, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  lcd.clear();
  digitalWrite(3, LOW);
  lcd_print();
  turn_LED();
  water();
  delay(1000);
}

void water(){
  int soil_moisture = analogRead(A1);
  lcd.setCursor(10,0);
  lcd.print(soil_moisture);
  if(soil_moisture >= 700){
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
  }
}

void lcd_print(){
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print(Humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(Temperature);
  lcd.print("C");
}

void turn_LED(){
  int cdsValue = analogRead(A0) / 4;
  lcd.setCursor(10,1);
  lcd.print(cdsValue);
  if(cdsValue >= 60 && cdsValue != 0){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
