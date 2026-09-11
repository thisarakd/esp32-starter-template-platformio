#include <Arduino.h>

// Standard onboard status LED for ESP32 WROOM-32 DevKits
#define STATUS_LED 2

void setup() {
    Serial.begin(115200);
    delay(1000);

    pinMode(STATUS_LED, OUTPUT);
    Serial.println();
    Serial.println(F("===================================="));
    Serial.println(F("[STATUS] ESP32 WROOM-32 Booted Cleanly"));
    Serial.printf("[INFO]   Free Heap: %u bytes\n", ESP.getFreeHeap());
    Serial.printf("[INFO]   Chip Rev : %u\n", ESP.getChipRevision());
    Serial.println(F("===================================="));
}

void loop() {
    digitalWrite(STATUS_LED, HIGH);
    Serial.println(F("[HEARTBEAT] Tick - LED ON"));
    delay(1000);

    digitalWrite(STATUS_LED, LOW);
    Serial.println(F("[HEARTBEAT] Tock - LED OFF"));
    delay(1000);
}