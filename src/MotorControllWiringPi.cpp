/*
 * MotorControllWiringPi.cpp
 *
 *  Created on: 2017. 4. 12.
 *      Author: JOON
 */
#include <iostream>

#include <wiringPi.h>
#include <softPwm.h>

#include "MotorControllWiringPi.h"
#include "GpioConfig.h"


MotorControllWiringPi::MotorControllWiringPi()
	:created(false),inited(false)
{
	std::cout << "Created MotorControllWiringPi" << std::endl;
	created = true;
}

MotorControllWiringPi::~MotorControllWiringPi()
{
	std::cout << "Destroy MotorControllWiringPi" << std::endl;
	created = false;
}

int MotorControllWiringPi::Init()
{
	std::cout << "MotorControllWiringPi::Init" << std::endl;
	if(!created)
		return ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_CREATED;

	if(wiringPiSetup() < 0){
		return ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_GPIO_INIT;
	}

	// Set Gpio for Forword, Rewind
	pinMode(DC_MOTOR_WPI_SPEED_PWM,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_BAL);
	pwmSetRange(DC_MOTOR_WPI_PWMR);
	pinMode(DC_MOTOR_WPI_SPEED_GPIO1,OUTPUT);
	pinMode(DC_MOTOR_WPI_SPEED_GPIO2,OUTPUT);
	// Set Gpio for steering
	pinMode(DC_MOTOR_WPI_STEERING_PWM, OUTPUT);
	pinMode(DC_MOTOR_WPI_STEERING_GPIO1,OUTPUT);
	pinMode(DC_MOTOR_WPI_STEERING_GPIO2,OUTPUT);
	std::cout << "init Gpio Mode" << std::endl;
	if(softPwmCreate(DC_MOTOR_WPI_STEERING_PWM, 0, DC_MOTOR_WPI_PWMR) != 0){
		return ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_SPWM_INIT;
	}
	SetSpeed(0, true);
	SetSteering(0, true);
	std::cout << "MotorControllWiringP::Init end" << std::endl;
	inited = true;
	return 0;
}

int MotorControllWiringPi::Clear()
{

	if(!inited && !created)
		return ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_CLEAR;

	std::cout << "MotorControllWiringP::Clear" << std::endl;
	SetSpeed(0, true);
	SetSteering(0, true);


	if(digitalRead(DC_MOTOR_WPI_SPEED_GPIO1) == HIGH){
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO1, LOW);
	}

	if(digitalRead(DC_MOTOR_WPI_SPEED_GPIO2) == HIGH){
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO2, LOW);
	}

	if(digitalRead(DC_MOTOR_WPI_STEERING_GPIO1) == HIGH){
			digitalWrite(DC_MOTOR_WPI_STEERING_GPIO1, LOW);
	}

	if(digitalRead(DC_MOTOR_WPI_STEERING_GPIO2) == HIGH){
			digitalWrite(DC_MOTOR_WPI_STEERING_GPIO2, LOW);
	}

	softPwmStop(DC_MOTOR_WPI_STEERING_PWM);

	inited = false;
	return 0;
}

int MotorControllWiringPi::SetSpeed(uint16_t speed, bool isForward)
{ // speed range (0 ~ 100)

	if(!speed){ // Speed equal to 0
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO1, false);
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO2, false);
	}else{
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO1, isForward);
		digitalWrite(DC_MOTOR_WPI_SPEED_GPIO2, !isForward);
	}

	pwmWrite(DC_MOTOR_WPI_SPEED_PWM, speed / 100 * DC_MOTOR_WPI_PWMR);
	std::cout << "MotorControllWiringPi::Set Speed" << std::endl;
	std::cout << "DC_MOTOR_WPI_SPEED_GPIO1(" << digitalRead(DC_MOTOR_WPI_SPEED_GPIO1) << ")" << std::endl;
	std::cout << "DC_MOTOR_WPI_SPEED_GPIO2(" << digitalRead(DC_MOTOR_WPI_SPEED_GPIO2) << ")" << std::endl;
	std::cout << "DC_MOTOR_WPI_SPEED_PWM(" << speed << ")" << std::endl;
	return 0;
}

int MotorControllWiringPi::SetSteering(uint16_t angle, bool isRight)
{


	digitalWrite(DC_MOTOR_WPI_STEERING_GPIO1, isRight);
	digitalWrite(DC_MOTOR_WPI_STEERING_GPIO2, !isRight);

	softPwmWrite(DC_MOTOR_WPI_STEERING_PWM, angle / 100 * DC_MOTOR_WPI_PWMR);
	std::cout << "MotorControllWiringPi::Set Steering" << std::endl;
	std::cout << "DC_MOTOR_WPI_GPIO0(" << digitalRead(DC_MOTOR_WPI_STEERING_GPIO1) << ")" << std::endl;
	std::cout << "DC_MOTOR_WPI_GPIO2(" << digitalRead(DC_MOTOR_WPI_STEERING_GPIO2) << ")" << std::endl;
	std::cout << "DC_MOTOR_WPI_STEERING_PWM(" << angle << std::endl;
	return 0;
}



