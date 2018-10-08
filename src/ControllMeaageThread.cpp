/*
 * ControllMeaageThread.cpp
 *
 *  Created on: 2017. 4. 18.
 *      Author: JOON
 */
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#include "ControllMeaageThread.h"
#include "ControlMeaage.h"
#include "Ipv4Address.h"

static ControlData sCntMsg;

ControllMessageThread::ControllMessageThread()
	:created(true), inited(false), pControllTh(0), isRunning(false), mSrcAddr("",0), mDstAddr("",0)

{

}
ControllMessageThread::ControllMessageThread(string myip, uint16_t myport, string detip, uint16_t dstport)
	: created(true), inited(false), pControllTh(0), isRunning(false), mSrcAddr(myip,myport), mDstAddr(detip,dstport)
{

}

ControllMessageThread::~ControllMessageThread()
{
	created = false;
}

int ControllMessageThread::Init() {

	if (!created)
		return ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CREATED;

	inited = true;
	return 0;
}

int ControllMessageThread::Clear() {
	if (!inited)
		return ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CLEAR;

	inited = false;
	return 0;
}

int ControllMessageThread::Start() {
	if (!inited)
		return ERROR_CLASS_CONTROLL_MESSAGE_THREAD_INIT;

	int status = 0;

	if (!isRunning && pControllTh == 0) {

		if ((status = pthread_create(&pControllTh,
				(const pthread_attr_t *) NULL,
				ControllMessageThread::ControlMessageHandler,
				(void *) &mSrcAddr)) != 0)
		{
			isRunning = false;
			return ERROR_CLASS_CONTROLL_MESSAGE_THREAD_CREATE;
		}

		isRunning = true;
		pthread_join(pControllTh, NULL);
	} else {
		std::cout << "Already Started Control Message Thread !!" << std::endl;
	}
	return 0;
}

int ControllMessageThread::Stop() {

	if (!inited)
		return ERROR_CLASS_CONTROLL_MESSAGE_THREAD_INIT;

	if (isRunning) {
		pthread_cancel(pControllTh);
		isRunning = false;
	} else {
		std::cout << "Already Stopped Control Message Thread !!" << std::endl;
	}
	return 0;
}

void* ControllMessageThread::ControlMessageHandler(void *data) {

	Ipv4Address myaddr("0",9000);

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

	UdpTransmitter transmitter(false,myaddr);
	int status = 0;

	if((status = transmitter.Init()) < 0){
		pthread_exit((void *) NULL);
		return (void *)0;
	}

	while (true)
	{
		struct DriveControlMeaage msg={0,};
		ControlMessageParser parser;
		ControlData cnt_data;

		if((transmitter.Recv((void *)&msg, sizeof(struct DriveControlMeaage))) > 0){

			parser.Parse(&msg, &sCntMsg);
		}

	}

	transmitter.Clear();

	pthread_exit((void *) NULL);
	return (void *)0;
}

ControlData ControllMessageThread::getControllMsg(){
	return sCntMsg;
}
