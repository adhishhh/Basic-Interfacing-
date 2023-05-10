#include <IRremote.h>
#include <Servo.h>

Servo servoMotor;

const int IR_PIN = 11;
const int SERVO_PIN = 9;

IRrecv irReceiver(IR_PIN);
decode_results irResults;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
  irReceiver.enableIRIn();
}

void loop() {
  if (irReceiver.decode(&irResults)) {
    switch (irResults.value) {
      case 0xFF6897:
        servoMotor.write(0);
        break;
      case 0xFF9867:
        servoMotor.write(90);
        break;
      case 0xFFB04F:
        servoMotor.write(180);
        break;
    }
    irReceiver.resume();
  }
}
