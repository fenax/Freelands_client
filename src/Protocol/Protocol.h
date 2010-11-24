/*
 * Protocol.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "NetworkBuffer.h"
#include "Network.h"
#include "Message.h"


namespace Protocol
{

class Protocol
{
public:
	Protocol();
	virtual ~Protocol();

	virtual void Parse(NetworkBuffer&,int)=0;
	virtual int Send(NetworkBuffer&)=0;
};

}

#endif /* PROTOCOL_H_ */
