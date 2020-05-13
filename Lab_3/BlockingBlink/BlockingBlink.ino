
// Created by Jack Wilson 5/13/2020 for EE 352 lab 3, part 1
// The goal of this sketch is to make the built-in LED blink depending 
//  on which pin it is connected to.
// Assumptions: only one pin is connected to ground at a time.

const int ledPin = 13;

void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  
  if (digitalRead(7) == LOW) {
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  } else if (digitalRead(6) == LOW) {
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else if (digitalRead(5) == LOW) {
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}
