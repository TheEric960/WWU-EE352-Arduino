
// Created by Jack Wilson 5/13/2020 for EE 352 homework 2, question 4
// The goal of this sketch is to start/stop a fan using two buttons.

void setup() {
  pinMode(7, INPUT_PULLUP); // on button
  pinMode(6, INPUT_PULLUP); // off button
  pinMode(13, OUTPUT);      // fan (LED for testing)
}

void loop() {
  if (digitalRead(7) == LOW) {
    digitalWrite(13, HIGH);
  } else if (digitalRead(6) == LOW && digitalRead(13) == HIGH) {
    delay(5000);
    digitalWrite(13, LOW);
  }
}
