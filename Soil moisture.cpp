int sensorPin = A0; // analog input pin connected to the sensor
int sensorValue = 0; // variable to store the analog value read from the sensor
int moisturePercentage = 0; // variable to store the moisture percentage

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  sensorValue = analogRead(sensorPin); // read the analog value from the sensor
  moisturePercentage = map(sensorValue, 0, 1023, 0, 100); // map the analog value to a percentage value
  Serial.print("Moisture percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  delay(1000); // wait for 1 second
}

