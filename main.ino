/*

PIN NUMBERS:

LEFT MOTOR (CHANNEL A) : BRAKES PIN 9, DIRECTION PIN 12, SPEED PIN 3
RIGHT MOTOR (CHANNEL B) : BRAKES PIN 8, DIRECTION PIN 11, SPEED PIN 8

*/

//GLOBAL VARS
int leftDirPin = 12;
int rightDirPin = 11;

int leftSpeedPin = 3;
int rightSpeedPin = 8;

void setup() {
    //Disengage brake pins.
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);

    //Set direction pins
    pinMode(leftDirPin, OUTPUT);
    pinMode(rightDirPin, OUTPUT);

    //Set speed pins
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);
}

void loop() {
    //Read axis values
    //TODO: IMPLEMENT USB SERIAL AND PS4 CONTROLLER LIBRARIES.
    int leftStickYAxis;
    int rightStickYAxis;

    //Do a check to set pin dirs.
    if (leftStickYAxis > 0) {
	digitalWrite(leftDirPin, HIGH);
    } else {
        digitalWrite(leftDirPin, LOW);
    }

    if (rightStickYAxis > 0) {
        digitalWrite(rightDirPin, HIGH);
    } else {
        digitalWrite(rightDirPin, LOW);
    }

    //Calculate the motor speed (this needs to solve to a value 0 -> 255)
    int leftMotorSpeed = abs(leftStickYAxis) * 255;
    int rightMotorSpeed = abs(rightStickYAxis) * 255;

    //Now we need to output these values to the motors
    analogWrite(leftSpeedPin, leftMotorSpeed);
    analogWrite(rightSpeedPin, rightMotorSpeed);
}
