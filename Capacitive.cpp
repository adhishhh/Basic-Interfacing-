#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(2, 4); // define the pins for the capacitive sensor

void setup() {
  Serial.begin(9600);
  capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF); // autocalibrate the sensor
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30); // read the value of the sensor
  Serial.println(sensorValue); // print the value of the sensor to the serial monitor

  // perform some action based on the value of the sensor
  if (sensorValue > 100) {
    digitalWrite(LED_BUILTIN, HIGH); // turn on the built-in LED
  } else {
    digitalWrite(LED_BUILTIN, LOW); // turn off the built-in LED
  }

  delay(10); // wait for a short period before reading the sensor again
}

