
// Created by Jack Wilson 5/5/2020 for EE 352 lab 2
// Last updated 5/8/2020 to adhere to the lab specifications
// The function of this program is to convert a serial binary character input
//  into greycode and count until 8 bits are filled (255).

void setup() {
  Serial.begin(9600);
}

void loop() {
  // check for serial input
  if (Serial.available()) {
    int aByte = Serial.read();

    // report all conversions up to 255
    while (aByte < 256) {
      Serial.print("Decimal: " + (String)aByte + ", Binary: ");
      Serial.print(aByte, BIN);
      Serial.print(", Grey: ");
      Serial.print(BinToGrey(aByte), BIN);
      Serial.println();
      aByte += 1;
    }

    while (true) {
      // lock/finish the program
    }
  }
}

// converts a binary input into grey code
byte BinToGrey(byte aByte) {
  return aByte ^ (aByte >> 1);
}
