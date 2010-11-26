/*
 * ELProtocolV0.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef ELPROTOCOLV0_H_
#define ELPROTOCOLV0_H_

#include <boost/cstdint.hpp>
#include <Game/GameManager.h>

#include "Network/Buffer.h"
#include "Network/Network.h"

#include "Protocol.h"

namespace Protocol {

class ELProtocolV0 : public Protocol{
private:
	int packet_size_;
	int packet_type_;

public:
	ELProtocolV0(Game::GameManager&);
	virtual ~ELProtocolV0();
	virtual void parse(Network::Buffer&);
	virtual void send(Network::Buffer&,char);

	virtual void sendMessage(std::string message);
	virtual void sendLogin(std::string username, std::string password);
	virtual int getAmountToRead();


};

}

#endif /* ELPROTOCOLV0_H_ */
