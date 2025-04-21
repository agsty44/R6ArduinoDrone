void setup() {
    //Disengage break pins.
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);

    //Set direction pins
    int leftDir = 12;
    int rightDir = 11;
    pinMode(leftDir, OUTPUT);
    pinMode(rightDir, OUTPUT);
}

void loop() {
    
}