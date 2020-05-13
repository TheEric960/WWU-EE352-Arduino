
// Created by Jack Wilson 5/13/2020 for EE 352 homework 2, question 2
// The function of this program is to take 5 floating point numbers
//  as inputs and return the average value.

void setup() {
  Serial.begin(9600);
  
  float arr[] = {2.5, 3.0, 2.75, 6, 0.2};
  Serial.println(average(arr, sizeof(arr)/sizeof(arr[0])));
  Serial.println(average(2.5, 3.0, 2.75, 6, 0.2));
}

void loop() {
  
}

// returns the average of a float array
float average(float values[], int arrSize) {
  float total = 0;
  
  for (int i=0; i < arrSize; i++) {
    total += values[i];
  }

  return total / arrSize;
}

// returns the average of 5 float numbers
float average(float a, float b, float c, float d, float e) {
  return (a + b + c + d + e) / 5;
}
