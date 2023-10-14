################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dio_Mod/Dio.c 

OBJS += \
./MCAL/Dio_Mod/Dio.o 

C_DEPS += \
./MCAL/Dio_Mod/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio_Mod/%.o: ../MCAL/Dio_Mod/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


