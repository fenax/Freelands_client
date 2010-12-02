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
