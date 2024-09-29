#include <DHT.h>

#define DHTPIN 2      // Define the pin where the sensor is connected
#define DHTTYPE DHT11 // Define the type of sensor (DHT11 or DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Delay for 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
