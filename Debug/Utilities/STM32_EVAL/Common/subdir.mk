################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32_EVAL/Common/fonts.c \
../Utilities/STM32_EVAL/Common/stm32_eval_i2c_ee.c \
../Utilities/STM32_EVAL/Common/stm32_eval_i2c_tsensor.c \
../Utilities/STM32_EVAL/Common/stm32_eval_sdio_sd.c \
../Utilities/STM32_EVAL/Common/stm32_eval_spi_flash.c \
../Utilities/STM32_EVAL/Common/stm32_eval_spi_sd.c 

OBJS += \
./Utilities/STM32_EVAL/Common/fonts.o \
./Utilities/STM32_EVAL/Common/stm32_eval_i2c_ee.o \
./Utilities/STM32_EVAL/Common/stm32_eval_i2c_tsensor.o \
./Utilities/STM32_EVAL/Common/stm32_eval_sdio_sd.o \
./Utilities/STM32_EVAL/Common/stm32_eval_spi_flash.o \
./Utilities/STM32_EVAL/Common/stm32_eval_spi_sd.o 

C_DEPS += \
./Utilities/STM32_EVAL/Common/fonts.d \
./Utilities/STM32_EVAL/Common/stm32_eval_i2c_ee.d \
./Utilities/STM32_EVAL/Common/stm32_eval_i2c_tsensor.d \
./Utilities/STM32_EVAL/Common/stm32_eval_sdio_sd.d \
./Utilities/STM32_EVAL/Common/stm32_eval_spi_flash.d \
./Utilities/STM32_EVAL/Common/stm32_eval_spi_sd.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32_EVAL/Common/%.o: ../Utilities/STM32_EVAL/Common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/STM32F10x_StdPeriph_Driver/inc" -I"/home/artur/eclipseProjects/cyclingEfficiency/Utilities/STM32_EVAL" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/CoreSupport" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


