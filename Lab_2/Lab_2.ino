
// Created by Jack Wilson 5/5/2020 for EE 352 lab 2
// The function of this program is to convert a serial integer input
//  into greycode.

void setup() {
  Serial.begin(9600);
}

void loop() {
  int aByte;
  if (Serial.available()) {
    aByte = Serial.parseInt();
    Serial.println(BinToGrey(aByte), BIN);
  }
}

byte BinToGrey(byte aByte) {
  return aByte ^ (aByte >> 1);
}
