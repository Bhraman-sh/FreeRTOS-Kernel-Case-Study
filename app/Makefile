
# Output directory and final image
OUTPUT_DIR := ./output
IMAGE := $(OUTPUT_DIR)/FreeRTOSDemo.out

# FreeRTOS source root (adjust this to your FreeRTOS source location)
FREERTOS_ROOT = $(HOME)/FreeRTOS-Kernel-Case-Study
KERNEL_PORT_DIR += $(FREERTOS_ROOT)/portable/GCC/ARM_CM3
# Compiler settings for ARM Cortex-M3
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
SIZE = arm-none-eabi-size

# Compiler Flags
CFLAGS += -ffreestanding -mthumb -mcpu=cortex-m3
CFLAGS += -Wall -Wextra -g3 -Os -ffunction-sections -fdata-sections
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT $@
CFLAGS += $(INCLUDE_DIRS)

# Linker Flags
LDFLAGS = -T ./mps2_m3.ld
LDFLAGS += -Xlinker -Map=$(OUTPUT_DIR)/FreeRTOSDemo.map
LDFLAGS += -Xlinker --gc-sections
LDFLAGS += -nostartfiles
LDFLAGS += -specs=nano.specs -specs=nosys.specs

VPATH += $(FREERTOS_ROOT) $(KERNEL_PORT_DIR) $(FREERTOS_ROOT)/portable/MemMang

# Include directories:
# Add the FreeRTOS kernel include directory and the application include directory
INCLUDE_DIRS += -I$(FREERTOS_ROOT)/include \
                -I$(FREERTOS_ROOT)/portable/GCC/ARM_CM3 \
                -I./include  # This ensures FreeRTOSConfig.h is found

# Source files (kernel, port, and your application)
SOURCE_FILES += $(FREERTOS_ROOT)/tasks.c
SOURCE_FILES += $(FREERTOS_ROOT)/list.c
SOURCE_FILES += $(FREERTOS_ROOT)/queue.c
SOURCE_FILES += $(FREERTOS_ROOT)/timers.c
SOURCE_FILES += $(FREERTOS_ROOT)/event_groups.c
SOURCE_FILES += $(FREERTOS_ROOT)/stream_buffer.c
SOURCE_FILES += $(FREERTOS_ROOT)/IntQueueTimer.c
SOURCE_FILES += $(FREERTOS_ROOT)/portable/MemMang/heap_4.c
SOURCE_FILES += $(FREERTOS_ROOT)/portable/GCC/ARM_CM3/port.c
SOURCE_FILES += ./startup_gcc.c  # Startup file for your MCU
SOURCE_FILES += ./main.c         # Your application code

# Create object and dependency lists
OBJS = $(SOURCE_FILES:%.c=%.o)
OBJS_NO_PATH = $(notdir $(OBJS))
OBJS_OUTPUT = $(OBJS_NO_PATH:%.o=$(OUTPUT_DIR)/%.o)
DEP_FILES := $(SOURCE_FILES:%.c=$(OUTPUT_DIR)/%.d)
DEP_FILES_NO_PATH = $(notdir $(DEP_FILES))
DEP_OUTPUT = $(DEP_FILES_NO_PATH:%.d=$(OUTPUT_DIR)/%.d)

all: $(IMAGE)

# Pattern rule for object files
%.o : %.c
$(OUTPUT_DIR)/%.o : %.c $(OUTPUT_DIR)/%.d Makefile
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(IMAGE): ./mps2_m3.ld $(OBJS_OUTPUT) Makefile
	@echo ""
	@echo "--- Final linking ---"
	$(LD) $(CFLAGS) $(LDFLAGS) $(OBJS_OUTPUT) -o $(IMAGE)
	$(SIZE) $(IMAGE)

$(DEP_OUTPUT):
include $(wildcard $(DEP_OUTPUT))

clean:
	rm -f $(IMAGE) $(OUTPUT_DIR)/FreeRTOSDemo.map $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/*.d

.PHONY: all clean
