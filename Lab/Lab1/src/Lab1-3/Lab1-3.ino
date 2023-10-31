const int lebPin = 7;
const int buttonPin = 6;

void setup() {
    // Setup the pin modes.
    pinMode(lebPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // If the button is pressed, turn on the LED.
    // Otherwise, turn off the LED.
    if (digitalRead(buttonPin) == HIGH) {
        digitalWrite(lebPin, HIGH);
    } else {
        digitalWrite(lebPin, LOW);
    }
}
