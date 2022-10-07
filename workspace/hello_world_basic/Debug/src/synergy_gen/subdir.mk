################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/synergy_gen/common_data.c \
../src/synergy_gen/hal_data.c \
../src/synergy_gen/main.c \
../src/synergy_gen/pin_data.c 

C_DEPS += \
./src/synergy_gen/common_data.d \
./src/synergy_gen/hal_data.d \
./src/synergy_gen/main.d \
./src/synergy_gen/pin_data.d 

OBJS += \
./src/synergy_gen/common_data.o \
./src/synergy_gen/hal_data.o \
./src/synergy_gen/main.o \
./src/synergy_gen/pin_data.o 


# Each subdirectory must supply rules for building sources it contributes
src/synergy_gen/%.o: ../src/synergy_gen/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_SYNERGY_ -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy_cfg/ssp_cfg/driver" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy/ssp/inc" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy/ssp/inc/bsp" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy/ssp/inc/driver/api" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/synergy/ssp/inc/driver/instances" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/src" -I"C:/Users/wesle/e2_studio/workspace/hello_world_basic/src/synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

