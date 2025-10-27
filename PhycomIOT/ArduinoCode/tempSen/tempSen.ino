
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0); // อ่านค่าเซนเซอร์
  float voltage = (sensorValue * (5.0 / 1023.0)); // แปลงค่า Analog เป็น Voltage
  float temperatureC = ((voltage - 0.5) * 100.0) - 10; // แปลง Voltage เป็น อุณหภูมิ (Celsius)
  
  Serial.print("temperature : ");
  Serial.print(temperatureC);
  Serial.println("C");
  
  delay(1000); // หน่วงเวลา 1 วินาที
}
