/*
 * ControlMessageParser.cpp
 *
 *  Created on: 2017. 4. 19.
 *      Author: JOON
 */
#include <sstream>
#include <stdio.h>
#include <arpa/inet.h>
#include "ControlMessageParser.h"
#include "ControlMeaage.h"


ControlMessageParser::ControlMessageParser()
	: created(true), inited(false)
{

}
ControlMessageParser::~ControlMessageParser(){
	created = false;
}

int ControlMessageParser::Init()
{
	if(!created)
		return ERROR_CLASS_CONTROLMESSAGE_PARSER_CREATED;

	inited = true;
	return 0;
}

int ControlMessageParser::Clear()
{
	if(!created)
		return ERROR_CLASS_CONTROLMESSAGE_PARSER_CREATED;
	if(!inited)
		return ERROR_CLASS_CONTROLMESSAGE_PARSER_INIT;

	inited = false;
	return 0;
}

int ControlMessageParser::Parse(void *data, ControlData *message)
{
	struct DriveControlMeaage *temp = (struct DriveControlMeaage *)data;

	if(temp == 0){
		return ERROR_CLASS_CONTROLMESSAGE_PARSER_ARGUMENT_IS_NULL;
	}

//	printf("size = %d (====>", sizeof(struct DriveControlMeaage));
//			for (int count = 0; count < sizeof(struct DriveControlMeaage); count++) {
//
//				printf("0x%X ", *((char *) (data + count)));
//			}
//			printf(")\n");
	message->SetRight((bool) temp -> isRight);
	message->SetForword((bool) temp -> isForword);
	message->SetSpeed(temp -> speed);
	message->SetSteering(temp -> steering);

	return 0;
}

ControlData::ControlData(){
	this->isForword = false;
	this->mSpeed = 0;
	this->isRight = false;
	this->mSteering = 0;
}
ControlData::~ControlData(){

}
ControlData::ControlData(bool forword, uint8_t speed, bool right, uint8_t steering )
{
		this->isForword = forword;
		this->mSpeed = speed;
		this->isRight = right;
		this->mSteering = steering;
}

string ControlData::toString()
{
	stringstream ss;

	ss << "===============>Control Data<===============\n";
	ss << (this -> isForword ? "Forward" : "Rewind");
	ss << " Speed(" << (int)this -> mSpeed <<"), ";
	ss << (this -> isRight ? "Right" : "Left,");
	ss << " Steering(" << (int)this -> mSteering <<")\n";
	return ss.str();
}



