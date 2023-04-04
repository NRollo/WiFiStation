# ESP32 Wi-Fi Station and ADC2 Example

This example "merges" the wifi station example and the ADC2 example in order to test using wifi and the ADC2 on e.g. the ESP32-WROOM sequentially. As the ADC2 is "disabled" when the WiFi driver is installed and configured, it is only possible to use the two features one at a time if both features are needed in the application - meaning that the WiFi driver must be disconnected and uninstalled for the ADC2 to work.

The example has the following flow:
1. Sample the ADC2 channel #0
2. Install the wifi driver and connect
3. Wait for wifi to "settle" (e.g. server communication would go here)
4. Stop wifi, de-init and cleanup
5. Repeat from 1.)

(See the README.md file in the upper level 'examples' directory for more information about examples.)

(Based on ESP-IDF version 4.4.2)

## How to use example

### Configure the project

Open the project configuration menu (`idf.py menuconfig`). 

In the `Example Configuration` menu:

* Set the Wi-Fi configuration.
    * Set `WiFi SSID`.
    * Set `WiFi Password`.


