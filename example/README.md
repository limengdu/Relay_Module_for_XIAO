# Examples

ESPHome firmware for the Relay Add-On Module for XIAO. The module is controlled from **XIAO pin D1**; the GPIO number for D1 depends on the board.

## Board pin map

| Board | ESPHome example | Relay pin (D1) | ESPHome board | Framework |
| --- | --- | --- | --- | --- |
| XIAO ESP32-C3 | `relay_module_for_xiao_esp32c3.yaml` | GPIO3 | `esp32-c3-devkitm-1` | Arduino |
| XIAO ESP32-C6 | `relay_module_for_xiao_esp32c6.yaml` | GPIO1 | `esp32-c6-devkitc-1` | ESP-IDF |
| XIAO ESP32-S3 | `relay_module_for_xiao_esp32s3.yaml` | GPIO2 | `esp32-s3-devkitc-1` | Arduino |
| XIAO ESP32-C5 | `relay_module_for_xiao_esp32c5.yaml` | GPIO0 | `esp32-c5-devkitc-1` | ESP-IDF |

C5 D1 = GPIO0 is taken from the [Seeed XIAO ESP32-C5 pin map](https://wiki.seeedstudio.com/xiao_esp32c5_getting_started/) and the [arduino-esp32 `XIAO_ESP32C5` variant](https://github.com/espressif/arduino-esp32/blob/3.3.5/variants/XIAO_ESP32C5/pins_arduino.h) (`D1 = 0`). GPIO0 is not a boot strapping pin on ESP32-C5.

## Build ESPHome firmware (XIAO ESP32-C5)

ESP32-C5 in ESPHome uses the ESP-IDF framework (the Arduino framework is not available for this chip in ESPHome). Use **ESPHome 2025.11.5 or newer**.

```bash
esphome compile example/relay_module_for_xiao_esp32c5.yaml
esphome upload example/relay_module_for_xiao_esp32c5.yaml
```

After the first flash, the board raises a fallback Wi-Fi AP named `seeedstudio-relay-module`. Connect to it and open `192.168.4.1` to join your Home Assistant network.

## Arduino IDE / arduino-cli (XIAO ESP32-C5)

A minimal Arduino sketch is in `arduino/relay_module_for_xiao_esp32c5/`.

| Setting | Value |
| --- | --- |
| Arduino IDE board | `XIAO_ESP32C5` |
| FQBN | `esp32:esp32:XIAO_ESP32C5` |
| arduino-esp32 core | **3.3.5 or newer** (Seeed wiki; based on ESP-IDF 5.5.1+) |
| Flash | 8 MB (board default) |
| PSRAM | 8 MB present; not required for this sketch |

```bash
arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli core install esp32:esp32@3.3.5 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli compile --fqbn esp32:esp32:XIAO_ESP32C5 arduino/relay_module_for_xiao_esp32c5
```

In Arduino IDE: Boards Manager → install **esp32** 3.3.5 or newer → select **XIAO_ESP32C5**.
