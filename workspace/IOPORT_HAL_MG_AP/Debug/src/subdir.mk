################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c \
../src/ioport_hal.c 

C_DEPS += \
./src/hal_entry.d \
./src/ioport_hal.d 

OBJS += \
./src/hal_entry.o \
./src/ioport_hal.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy_cfg/ssp_cfg/driver" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy/ssp/inc" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy/ssp/inc/bsp" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy/ssp/inc/driver/api" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/synergy/ssp/inc/driver/instances" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/src" -I"C:/Users/wesle/e2_studio/workspace_3/IOPORT_HAL_MG_AP/src/synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

