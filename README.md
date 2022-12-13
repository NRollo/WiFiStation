# ESP32 Wi-Fi Station and ADC2 Example

This example "merges" the wifi station example and the ADC2 example in order to test using wifi and the ADC2 on the ESP32-WROOM sequentially.
The example has the following flow:
1. Sample the ADC2 channel #0
2. Install the wifi driver and connect
3. Wait for wifi to "settle" (e.g. server communication would go here)
4. Stop wifi, de-init and cleanup
5. Repeat from 1.)

## How to use example

### Configure the project

Open the project configuration menu (`idf.py menuconfig`). 

In the `Example Configuration` menu:

* Set the Wi-Fi configuration.
    * Set `WiFi SSID`.
    * Set `WiFi Password`.


