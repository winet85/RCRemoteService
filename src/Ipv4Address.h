/*
 * Ipv4Address.h
 *
 *  Created on: 2017. 4. 27.
 *      Author: JOON
 */

#ifndef SRC_IPV4ADDRESS_H_
#define SRC_IPV4ADDRESS_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <string>
#include <sstream>

using namespace std;
class Ipv4Address{

public :
	Ipv4Address() {}
	Ipv4Address(string ip, uint16_t port)
	{
		this -> mAddr.sin_family = AF_INET;
		inet_aton(ip.c_str(), &this -> mAddr.sin_addr);
		this -> mAddr.sin_port = htons(port);
	}
	~Ipv4Address() {}

	struct sockaddr_in GetAddr() { return this -> mAddr; }
	in_addr_t GetNetIp() { return this -> mAddr.sin_addr.s_addr; }
	uint16_t GetNetPort() { return this -> mAddr.sin_port; }
	void update(Ipv4Address* addr)
	{
		this -> mAddr.sin_family = addr->GetAddr().sin_family;
		this -> mAddr.sin_addr.s_addr = addr->GetNetIp();
		this -> mAddr.sin_port = addr->GetNetPort();
	}
	string toString(){
		stringstream ss;
		ss << "IP Addr(" << inet_ntoa(this -> mAddr.sin_addr) <<"), Port("<< ntohs(this -> mAddr.sin_port) << ")\n";
		return ss.str();
	}
private :
	struct sockaddr_in mAddr;
};



#endif /* SRC_IPV4ADDRESS_H_ */
