char Data;

// AT+CAPPSKEY?  ->  FAFF
// AT+CNWKSKEY?  ->  FAFF

void setup() {
    // Setup serial port baud rate
    Serial.begin(9600);

    // Setup 6509 baud rate
    Serial1.begin(9600);

    delay(1000);
}

void loop() {
    // Read data from Serial port.
    if (Serial.available()) {
        Data = Serial.read();
        Serial1.print(Data);
    }

    // Read data from 6509.
    if (Serial1.available()) {
        Data = Serial1.read();
        Serial.print(Data);
    }
}
