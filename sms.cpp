#include <Servo.h>

const int SERVO_PIN = 9;
const int SOIL_SENSOR_PIN = A0;

const int SOIL_THRESHOLD = 500;

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
  servoMotor.write(90);
}

void loop() {
  int soilValue = analogRead(SOIL_SENSOR_PIN);
  Serial.println(soilValue);
  if (soilValue > SOIL_THRESHOLD) {
    servoMotor.write(0);
    delay(1000);
    servoMotor.write(90);
    delay(1000);
    servoMotor.write(180);
    delay(1000);
    servoMotor.write(90);
    delay(1000);
  }
}
