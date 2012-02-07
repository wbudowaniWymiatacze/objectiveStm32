################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval.c \
../Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nand.c \
../Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nor.c \
../Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_sram.c \
../Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_lcd.c 

OBJS += \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval.o \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nand.o \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nor.o \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_sram.o \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_lcd.o 

C_DEPS += \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval.d \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nand.d \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_nor.d \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_fsmc_sram.d \
./Utilities/STM32_EVAL/STM3210E_EVAL/stm3210e_eval_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32_EVAL/STM3210E_EVAL/%.o: ../Utilities/STM32_EVAL/STM3210E_EVAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/STM32F10x_StdPeriph_Driver/inc" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/CoreSupport" -I"/home/artur/eclipseProjects/cyclingEfficiency/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


