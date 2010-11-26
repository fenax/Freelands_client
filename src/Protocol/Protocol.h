/*
 * Protocol.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "Network/Buffer.h"

#include "Game/GameManager.h"
#include "Network/Sender.h"


namespace Protocol
{

class Protocol
{
private:
	Game::GameManager & game_manager_;
	Network::Sender * sender_;
protected:
public:
	Protocol(Game::GameManager & game_manager);
	virtual ~Protocol();

	virtual void parse(Network::Buffer&)=0;
	//virtual void send(NetworkBuffer&,int & type)=0;
	Game::GameManager & getGameManager();
	Network::Sender & getNetworkSender();

	void registerNetworkSender(Network::Sender &);

	virtual void sendMessage(std::string message)=0;
	virtual void sendLogin(std::string username, std::string password)=0;
	virtual int getAmountToRead()=0;



};

}

#endif /* PROTOCOL_H_ */
