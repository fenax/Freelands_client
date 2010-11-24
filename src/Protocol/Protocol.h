/*
 * Protocol.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "NetworkBuffer.h"
#include "Game/GameManager.h"


namespace Protocol
{

class Protocol
{
private:
	Game::GameManager & game_manager_;
public:
	Protocol(Game::GameManager game_manager);
	virtual ~Protocol();

	virtual void parse(NetworkBuffer&,int)=0;
	virtual int send(NetworkBuffer&)=0;
	Game::GameManager & getGameManager();
};

}

#endif /* PROTOCOL_H_ */
