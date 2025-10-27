
void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(A0);
  float Vout = adcValue * 5.0 / 1023.0;      // ถ้าใช้ Arduino UNO (10-bit, 5V)
  float Rth = 10000.0 * Vout / (5.0 - Vout); // คำนวณค่า R ของ thermistor
  // แปลงเป็นอุณหภูมิ
  float tempK = 1.0 / ( (1.0 / 298.15) + (1.0 / 4050) * log(Rth / 10000.0) );
  float tempC = tempK - 273.15;

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}