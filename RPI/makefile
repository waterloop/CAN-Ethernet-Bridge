##################################################################################
# variables

TARGET := main
OPT := -Os
BUILD_DIR = build

CC := gcc
AS := gcc -x assembler-with-cpp
CP := objcopy
SZ := size

HEX := $(CP) -O ihex
BIN := $(CP) -O binary -S

##################################################################################

##################################################################################
# sources
C_SOURCES := $(shell find ./src -name "*.c")
# C_INCLUDES := \
# -I ./...

C_FLAGS := $(C_INCLUDES) $(OPT) -Wall

ASM_SOURCES := $(shell find ./src -name "*.s")
# ASM_INCLUDES := \
# -I ./...

ASM_FLAGS := $(ASM_INCLUDES) $(OPT) -Wall

##################################################################################


##################################################################################
# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c makefile | $(BUILD_DIR) 
	$(CC) -c $(C_FLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s makefile | $(BUILD_DIR)
	$(AS) -c $(ASM_FLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) makefile
	$(CC) $(OBJECTS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

clean:
	rm -rf $(BUILD_DIR)

##################################################################################
