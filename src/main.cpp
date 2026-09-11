#include <Arduino.h>

#define STATUS_LED 2  // Onboard LED pin.

void setup() {
    Serial.begin(115200);

    pinMode(STATUS_LED, OUTPUT);
}

void loop() {
    // Blink the LED.
    digitalWrite(STATUS_LED, HIGH);
    delay(1000);

    digitalWrite(STATUS_LED, LOW);
    delay(1000);
}