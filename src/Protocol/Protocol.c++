/*
 * Protocol.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include "Protocol.h"

namespace Protocol
{

Protocol::Protocol(Game::GameManager & game_manager):
		game_manager_(game_manager)
{
	// TODO Auto-generated constructor stub

}

Protocol::~Protocol()
{
	// TODO Auto-generated destructor stub
}

Game::GameManager &
Protocol::getGameManager(){
	return game_manager_;
}
Network::Sender &
Protocol::getNetworkSender(){
	return *sender_;
}

void
Protocol::registerNetworkSender(Network::Sender & sender){
	sender_ = &sender;
}



}
