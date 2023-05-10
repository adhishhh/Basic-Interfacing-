#include <Servo.h>
#include <IRremote.h>
#include <CapacitiveSensor.h>

const int IR_SENSOR_PIN = 7;
const int SERVO_PIN = 9;
const int SOIL_SENSOR_PIN = A0;
const int CAP_SENSOR_SEND = 2;
const int CAP_SENSOR_RECEIVE = 4;

const int SOIL_THRESHOLD = 500;
const int CAP_THRESHOLD = 100;

IRrecv irSensor(IR_SENSOR_PIN);
decode_results irResults;

Servo servoMotor;

CapacitiveSensor capSensor = CapacitiveSensor(CAP_SENSOR_SEND, CAP_SENSOR_RECEIVE);

void setup() {
  Serial.begin(9600);

  irSensor.enableIRIn();
  servoMotor.attach(SERVO_PIN);
  servoMotor.write(90);
}

void loop() {
  if (irSensor.decode(&irResults)) {
    switch (irResults.value) {
      case 0xFFA25D:
        servoMotor.write(0);
        break;
      case 0xFF629D:
        servoMotor.write(90);
        break;
      case 0xFFE21D:
        servoMotor.write(180);
        break;
      default:
        break;
    }
    irSensor.resume();
  }

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

  long capValue = capSensor.capacitiveSensor(30);
  Serial.println(capValue);
  if (capValue > CAP_THRESHOLD) {
    servoMotor.write(90);
    delay(1000);
  }
}
