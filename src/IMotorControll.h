/*
 * IMotorControll.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: JOON
 */

#ifndef SRC_IMOTORCONTROLL_H_
#define SRC_IMOTORCONTROLL_H_

#include "RCRemoteError.h"
class IMotorControll {

public :

	virtual int Init() = 0;
	virtual int Clear() = 0;
	virtual int SetSpeed(uint16_t speed, bool isForward) = 0;
	virtual int SetSteering(uint16_t angle, bool isRight) = 0;


};



#endif /* SRC_IMOTORCONTROLL_H_ */
