// Created by Jack Wilson 5/28/2020 for the EE 352 final project.
// The goal of this sketch is build an electric compass.

#include <Servo.h>
#include <QMC5883L.h>

Servo aServo;
QMC5883L compass;

const bool testing = false;
int posX, posY, posZ;
float heading, headingDegrees;


void setup() {
  // start ports
  Wire.begin();
  Serial.begin(9600);

  // initiate objects
  aServo.attach(9);
  compass.init();
  compass.setMode(Mode_Continuous, ODR_10Hz, RNG_8G, OSR_512);

  // set servo to default position
  aServo.write(0);
  delay(15);
}

void loop() {
  compass.read(&posX, &posY, &posZ);  // updates variables by reference
  updateHeadings();
  aServo.write(convHeadToPos(headingDegrees));
  delay(500);
}

// Calculate heading when the magnetometer is level, then correct for signs of axis.
// This uses the global variables.
void updateHeadings() {
  // Atan2() automatically checks the correct formula taking care of the quadrant you are in
  heading = atan2(posY, posX);

  float declinationAngle = 0.2772;  // +15° 53' = 0.2772
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;

  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;

  // Convert radians to degrees for readability.
  headingDegrees = heading * 180 / M_PI;

  if (testing) {
    Serial.print("x: ");
    Serial.print(posX);
    Serial.print("    y: ");
    Serial.print(posY);
    Serial.print("    z: ");
    Serial.print(posZ);
    Serial.print("    heading: ");
    Serial.print(heading);
    Serial.print("    Radius: ");
    Serial.print(headingDegrees);
    Serial.println();
  }
}

// Convert degrees to servo motor position.
// The servo flips on the N-S lines.
float convHeadToPos(float deg) {
  return (deg >= 180) ? deg - 180 : deg ;
}
