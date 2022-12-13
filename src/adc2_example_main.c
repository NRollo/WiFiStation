/* ADC2 Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_system.h"
#include "esp_log.h"

#define ADC2_EXAMPLE_CHANNEL ADC2_CHANNEL_0

static const char *TAG = "ADC2";

static const adc_bits_width_t width = ADC_WIDTH_BIT_12;

void ADC_main(void)
{
    int     read_raw;
    esp_err_t r;

    gpio_num_t adc_gpio_num;

    r = adc2_pad_get_io_num( ADC2_EXAMPLE_CHANNEL, &adc_gpio_num );
    assert( r == ESP_OK );

    ESP_LOGI(TAG, "ADC2 channel %d @ GPIO %d", ADC2_EXAMPLE_CHANNEL, adc_gpio_num);

    //be sure to do the init before using adc2.
    ESP_LOGI(TAG, "adc2_init...");
    adc2_config_channel_atten( ADC2_EXAMPLE_CHANNEL, ADC_ATTEN_11db );

    vTaskDelay(2 * portTICK_PERIOD_MS);

    ESP_LOGI(TAG, "start conversion.");
    r = adc2_get_raw( ADC2_EXAMPLE_CHANNEL, width, &read_raw);
    if ( r == ESP_OK ) {
        ESP_LOGI(TAG, "Raw ADC data: %d", read_raw );
    } else if ( r == ESP_ERR_INVALID_STATE ) {
        ESP_LOGE(TAG, "%s: ADC2 not initialized yet.", esp_err_to_name(r));
    } else if ( r == ESP_ERR_TIMEOUT ) {
        //This can not happen in this example. But if WiFi is in use, such error code could be returned.
        ESP_LOGE(TAG, "%s: ADC2 is in use by Wi-Fi.", esp_err_to_name(r));
    } else {
        ESP_LOGE(TAG, "%s\n", esp_err_to_name(r));
    }

    vTaskDelay( 2 * portTICK_PERIOD_MS );
}
