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
 * Protocol for Eternal lands servers header file.
 */

#ifndef PROTOCOL_ELPROTOCOLV0_H_
#define PROTOCOL_ELPROTOCOLV0_H_

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
	virtual void sendCreateCharacter(std::string username, std::string password,
							  char skin, char hair, char shirt, char pants,
							  char boots, char race, char head);
	virtual void sendMoveTo(boost::int16_t x, boost::int16_t y);
	virtual void sendRawTextMessage(std::string message);
	virtual void sendPrivateMessage(std::string target, std::string message);
	virtual void sendOpeninigScreen();
	virtual void sendAttack(boost::int16_t target);
	virtual void sendLookAtInventoryItem(boost::int8_t pos);
	virtual void sendUseInventoryItem(boost::int8_t pos);
	virtual void sendDropItem(boost::int8_t pos, boost::int32_t quantity);
	virtual void sendTouchPlayer(boost::int16_t target);
	virtual void sendRespondToNpc(boost::int16_t npc, boost::int16_t response);
	virtual void sendInspectBag(boost::int8_t bag);
	virtual void sendPickUpItem(boost::int8_t pos, boost::int32_t quantity);//from bag
	virtual void sendMoveInventoryItem(boost::int8_t pos,boost::int8_t newpos);
	virtual void sendLookAtMapObject(boost::int32_t object_id);
	virtual void sendUseMapObject(boost::int32_t object_id, boost::int32_t inventory_item);
	virtual void sendHarvest(boost::int16_t object_id);
	virtual void sendManufactureThis(boost::int16_t count, boost::int8_t item_pos_quantity[][2]);
	virtual void sendSetActiveChannel(boost::int8_t channel );
	virtual void sendCastSpell(boost::int8_t channel, boost::int8_t sigil[]);
	virtual void sendPong(boost::int32_t payload);




	virtual int getAmountToRead();


};

}

#endif /* PROTOCOL_ELPROTOCOLV0_H_ */
