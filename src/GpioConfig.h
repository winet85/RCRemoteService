/*
 * GpioConfig.h
 *
 *  Created on: 2017. 4. 11.
 *      Author: JOON
 */

#ifndef RC_GPIOCONFIG_H_
#define SRC_GPIOCONFIG_H_

#define DC_MOTOR_WPI_GPIO1 				1 //Physical GPIO 12
#define DC_MOTOR_WPI_GPIO4 				4 //Physical GPIO 16
#define DC_MOTOR_WPI_GPIO5 				5 //Physical GPIO 18

#define DC_MOTOR_WPI_GPIO27 			27 //Physical GPIO 36
#define DC_MOTOR_WPI_GPIO28 			28 //Physical GPIO 38
#define DC_MOTOR_WPI_GPIO29 			29 //Physical GPIO 40


#define DC_MOTOR_WPI_SPEED_GPIO1		DC_MOTOR_WPI_GPIO4
#define DC_MOTOR_WPI_SPEED_GPIO2		DC_MOTOR_WPI_GPIO5

#define DC_MOTOR_WPI_STEERING_GPIO1 	DC_MOTOR_WPI_GPIO28
#define DC_MOTOR_WPI_STEERING_GPIO2 	DC_MOTOR_WPI_GPIO29

#define DC_MOTOR_WPI_SPEED_PWM  		DC_MOTOR_WPI_GPIO1
#define DC_MOTOR_WPI_STEERING_PWM  		DC_MOTOR_WPI_GPIO27
#define DC_MOTOR_WPI_PWMR 				100


#endif /* SRC_GPIOCONFIG_H_ */