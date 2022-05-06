#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

DHT dht(6, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float Humidity;
float Temperature;

void setup() { 
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  lcd_print();
  delay(1000);
}


void lcd_print(){
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(Humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.print(Temperature);
  lcd.print("C");
}
