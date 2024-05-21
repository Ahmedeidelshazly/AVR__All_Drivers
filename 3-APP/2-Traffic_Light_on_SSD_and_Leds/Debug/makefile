################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Traffic_Light_on_SSD_and_Leds.lss \

FLASH_IMAGE += \
Traffic_Light_on_SSD_and_Leds.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Traffic_Light_on_SSD_and_Leds.elf secondary-outputs

# Tool invocations
Traffic_Light_on_SSD_and_Leds.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Traffic_Light_on_SSD_and_Leds.map -mmcu=atmega32 -o "Traffic_Light_on_SSD_and_Leds.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Traffic_Light_on_SSD_and_Leds.lss: Traffic_Light_on_SSD_and_Leds.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Traffic_Light_on_SSD_and_Leds.elf  >"Traffic_Light_on_SSD_and_Leds.lss"
	@echo 'Finished building: $@'
	@echo ' '

Traffic_Light_on_SSD_and_Leds.hex: Traffic_Light_on_SSD_and_Leds.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Traffic_Light_on_SSD_and_Leds.elf  "Traffic_Light_on_SSD_and_Leds.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Traffic_Light_on_SSD_and_Leds.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Traffic_Light_on_SSD_and_Leds.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Traffic_Light_on_SSD_and_Leds.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
