/*
 * Protocol.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include "Protocol.h"

namespace Protocol
{

Protocol::Protocol(Game::GameManager game_manager):
		game_manager_(game_manager)
{
	// TODO Auto-generated constructor stub

}

Protocol::~Protocol()
{
	// TODO Auto-generated destructor stub
}

Protocol::getGameManager(){
	return game_manager_;
}

}
