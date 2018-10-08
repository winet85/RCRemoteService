/*
 * UdpTransmitter.cpp
 *
 *  Created on: 2017. 4. 22.
 *      Author: JOON
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "UdpTransmitter.h"

UdpTransmitter::UdpTransmitter(bool sender, Ipv4Address myaddr)
	:created(true), inited(false), isSender(sender), mSockFd(0), mMyaddr(myaddr)
{

}

//UdpTransmitter::UdpTransmitter(std::string ipaddr, int port, bool sender)
//	:created(true), inited(false), isSender(sender), mSockFd(0)
//{
//
//}

UdpTransmitter::~UdpTransmitter()
{
	created = false;
}

int UdpTransmitter::Init()
{
	int status  = 0;
	std::cout << " UdpTransmitter::Init" << std::endl;
	if(!created)
	{
		return ERROR_CLASS_UDPTRANSMITTER_INIT;
	}

	if((status = internalCreate()) < 0){
		return status;
	}

	inited = true;

	return 0;
}

int UdpTransmitter::internalCreate(){

	int sock_opt = 0;
	if ((mSockFd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		return ERROR_CLASS_UDPTRANSMITTER_SOCKET_CREATE;
	}
	sock_opt = 1;
	setsockopt(mSockFd,SOL_SOCKET,SO_REUSEADDR,&sock_opt, sizeof(sock_opt));

	if ((bind(mSockFd, (struct sockaddr *) &mMyaddr.GetAddr(),sizeof(struct sockaddr_in))) < 0) {
		return ERROR_CLASS_UDPTRANSMITTER_SOCKET_BIND;
	}

	return 0;
}
int UdpTransmitter::Clear()
{
	if(!inited)
	{
		return ERROR_CLASS_UDPTRANSMITTER_CLEAR;
	}

	inited = false;
	return 0;
}

int UdpTransmitter::SendTo(struct sockaddr_in dst, void *data, ssize_t length)
{
	if (!created)
	{
		return ERROR_CLASS_UDPTRANSMITTER_INIT;
	}

	if (!inited)
	{
		return ERROR_CLASS_UDPTRANSMITTER_CLEAR;
	}

	if(sendto(mSockFd,data,length,0,(struct sockaddr *)&dst,sizeof(struct sockaddr)) < 0){
		return ERROR_CLASS_UDPTRANSMITTER_SEND;
	}
	return 0;
}

int UdpTransmitter::Recv(void *data, ssize_t size)
{
	struct sockaddr senderaddr;
	socklen_t addrlen = 0;
	ssize_t recvlen = 0;

	if(!created)
	{
		return ERROR_CLASS_UDPTRANSMITTER_INIT;
	}
	if(!inited)
	{
		return ERROR_CLASS_UDPTRANSMITTER_CLEAR;
	}

	if(!mSockFd)
	{
		return ERROR_CLASS_UDPTRANSMITTER_SOCKET_IS_NULL;
	}

	if((recvlen = recvfrom(mSockFd,(void *)data,size,0,&senderaddr,&addrlen)) <= 0)
	{
		return ERROR_CLASS_UDPTRANSMITTER_SOCKET_RECV;
	}

	return recvlen;
}


