
#define configUSE_16_BIT_TICKS 0  // Or use configTICK_TYPE_WIDTH_IN_BITS instead
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 5  // Set to a reasonable priority value
#define configMINIMAL_STACK_SIZE 128  // Set this according to your system requirements
#define configMAX_PRIORITIES 5  // Number of task priorities
#define configUSE_PREEMPTION 1  // Enable preemption (1 for preemption)
#define configUSE_IDLE_HOOK 0  // Set to 1 if you want to use idle hook
#define configUSE_TICK_HOOK 0  // Set to 1 if you want to use tick hook
#define configTOTAL_HEAP_SIZE 4096  // Set to a reasonable value
#define configCPU_CLOCK_HZ                       ( ( unsigned long ) 25000000 )
#define configTICK_RATE_HZ                       ( ( TickType_t ) 1000 )
#define INCLUDE_vTaskDelay 1  // Include vTaskDelay
