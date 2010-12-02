/**
 * @file
 * @author  Guillaume Minet "Fenax" <mail@fenax.name>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Interface class for a protocol.
 */

#ifndef PROTOCOL_PROTOCOL_H_
#define PROTOCOL_PROTOCOL_H_

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

#endif // PROTOCOL_PROTOCOL_H_
