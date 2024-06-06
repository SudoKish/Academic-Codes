/*

12. Understanding the connectivity of Raspberry-Pi /Beagle board circuit / Arduino with
IR sensor. Write an application to detect obstacle and notify user using LEDs

*/

// Define pin numbers
const int irSensorPin = 2; // IR sensor OUT pin
const int greenLedPin = 8; // Green LED
const int yellowLedPin = 9; // Yellow LED
const int redLedPin = 10; // Red LED

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the sensor pin as an input
  pinMode(irSensorPin, INPUT);

  // Set the LED pins as outputs
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Read the state of the IR sensor
  int obstacleDetected = digitalRead(irSensorPin);

  // Print the sensor state to the serial monitor
  Serial.println(obstacleDetected);

  // If obstacle detected, turn on the red LED and turn off the others
  if (obstacleDetected == HIGH) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
  } else {
    // If no obstacle detected, turn on the green LED and turn off the others
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
  }

  // Delay for a short interval before taking another reading
  delay(100); // Adjust the delay time as needed
}

/*Circuit Connection:

Connect the VCC pin of the IR sensor to a 5V pin on the Arduino.
Connect the GND pin of the IR sensor to a GND pin on the Arduino.
Connect the OUT pin of the IR sensor to a digital pin (e.g., pin 2) on the Arduino.
Connect three LEDs to digital output pins of the Arduino, each representing a different status: one for obstacle detected, one for obstacle not detected, and one for an error condition (if needed).
Optionally, add current-limiting resistors (usually around 220 ohms) in series with each LED to prevent damage to the LEDs.

Explanation:

The code sets up the specified pins as inputs and outputs.
It continuously reads the state of the IR sensor using digitalRead() and checks if an obstacle is detected.
Depending on the sensor reading, it lights up the appropriate LED to indicate the status (obstacle detected or not detected).
It also provides serial output for debugging purposes, which can be viewed using the Serial Monitor in the Arduino IDE.
Conclusion:
This simple Arduino application demonstrates how to use an IR sensor to detect obstacles and notify the user using LEDs. The same concept can be applied to Raspberry Pi or BeagleBoard by adapting the code accordingly and using appropriate GPIO pins for sensor input and LED output. Additionally, you can enhance the application by adding features like sound alerts or notifications through email or SMS.






*/