/*

8. Write a program that asks the user for a number and outputs the number squared that is entered

*/

void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Wait for the serial monitor to open
  while (!Serial) {
    ;
  }

  // Prompt the user to enter a number
  Serial.println("Enter a number:");
}

void loop() {
  if (Serial.available() > 0) {
    // Read the number entered by the user
    int number = Serial.parseInt();

    // Calculate the square of the number
    int square = number * number;

    // Output the result
    Serial.print("The square of ");
    Serial.print(number);
    Serial.print(" is ");
    Serial.println(square);

    // Prompt the user to enter another number
    Serial.println("Enter another number:");
  }
}


/*Theory:

This Arduino program utilizes the Serial communication feature to interact with the user. It prompts the user to enter a number, reads the input from the Serial Monitor, computes the square of the entered number, and then outputs the result.

Conclusion:

This Arduino program interacts with the user through the Serial Monitor. It prompts the user to enter a number, calculates the square of the entered number, and then outputs the result to the Serial Monitor. This program demonstrates how to incorporate user input and perform basic arithmetic operations on Arduino. It can be expanded to handle more complex calculations or incorporate error handling for invalid inputs.

*/