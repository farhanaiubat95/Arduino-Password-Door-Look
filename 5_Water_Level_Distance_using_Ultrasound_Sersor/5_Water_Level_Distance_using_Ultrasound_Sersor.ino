#include <LiquidCrystal.h>

// LCD setup: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

// Ultrasonic sensor pins
const int trigPin = 10;
const int echoPin = 11;

// Buzzer pin
const int buzzerPin = 3;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Water Monitor");
  delay(1500);
  lcd.clear();
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  // Show distance on LCD
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Show status on LCD based on distance
  lcd.setCursor(0, 1);
  if (distance <= 3) {
    lcd.print("Status: Very Close");
  } else if (distance <= 8) {
    lcd.print("Status: Close     ");
  } else if (distance <= 18) {
    lcd.print("Status: Far       ");
  } else {
    lcd.print("Status: Safe      ");
  }

  // Buzzer logic based on distance
  if (distance <= 10) {
    int beepDelay;

    if (distance <= 3) {
      beepDelay = 100;  // Very close - fast beep
    } else if (distance <= 8) {
      beepDelay = 300;  // Medium beep
    } else {
      beepDelay = 600;  // Slow beep
    }

    // Beep pattern
    digitalWrite(buzzerPin, HIGH);
    delay(100);  // Beep duration
    digitalWrite(buzzerPin, LOW);
    delay(beepDelay); // Pause before next beep

  } else {
    // Safe distance: no beep
    digitalWrite(buzzerPin, LOW);
    delay(500); // Refresh delay when safe
  }
}
