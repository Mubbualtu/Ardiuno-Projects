// Define the pins for the sonar sensor
const int trigPin = 2;
const int echoPin = 3;

// Variables for distance calculation
long duration;
float distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the trigPin as an output and echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance on the serial monitor
  Serial.println(distance);

  // Wait for a short delay before the next reading
  delay(500);
}
