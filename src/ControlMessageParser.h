/*
 * ControlMessageParser.h
 *
 *  Created on: 2017. 4. 19.
 *      Author: JOON
 */

#ifndef SRC_CONTROLMESSAGEPARSER_H_
#define SRC_CONTROLMESSAGEPARSER_H_

#include <stdint.h>
#include <string>
#include "RCRemoteError.h"

using namespace std;
class ControlData
{
public :
	ControlData();
	ControlData(bool forword, uint8_t speed, bool right, uint8_t steering );
	~ControlData();
	bool IsForword() const { return isForword; }
	void SetForword(bool forword) { this->isForword = forword; }
	bool IsRight() const { return isRight;}
	void SetRight(bool right) { this->isRight = right; }
	uint8_t GetSpeed() const {return mSpeed; }
	void SetSpeed(uint8_t speed) { this->mSpeed = speed; }
	uint8_t GetSteering() const { return mSteering; }
	void SetSteering(uint8_t steering) { this->mSteering = steering;}
	void update(ControlData data);

	string toString();

private :
	bool isRight;
	bool isForword;
	uint8_t mSpeed;
	uint8_t mSteering;
};

class ControlMessageParser
{
public :
	ControlMessageParser();
	~ControlMessageParser();
	int Init();
	int Clear();
	int Parse(void *data, ControlData *message);
private :
	bool created;
	bool inited;
};



#endif /* SRC_CONTROLMESSAGEPARSER_H_ */
