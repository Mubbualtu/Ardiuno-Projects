
const int gasSensorPin = A0;  
const int buzzer = 9;  


const float gasThreshold = 2.0;  // Adjust this value according to your sensor's sensitivity

void setup() {
  pinMode(buzzer, OUTPUT);  // Configure the LED pin as output
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Read the analog value from the gas sensor
  int sensorValue = analogRead(gasSensorPin);

  // Convert the analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Check if gas concentration exceeds the threshold
  if (voltage > gasThreshold) {
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 1200);
      // Turn on the LED if gas is detected
    // Serial.println("Gas detected!");
  } else {
    digitalWrite(buzzer, LOW);
     noTone(buzzer);
      // Turn off the LED if no gas is detected
  }

  delay(1000);  // Delay for 1 second before taking the next reading
}
