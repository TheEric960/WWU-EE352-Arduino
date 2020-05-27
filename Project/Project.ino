// Created by Jack Wilson 5/27/2020 for the EE 352 final project
// The goal of this sketch is build an electric compass.

#include <Servo.h>
#include <QMC5883L.h>

Servo aServo;
QMC5883L compass;

int posX = 0, posY = 0, posZ = 0;

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
  compass.read(&posX, &posY, &posZ);

  // Calculate heading when the magnetometer is level, then correct for signs of axis.

  // Atan2() automatically checks the correct formula taking care of the quadrant you are in
  float heading = atan2(posY, posX);

  float declinationAngle = 0.2772;  // +15° 53' = 0.2772
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;

  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;

  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180 / M_PI;

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
  delay(500);
}
