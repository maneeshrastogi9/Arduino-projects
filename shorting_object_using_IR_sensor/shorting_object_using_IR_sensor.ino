// Define IR sensor pins
const int irSensor1 = A0;  // Connect to the first IR sensor
const int irSensor2 = A1;  // Connect to the second IR sensor

// Define sorting servo pin
const int servoPin = 9;

// Define motor control pins for the conveyor belt
const int motorEnablePin = 10;  // Motor driver enable pin
const int motorDirectionPin = 8; // Motor driver direction pin

void setup() {
  Serial.begin(9600);
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(servoPin, OUTPUT);

  // Motor control setup
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorDirectionPin, OUTPUT);
}

void loop() {
  // Read analog values from IR sensors
  int sensorValue1 = analogRead(irSensor1);
  int sensorValue2 = analogRead(irSensor2);

  // Check for color based on sensor readings
  if (isColorDetected(sensorValue1, sensorValue2)) {
    // Activate sorting mechanism (servo, stepper motor, etc.)
    sortObject();

    // Activate conveyor belt
    startConveyorBelt();

    delay(1000);  // Delay for stability

    // Stop conveyor belt
    stopConveyorBelt();
  }
}

bool isColorDetected(int sensor1Value, int sensor2Value) {
  // Adjust these thresholds based on calibration
  int threshold1 = 500;  // Set threshold for color detection on sensor 1
  int threshold2 = 500;  // Set threshold for color detection on sensor 2

  // Compare sensor values to thresholds
  return (sensor1Value > threshold1 && sensor2Value > threshold2);
}

void sortObject() {
  // Activate sorting mechanism (e.g., move the servo)
  digitalWrite(servoPin, HIGH);
  delay(500);  // Adjust delay based on sorting mechanism speed
  digitalWrite(servoPin, LOW);
}

void startConveyorBelt() {
  // Activate motor to start the conveyor belt
  digitalWrite(motorEnablePin, HIGH);
  digitalWrite(motorDirectionPin, HIGH);  // Adjust based on the motor direction
}

void stopConveyorBelt() {
  // Stop the conveyor belt
  digitalWrite(motorEnablePin, LOW);
}
