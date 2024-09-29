/*** www.arduinopoint.com ***/
/*** Arduino with IR Sensor ***/

int SensorPin = 2;
int buzzerPin = 13;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (true) {
    int SensorValue = digitalRead(SensorPin);   
    if (SensorValue == LOW) { 
  tone(buzzerPin, 1); 
 
    } else {
       noTone(buzzerPin);
    }
  }
}
