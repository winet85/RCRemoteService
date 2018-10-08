/*
 * UdpTransmitter.h
 *
 *  Created on: 2017. 4. 22.
 *      Author: JOON
 */

#ifndef SRC_UDPTRANSMITTER_H_
#define SRC_UDPTRANSMITTER_H_

#include <stdint.h>
#include <list>
#include "Ipv4Address.h"
#include "RCRemoteError.h"

class UdpTransmitter
{
public :
	UdpTransmitter(bool sender, Ipv4Address myaddr);
	~UdpTransmitter();
	int Init();
	int Clear();
	int SendTo(struct sockaddr_in dst, void *data, ssize_t length);
	int Recv(void *data, ssize_t size);
private :
	bool created, inited;
	bool isSender;
	int mSockFd;
	Ipv4Address mMyaddr;

	int internalCreate();
	//std::list<ControlData> mInternalBuffer;
};

#endif /* SRC_UDPTRANSMITTER_H_ */
