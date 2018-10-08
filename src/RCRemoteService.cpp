/*
 * RCRemoteService.cpp
 *
 *  Created on: 2017. 4. 11.
 *      Author: JOON
 */

#include <iostream>
#include <csignal>
#include <pthread.h>
#include "MotorControllWiringPi.h"
#include "ControllMeaageThread.h"

pthread_mutex_t mMainMutex;
#define MUTEX_MAIN_LOCK pthread_mutex_lock(&mMainMutex)
#define MUTEX_MAIN_UNLOCK pthread_mutex_unlock(&mMainMutex)

#include <unistd.h>
using namespace std;

bool isRunning = false;
ControllMessageThread* controllMessageThread;

void SigHandler(int signo) {
	std::cout << "Interupt Signal (" << signo << ")" << std::endl;
	isRunning = false;
	controllMessageThread -> Stop();
	controllMessageThread -> Clear();
	delete controllMessageThread;

}
void printError(int errorno)
{
	std::cout << "ERROR (" << errorno << ")" << std::endl;
}
void *CtlMotroThread(void *data) {
	std::cout << "CtlMotroThread Created " << std::endl;
	int status = 0;
	MotorControllWiringPi* motorcontroll = new MotorControllWiringPi();

	if ((status = motorcontroll->Init()) < 0)
	{
		printError(status);
	}

	while (isRunning) {
		motorcontroll->SetSpeed(controllMessageThread->getControllMsg().GetSpeed()
				,controllMessageThread->getControllMsg().IsForword());
		motorcontroll->SetSteering(controllMessageThread->getControllMsg().GetSteering()
				,controllMessageThread->getControllMsg().IsRight());

		usleep(20000);
	}

	if((status = motorcontroll -> Clear()) < 0)
	{
		printError(status);
	}

	std::cout << "CtlMotroThread end " << std::endl;
	delete motorcontroll;
	pthread_exit((void *) NULL);
	return (void *) 0;
}


int main(int argc, char **argv) {

	pthread_t ctlMotorThId = 0;
	int status  = 0;

	signal(SIGINT, SigHandler);

	isRunning = true;
	if (pthread_create(&ctlMotorThId, (const pthread_attr_t *) NULL, CtlMotroThread, (void *) NULL)) {
		std::cout << "ERROR : pthread created " << ctlMotorThId << std::endl;
		return -1;
	}

	controllMessageThread = new ControllMessageThread();

	if((status = controllMessageThread -> Init()))
	{
		printError(status);
		return 0;
	}
	if((status = controllMessageThread -> Start()) < 0){
		printError(status);
	}

	pthread_join(ctlMotorThId, (void **) NULL);
	return 0;
}
