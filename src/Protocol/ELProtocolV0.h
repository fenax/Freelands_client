/*
 * ELProtocolV0.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef ELPROTOCOLV0_H_
#define ELPROTOCOLV0_H_

#include <boost/cstdint.hpp>

#include "NetworkBuffer.h"
#include "Message.h"
#include "Protocol.h"

namespace Protocol {

class ELProtocolV0 : public Protocol{
public:
	ELProtocolV0();
	virtual ~ELProtocolV0();
	virtual Message Parse(NetworkBuffer&,int);
	virtual int Send(NetworkBuffer&);
};

}

#endif /* ELPROTOCOLV0_H_ */
