const int BTN = 2;
const int LED = 3;

bool is_led_on = true;

void setup()
{
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (digitalRead(BTN) == HIGH) {
    is_led_on = !is_led_on;
    delay(100);
  }
  
  if (is_led_on) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(5);
}