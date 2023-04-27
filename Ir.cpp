int IRpin = 2;   // define the input pin for the IR sensor

void setup() {
  Serial.begin(9600);   // initialize serial communication
  pinMode(IRpin, INPUT);   // set the IR sensor pin as an input
}

void loop() {
  int IRstate = digitalRead(IRpin);   // read the state of the IR sensor
  Serial.println(IRstate);   // print the state to the serial monitor
  delay(100);   // wait for 100ms before reading again
}
