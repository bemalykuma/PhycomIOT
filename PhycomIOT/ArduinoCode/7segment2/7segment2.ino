#include <stdlib.h>
#include <string.h>

const int segments[] = {2, 3, 4, 5, 6, 7, 8}; // Segment pins a-g
const int leftSegment = 11, rightSegment = 12;

// Digit segment patterns (0-9)
const int digitPatterns[][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

const char text[] = "67070148";

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(leftSegment, OUTPUT);
  pinMode(rightSegment, OUTPUT);
}

void loop() {
  for (int i = 0; i < strlen(text); i += 2) {
    int digit1 = text[i] - '0', digit2 = text[i + 1] - '0';
    showTwoDigits(digit1, digit2);
  }
}

void showTwoDigits(int digit1, int digit2) {
  unsigned long startTime = millis();
  while (millis() - startTime < 1000) {
    displayDigit(digit1, rightSegment);
    delay(10);
    displayDigit(digit2, leftSegment);
    delay(10);
  }
}

void displayDigit(int digit, int activeSegment) {
  digitalWrite(leftSegment, activeSegment == leftSegment ? HIGH : LOW);
  digitalWrite(rightSegment, activeSegment == rightSegment ? HIGH : LOW);

  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], digitPatterns[digit][i] ? HIGH : LOW);
  }
}