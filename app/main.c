#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

// Simple task function
void vTaskFunction(void *pvParameters) {
    while (1) {
        (void) pvParameters;
        printf("Hello, FreeRTOS!\n");
        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1 second
    }
}

int main(void) {
    // Create a simple task
    xTaskCreate(vTaskFunction, "Task1", configMINIMAL_STACK_SIZE, NULL, 1, 1, NULL);
    
    // Start the scheduler
    vTaskStartScheduler();
    
    // If execution reaches here, it means there was insufficient heap memory
    while (1);
}
