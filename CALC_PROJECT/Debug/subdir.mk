################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CALC.c \
../DIO_prog.c \
../KPD_prog.c \
../LCD_Prog.c \
../main.c 

OBJS += \
./CALC.o \
./DIO_prog.o \
./KPD_prog.o \
./LCD_Prog.o \
./main.o 

C_DEPS += \
./CALC.d \
./DIO_prog.d \
./KPD_prog.d \
./LCD_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


