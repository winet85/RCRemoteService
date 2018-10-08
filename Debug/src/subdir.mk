################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ControlMessageParser.cpp \
../src/ControllMeaageThread.cpp \
../src/MotorControllWiringPi.cpp \
../src/RCRemoteService.cpp \
../src/UdpTransmitter.cpp 

OBJS += \
./src/ControlMessageParser.o \
./src/ControllMeaageThread.o \
./src/MotorControllWiringPi.o \
./src/RCRemoteService.o \
./src/UdpTransmitter.o 

CPP_DEPS += \
./src/ControlMessageParser.d \
./src/ControllMeaageThread.d \
./src/MotorControllWiringPi.d \
./src/RCRemoteService.d \
./src/UdpTransmitter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -fpermissive -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


