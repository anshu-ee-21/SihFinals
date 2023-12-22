const int sensorPin = A0; // Analog pin connected to the sensor
const int ledPin = 13;    // LED pin for visual indication

void setup() {
  Serial.begin(9600);     // Initialize serial communication
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog sensor value
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage (assuming 5V Arduino)

  // Calculate the water level based on your sensor's specifications
  // Replace the formula with your sensor's calibration data
  float waterLevel = map(voltage, 0, 5, 0, 100); // Map the voltage to a percentage (0-100%)

  // Print the sensor value, voltage, and water level
 // Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print(voltage);
  Serial.print(",");
  Serial.println(waterLevel);

  // Visual indication using the onboard LED
  if (waterLevel < 30) {
    digitalWrite(ledPin, HIGH); // Turn on the LED if water level is below 30%
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED if water level is 30% or above
  }

  delay(1000); // Add a delay to avoid rapid readings
}

