// Created by Jack Wilson 5/13/2020 for EE 352 lab 3, part 2
// The goal of this sketch is to make the built-in LED blink depending
//  on which pin it is connected to without using delay().
// Assumptions: only one pin is connected to ground at a time.

const int ledPin = 13;
unsigned long time = millis();

void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);

  if (digitalRead(7) == LOW) {
    // wait for a second
    if (millis() - time >= 1000) {
      digitalWrite(ledPin, LOW);
      while (millis() - time <= 2000) {
        // wait until another second has passed
      }
      time = millis();
    }
  } else if (digitalRead(6) == LOW) {
    // wait for a half-second
    if (millis() - time >= 500) {
      digitalWrite(ledPin, LOW);
      while (millis() - time <= 1000) {
        // wait until another half-second has passed
      }
      time = millis();
    }
  } else if (digitalRead(5) == LOW) {
    // wait for a quarter-second
    if (millis() - time >= 250) {
      digitalWrite(ledPin, LOW);
      while (millis() - time <= 500) {
        // wait until another quarter-second has passed
      }
      time = millis();
    }
  }
}
