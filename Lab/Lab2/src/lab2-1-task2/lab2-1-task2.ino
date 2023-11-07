/*************************Command**************************/

// AT+CAPPSKEY?  ->  FAFF
// AT+CNWKSKEY?  ->  FAFF

// Master
// AT+CPT="TXPP,1,0100,923.000,20,2,5,1,0,1,0,0035,1234"

// Slave
// AT+CPT="TXPP,0,0010,923.000,00,2,5,1,0,1,0,0100,1234"

/**********************************************************/

char Data;

void setup() {
    // Setup serial port baud rate.
    Serial.begin(9600);

    // Setup 6509 baud rate.
    Serial1.begin(9600);

    // Wait 1 second for init.
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
