################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/startup_S7G2.c \
../synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/system_S7G2.c 

C_DEPS += \
./synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/startup_S7G2.d \
./synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/system_S7G2.d 

OBJS += \
./synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/startup_S7G2.o \
./synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/system_S7G2.o 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/%.o: ../synergy/ssp/src/bsp/cmsis/Device/RENESAS/S7G2/Source/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_SYNERGY_ -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy_cfg/ssp_cfg/driver" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy/ssp/inc" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy/ssp/inc/bsp" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy/ssp/inc/driver/api" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/synergy/ssp/inc/driver/instances" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/src" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic_modificado/src/synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

