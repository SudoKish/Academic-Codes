/*

5. Write a program using Arduino to control LED (One or more ON/OFF). Or Blinking

*/

// Define the pin number for the LED
const int ledPin = 13;

// Define the interval for blinking (in milliseconds)
const int blinkInterval = 1000; // 1000 milliseconds = 1 second

// Variable to store the current state of the LED
bool ledState = false;

// Variable to store the previous time the LED was toggled
unsigned long previousMillis = 0;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time

  // Check if it's time to toggle the LED based on the blink interval
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis; // Save the current time as the previous time

    // Toggle the LED state
    ledState = !ledState;

    // Apply the new state to the LED pin
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }

  // You can add more functionality here, like responding to user input to turn the LED on/off
}

/*Theory:
Arduino is an open-source electronics platform based on easy-to-use hardware and software. It consists of a programmable microcontroller (typically Atmel AVR or ARM) and a development environment that allows for the writing, uploading, and execution of code on the microcontroller.

For this example, we'll use the Arduino IDE (Integrated Development Environment) to write and upload our code to the Arduino board. We'll connect an LED to one of the digital pins of the Arduino board. The digital pins can be configured as either input or output. In our case, we'll set the pin connected to the LED as an output pin.

The program will turn the LED on for a certain duration, then turn it off for another duration, creating a blinking effect. This will be achieved by setting the pin to a HIGH state to turn the LED on and then to a LOW state to turn it off, with delays in between.

Conclusion:
This simple Arduino program demonstrates how to control an LED connected to an Arduino board. By setting the appropriate pin mode and using the digitalWrite function, we can easily turn the LED on and off. By incorporating delays, we can create different blinking patterns or durations for the LED. This is just the beginning of what can be achieved with Arduino, as it can be expanded to control various sensors, actuators, and other electronic components, making it a powerful tool for prototyping and DIY projects.
*/