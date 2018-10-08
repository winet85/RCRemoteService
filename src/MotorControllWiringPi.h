/*
 * MotorControllWiringPi.h
 *
 *  Created on: 2017. 4. 11.
 *      Author: JOON
 */

#ifndef RCREMOTESERVICE_SRC_MOTORCONTROLLWIRINGPI_H_
#define RCREMOTESERVICE_SRC_MOTORCONTROLLWIRINGPI_H_

#include "IMotorControll.h"
#include "RCRemoteError.h"

class MotorControllWiringPi : public IMotorControll{

public :
	MotorControllWiringPi();
	~MotorControllWiringPi();
	int Init();
    int Clear();
    int SetSpeed(uint16_t speed, bool isForward);
    int SetSteering(uint16_t angle, bool isRight);


private :
    bool inited;
    bool created;
};




#endif /* RCREMOTESERVICE_SRC_MOTORCONTROLLWIRINGPI_H_ */
