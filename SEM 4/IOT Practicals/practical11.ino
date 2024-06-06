/*

11. Write a program so it displays the temperature in Fahrenheit as well as the maximum
and minimum temperatures it has seen

*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

// Variable to store the maximum temperature seen
float maxTemperature = -127.0; // Initializing with an invalid temperature value

// Variable to store the minimum temperature seen
float minTemperature = 1000.0; // Initializing with an invalid temperature value

void setup() {
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);

  // Initialize the DS18B20 temperature sensor
  sensors.begin();
}

void loop() {
  // Request temperature readings from all DS18B20 sensors
  sensors.requestTemperatures();

  // Get the temperature value in Celsius
  float temperatureC = sensors.getTempCByIndex(0);

  // Convert Celsius to Fahrenheit
  float temperatureF = sensors.convertCtoF(temperatureC);

  // Check if the temperature reading is valid (not -127 degrees Celsius)
  if (temperatureC != -127.00) {
    // Print the temperature value to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.print(" °C, ");
    Serial.print(temperatureF);
    Serial.println(" °F");

    // Update maximum temperature
    if (temperatureC > maxTemperature) {
      maxTemperature = temperatureC;
    }

    // Update minimum temperature
    if (temperatureC < minTemperature) {
      minTemperature = temperatureC;
    }

    // Display maximum and minimum temperatures
    Serial.print("Max Temperature: ");
    Serial.print(maxTemperature);
    Serial.print(" °C, ");
    Serial.print(sensors.convertCtoF(maxTemperature));
    Serial.println(" °F");

    Serial.print("Min Temperature: ");
    Serial.print(minTemperature);
    Serial.print(" °C, ");
    Serial.print(sensors.convertCtoF(minTemperature));
    Serial.println(" °F");
  } else {
    // Print an error message if the temperature reading is invalid
    Serial.println("Error: Unable to read temperature");
  }

  // Delay for a short interval before taking another reading
  delay(1000); // Adjust the delay time as needed
}


/*
Theory:

This program reads the analog value from a temperature sensor connected to one of the analog pins of the Arduino board. The analog value is then converted into temperature in both Celsius and Fahrenheit using appropriate conversion formulas. The program keeps track of the maximum and minimum temperatures seen so far. The calculated temperatures, along with the maximum and minimum values, are then sent to the Serial Monitor for display on the computer.

Conclusion:

This Arduino program reads the analog value from a temperature sensor connected to the Arduino board, converts it into temperature in both Celsius and Fahrenheit, and then sends the temperature values, along with the maximum and minimum temperatures seen so far, to the Serial Monitor on the computer. By monitoring the Serial Monitor, you can observe the real-time temperature readings in both Celsius and Fahrenheit, as well as track the maximum and minimum temperatures. This program demonstrates how to perform temperature conversions and track maximum and minimum values using an Arduino board.








*/