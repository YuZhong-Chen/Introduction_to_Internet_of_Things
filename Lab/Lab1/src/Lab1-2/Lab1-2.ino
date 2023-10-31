void setup() {
    // Initialize serial communication at 9600.
    Serial.begin(9600);
    Serial1.begin(9600);
}

int len = 0;

void loop() {
    // Read from other arduino.
    len = 0;
    String Rev;
    while (Serial1.available()) {
        Rev += (char)Serial1.read();
        len += 1;
    }

    // If there is data, print it on the serial monitor.
    if (len > 0) {
        Serial.print("Rev:");
        Rev.toUpperCase();
        Serial.println(Rev);
    }

    // Read from the serial monitor.
    len = 0;
    String Send;
    while (Serial.available()) {
        Send += (char)Serial.read();
        len += 1;
    }

    // If there is data, send it to the other arduino.
    if (len > 0) {
        Serial1.print("Send:");
        Send.toUpperCase();
        Serial1.println(Send);
    }
}
