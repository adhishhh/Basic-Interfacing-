#include <Servo.h>
#include <CapacitiveSensor.h>

Servo servoMotor;

const int CAP_SENSOR_SEND = 2;
const int CAP_SENSOR_RECEIVE = 4;
const int SERVO_PIN = 9;

const int CAP_THRESHOLD = 100;

CapacitiveSensor capSensor = CapacitiveSensor(CAP_SENSOR_SEND, CAP_SENSOR_RECEIVE);

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
}

void loop() {
  long capValue = capSensor.capacitiveSensor(30);
  Serial.println(capValue);
  if (capValue > CAP_THRESHOLD) {
    servoMotor.write(90);
    delay(1000);
  }
}
