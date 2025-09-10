/* --------------------------------------------------------------
   Application: 01 - Rev1
   Release Type: Baseline Multitask Possible Solution
   Class: Real Time Systems - Su 2025
   AI Use: Commented inline -- None
---------------------------------------------------------------*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2  // Using GPIO2 for the LED

// Task to blink an LED at 2 Hz (500 ms period: 250 ms ON, 250 ms OFF)
// Our toaster uses an LED to toast bread (probably has to do this forever to actually toast the bread :) 
void blink_task(void *pvParameters) {
    bool led_on = false;
    TickType_t currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
    TickType_t previousTime = 0;

    while (1) {
        previousTime = currentTime;
        currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
        gpio_set_level(LED_PIN, led_on);  // Set LED pin high or low based on led_status flag;
        led_on = !led_on;  // toggle state for next loop 
        printf("Beacon period = %lu\n", currentTime - previousTime);
        vTaskDelay(pdMS_TO_TICKS(250)); // Delay for 250 ms using MS to Ticks Function vs alternative which is MS / ticks per ms
        vTaskDelay(pdMS_TO_TICKS(50)); // Delay for 50 ms to test blinking frequency
    }
    vTaskDelete(NULL); // We'll never get here; tasks run forever
}

// Task to print a message every 10000 ms (10 seconds)
void print_task(void *pvParameters) {
    TickType_t currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
    TickType_t previousTime = 0;
    while (1) {
        previousTime = currentTime;
        currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
        // Prints a periodic message based on a toaster thematic area. Output a timestamp (ms) and period (ms)
        printf("Telemetry OK [period = %lu]!\n", currentTime - previousTime);

        vTaskDelay(pdMS_TO_TICKS(20000)); // Delay for 20000 ms
    }
    vTaskDelete(NULL); // We'll never get here; tasks run forever
}

void app_main() {
    // Initialize LED GPIO     
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    
    // Instantiate/ Create tasks: 
    // . pointer to task function, 
    // . descriptive name, [has a max length; located in the FREERTOS_CONFIG.H]
    // . stack depth, 
    // . parameters [optional] = NULL 
    // . priority [0 = low], 
    // . pointer referencing this created task [optional] = NULL
    // Learn more here https://www.freertos.org/Documentation/02-Kernel/04-API-references/01-Task-creation/01-xTaskCreate
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 1, NULL);
    xTaskCreate(print_task, "Print Task", 2048, NULL, 2, NULL);

}
