// Created by Jack Wilson 5/20/2020 for EE 352 lab 4
// The goal of this sketch is to manipulate a servo motor
//  to rotate from 0° to 180° and back incrementally.

#include <Servo.h>

Servo aServo;

int pos = 0;            // position 0-180°
int increment = 45;     // incremental shift in degrees
bool going_up = true;   // increment up/down flag

void setup() {
  Serial.begin(9600);
  aServo.attach(9); 
}

// turn the servo 180° and back 
void loop() {
  aServo.write(pos);
  delay(5000);
  Serial.print("Servo Position: " + (String)pos);
  Serial.println("°, Pot Value: " + (String)(analogRead(A0)/2));
  
  if (going_up) {             // turn towards 180° in the chosen increments
    pos += increment;
    if (pos >= 180) {
      pos = 180;
      going_up = false;
    }
  } else {                    // turn towards 0° in the chosen increments
    pos -= increment; 
    if (pos <= 0) {
      pos = 0;
      going_up = true;
    }
  }
}
