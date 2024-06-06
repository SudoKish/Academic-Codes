/*

9. Write a program to control the color of the LED by turning 3 different
potentiometers. One will be read for the value of Red, one for the value of Green,
and one for the value of Blue

*/

// Define the pins for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Define the pins for the potentiometers
const int redPotPin = A0;
const int greenPotPin = A1;
const int bluePotPin = A2;

void setup() {
  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read the analog values from the potentiometers
  int redValue = analogRead(redPotPin);
  int greenValue = analogRead(greenPotPin);
  int blueValue = analogRead(bluePotPin);

  // Map the analog values (0-1023) to the corresponding PWM values (0-255)
  int redIntensity = map(redValue, 0, 1023, 0, 255);
  int greenIntensity = map(greenValue, 0, 1023, 0, 255);
  int blueIntensity = map(blueValue, 0, 1023, 0, 255);

  // Set the brightness of the RGB LED using PWM
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, greenIntensity);
  analogWrite(bluePin, blueIntensity);
}

/*
Theory:

This program reads analog values from three potentiometers connected to the Arduino's analog input pins. Each potentiometer is responsible for controlling the intensity of a specific color channel: red, green, or blue. The program then maps these analog values to the appropriate PWM (Pulse Width Modulation) range (0-255) for controlling the brightness of each color channel. By adjusting the potentiometers, the user can mix different intensities of red, green, and blue to produce various colors.

Conclusion:

This Arduino program allows the user to control the color of an RGB LED by adjusting three potentiometers. The potentiometers control the intensity of the red, green, and blue color channels, respectively. By adjusting the potentiometers, the user can create a wide range of colors by mixing different intensities of red, green, and blue light. This program demonstrates how to read analog values from potentiometers and use PWM to control the brightness of an RGB LED on an Arduino.
*/