/*
 * Minimal relay control for Seeed Studio XIAO ESP32-C5 + Relay Add-On Module.
 *
 * Board: XIAO_ESP32C5
 * FQBN:  esp32:esp32:XIAO_ESP32C5
 * Core:  arduino-esp32 3.3.5 or newer (ESP-IDF 5.5.1+)
 *
 * The relay module is driven from XIAO pin D1.
 * On XIAO ESP32-C5, D1 is GPIO0:
 *   - Seeed wiki pin map: https://wiki.seeedstudio.com/xiao_esp32c5_getting_started/
 *   - arduino-esp32 variant: variants/XIAO_ESP32C5/pins_arduino.h (D1 = 0)
 *
 * Drive D1 HIGH to turn the relay on, LOW to turn it off.
 */

const int relayPin = D1;  // GPIO0 on XIAO ESP32-C5

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(relayPin, HIGH);
  Serial.println("Relay ON");
  delay(1000);

  digitalWrite(relayPin, LOW);
  Serial.println("Relay OFF");
  delay(1000);
}
