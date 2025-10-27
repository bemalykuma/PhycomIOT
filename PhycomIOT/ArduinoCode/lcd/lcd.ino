#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte heart[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000 };
byte ong[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000 };

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(2, heart);
  lcd.createChar(6, ong);
  lcd.setCursor(0, 0);
  lcd.print("I");
  lcd.write(byte(2)); 
  lcd.print("IT");

  Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(A0); // อ่านค่าเซนเซอร์
  float voltage = (sensorValue * (5.0 / 1023.0)); // แปลงค่า Analog เป็น Voltage
  float temperatureC = ((voltage - 0.5) * 100.0) - 10; // แปลง Voltage เป็น อุณหภูมิ (Celsius)
  
  lcd.setCursor(0, 1);
  lcd.print("67070148 ");
  lcd.print(temperatureC);
  lcd.write(byte(6)); 

  Serial.println(sensorValue);
  
  delay(1000); // หน่วงเวลา 1 วินาที
}
