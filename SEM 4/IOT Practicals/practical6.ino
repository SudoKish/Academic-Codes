

/*

6. Create a program that illuminates the green LED if the counter is less than 100,
illuminates the yellow LED if the counter is between 101 and 200 and illuminates the
red LED if the counter is greater than 200

*/

// Define the pin numbers for the LEDs
const int greenLedPin = 2;
const int yellowLedPin = 3;
const int redLedPin = 4;

// Define the counter variable
int counter = 0;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Check the value of the counter and illuminate the corresponding LED
  if (counter < 100) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (counter >= 101 && counter <= 200) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }

  // Increment the counter
  counter++;

  // Reset the counter if it exceeds 300 (to demonstrate continuous operation)
  if (counter > 300) {
    counter = 0;
  }

  // You can add a delay here to control the rate of change of the LEDs
  delay(100); // 100 milliseconds delay
}


/*
Modularization: To improve code readability and maintainability, consider breaking down the code into separate functions. For example, you could create a function to handle LED illumination based on the counter value.
Analog Inputs: Instead of using a static counter, you could incorporate analog inputs from sensors to dynamically change the counter value based on real-world parameters. This could make the program more versatile and applicable to various scenarios.
Brightness Control: If you're using LEDs capable of PWM (Pulse Width Modulation), you could vary the brightness of the LEDs based on the counter value. This would provide a finer level of control over the visual output.
Feedback Mechanism: Implementing feedback mechanisms such as serial communication with a computer or displaying the counter value on an LCD screen could provide real-time feedback on the system's operation.
Error Handling: Integrate error handling mechanisms to handle unexpected scenarios, such as sensor failures or out-of-range counter values. This could involve setting default LED states or triggering specific actions in case of errors.
Optimization: Look for opportunities to optimize the code for efficiency, such as minimizing delays or reducing power consumption. This is especially important for battery-powered or resource-constrained applications.
Expansion: Consider expanding the program to control additional peripherals or integrate with other systems. For example, you could add functionality to log data to an SD card or communicate with other Arduino boards via wireless modules.
Documentation: Provide thorough documentation within the code, including comments and explanations of the program's functionality, pin connections, and any external dependencies.

Conclusion:
This Arduino program illustrates how to control multiple LEDs based on a counter variable. By using conditional statements, we can determine which LED to illuminate based on the value of the counter. This program can be extended to incorporate additional functionality or be used as a basis for more complex projects involving multiple sensors and actuators.






*/