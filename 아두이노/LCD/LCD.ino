#include <LiquidCrystal_I2C.h>
int cdsValue;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  cdsValue = analogRead(A0) / 4;
  lcd_print();
  delay(1000);
}

void lcd_print(){
  lcd.clear();
  lcd.setCursor(0,1);
  if(cdsValue <= 50){
    lcd.print("dark ");
    lcd.setCursor(0,1);
    lcd.print(cdsValue);
  }
  else{
    lcd.print("bright");
    lcd.setCursor(0,1);
    lcd.print(cdsValue);
  }
}
