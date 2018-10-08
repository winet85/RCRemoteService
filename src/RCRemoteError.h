/*
 * RCRemoteError.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: JOON
 */

#ifndef SRC_RCREMOTEERROR_H_
#define SRC_RCREMOTEERROR_H_

#include <stdint.h>

#define ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_CREATED -1
#define ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_INIT -2
#define ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_CLEAR -3
#define ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_GPIO_INIT -4
#define ERROR_CLASS_MOTOR_CONTROLL_WIRINGPI_SPWM_INIT -5

#define ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CREATED -10
#define ERROR_CLASS_CONTROLL_MESSAGE_THREAD_INIT -11
#define ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CLEAR -12
#define ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CREATE -13

#define ERROR_CLASS_CONTROLMESSAGE_PARSER_CREATED -20
#define ERROR_CLASS_CONTROLMESSAGE_PARSER_INIT -21
#define ERROR_CLASS_CONTROLMESSAGE_PARSER_CLEAR -22
#define ERROR_CLASS_CONTROLMESSAGE_PARSER_ARGUMENT_IS_NULL -23

#define ERROR_CLASS_UDPTRANSMITTER_CREATED -20
#define ERROR_CLASS_UDPTRANSMITTER_INIT -21
#define ERROR_CLASS_UDPTRANSMITTER_CLEAR -22
#define ERROR_CLASS_UDPTRANSMITTER_SOCKET_CREATE -23
#define ERROR_CLASS_UDPTRANSMITTER_SOCKET_BIND -24
#define ERROR_CLASS_UDPTRANSMITTER_SOCKET_IS_NULL -25
#define ERROR_CLASS_UDPTRANSMITTER_SOCKET_RECV -26
#define ERROR_CLASS_UDPTRANSMITTER_SEND -27

#endif /* SRC_RCREMOTEERROR_H_ */
