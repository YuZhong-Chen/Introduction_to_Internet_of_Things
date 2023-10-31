#include <DHT22_lab.h>

// define pin data ( Connect DHT22 at pin 2 )
#define pinDATA 2

/**
 * For more details on the DHT22, please refer to the data sheet (located in the doc folder).
 */
DHT22 dht22(pinDATA);

float DHT22::getHumidity() {
    // read data and return whether read success or not
    bool valid = dht22.readFromSensor();
    if (!valid) return 0;

    uint64_t rawData = dht22.getRawData();
    String rawStr = dht22.getRawStrData();

    // The first 24 bits of the raw data need to be discarded.
    // And the next 16 bits are the humidity, it needs to be converted to float, also divided by 10.
    int16_t Humidity = ((rawData << 24) >> 48);
    float returnVal = (float)Humidity / 10.0;

    return returnVal;
}

float DHT22::getTemperature() {
    // read data and return whether read success or not
    bool valid = dht22.readFromSensor();
    if (!valid) return 0;

    uint64_t rawData = dht22.getRawData();
    String rawStr = dht22.getRawStrData();

    // The first 40 bits of the raw data need to be discarded.
    // And the next 16 bits are the temperature, it needs to be converted to float, also divided by 10, same as humidity.
    int16_t Tem = ((rawData << 40) >> 48);
    float returnVal = (float)Tem / 10.0;

    return returnVal;
}

void setup() {
    // Setup the serial port.
    Serial.begin(9600);
}

void loop() {
    // Get the temperature and humidity.
    float t = dht22.getTemperature();
    float h = dht22.getHumidity();

    // If the read failed, print error message.
    if (dht22.getLastError() != dht22.OK)
        Serial.println(dht22.getLastError());

    // Print the temperature and humidity.
    Serial.print("h=");
    Serial.print(h, 1);
    Serial.print("\t");
    Serial.print("t=");
    Serial.println(t, 1);

    // Wait 1 second.
    delay(1000);
}
