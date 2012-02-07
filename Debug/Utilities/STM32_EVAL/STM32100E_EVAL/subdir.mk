################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval.c \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_cec.c \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_onenand.c \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_sram.c \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_ioe.c \
../Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_lcd.c 

OBJS += \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval.o \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_cec.o \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_onenand.o \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_sram.o \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_ioe.o \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_lcd.o 

C_DEPS += \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval.d \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_cec.d \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_onenand.d \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_fsmc_sram.d \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_ioe.d \
./Utilities/STM32_EVAL/STM32100E_EVAL/stm32100e_eval_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32_EVAL/STM32100E_EVAL/%.o: ../Utilities/STM32_EVAL/STM32100E_EVAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/STM32F10x_StdPeriph_Driver/inc" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/CoreSupport" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


