
// Created by Jack Wilson 5/13/2020 for EE 352 homework 2, question 3
// The function of this program is to adjust an attached LED's brightness
//  using a potentiometer.
// Assumption: LED is connected directly to a digital pin.

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, analogRead(A0));
  Serial.println(analogRead(A0));
}
