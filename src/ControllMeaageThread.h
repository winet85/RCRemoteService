/*
 * ControllMeaageThread.h
 *
 *  Created on: 2017. 4. 18.
 *      Author: JOON
 */

#ifndef SRC_CONTROLLMEAAGETHREAD_H_
#define SRC_CONTROLLMEAAGETHREAD_H_

#include <pthread.h>
#include "RCRemoteError.h"
#include "UdpTransmitter.h"
#include "ControlMessageParser.h"

class ControllMessageThread{

public :
	ControllMessageThread();
	ControllMessageThread(string myip, uint16_t myport, string detip, uint16_t dstport);
	~ControllMessageThread();
	int Init();
	int Clear();
	int Start();
	int Stop();
	static void *ControlMessageHandler(void *data);

	static ControlData getControllMsg();


private :
	bool created;
	bool inited;
	pthread_t pControllTh ;
	bool isRunning ;

	Ipv4Address mSrcAddr;
	Ipv4Address mDstAddr;

};



#endif /* SRC_CONTROLLMEAAGETHREAD_H_ */
