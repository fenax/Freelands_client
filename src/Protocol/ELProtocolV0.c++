/*
 * ELProtocolV0.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include <iostream>

#include "ELProtocolV0.h"
#include "MessageTypeV0.h"
#include "MessageTypeToServerV0.h"

#include "Game/Messages/RawTextMessage.h"

#include "Game/Messages/Login.h"
#include "Game/Messages/LoginResponse.h"

namespace Protocol {
using namespace Game::Messages;

ELProtocolV0::ELProtocolV0(Game::GameManager& game_manager):
		Protocol(game_manager),
		packet_size_(-1){
	// TODO Auto-generated constructor stub

}

ELProtocolV0::~ELProtocolV0() {
	// TODO Auto-generated destructor stub
}

void
ELProtocolV0::sendMessage(std::string message){

}

void
ELProtocolV0::sendLogin(std::string username, std::string password){
	Network::Buffer networkbuffer;
	networkbuffer.write_c_string(username + " " + password);
	send(networkbuffer, MessageTypeToServerV0::CTS_LOG_IN);
}

void
ELProtocolV0::sendCreateCharacter(std::string username, std::string password,
							  char skin, char hair, char shirt, char pants,
							  char boots, char race, char head){
	Network::Buffer networkbuffer;
	networkbuffer.write_c_string(username + " " + password);
	/*
	 *      Skin skin = Skin.get(msg.get(position));
            Hairs hair = Hairs.get(msg.get(position + 1));
            Shirts shirt = Shirts.get(msg.get(position + 2));
            Pants pants = Pants.get(msg.get(position + 3));
            Boots boots = Boots.get(msg.get(position + 4));
            ActorType race = ActorType.get(msg.get(position + 5));
            Head head = Head.get(msg.get(position + 6));
	 * */
	networkbuffer.write_LE_int8(skin);
	networkbuffer.write_LE_int8(hair);
	networkbuffer.write_LE_int8(shirt);
	networkbuffer.write_LE_int8(pants);
	networkbuffer.write_LE_int8(boots);
	networkbuffer.write_LE_int8(race);
	networkbuffer.write_LE_int8(head);
	send(networkbuffer, MessageTypeToServerV0::CTS_CREATE_CHAR);
}

void
ELProtocolV0::sendMoveTo(boost::int16_t x, boost::int16_t y){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(x);
	networkbuffer.write_LE_int8(y);
	send(networkbuffer, MessageTypeToServerV0::CTS_MOVE_TO);
}

void
ELProtocolV0::sendRawTextMessage(std::string message){
	Network::Buffer networkbuffer;
	networkbuffer.write_c_string(message);
	send(networkbuffer, MessageTypeToServerV0::CTS_RAW_TEXT);
}

void
ELProtocolV0:: sendPrivateMessage(std::string target, std::string message){
	Network::Buffer networkbuffer;
	networkbuffer.write_c_string(target + " " + message);
	send(networkbuffer, MessageTypeToServerV0::CTS_SEND_PM);
}

//public static void sendVersionMessage(NetworkClient from, ByteBuffer msg) {
//    assert (msg.get(0) == ToServerProtocol.SEND_VERSION.value);
//    //TODO check version of client
//}

void
ELProtocolV0::sendOpeninigScreen(){
	Network::Buffer networkbuffer;
	send(networkbuffer, MessageTypeToServerV0::CTS_SEND_OPENING_SCREEN);
}

void
ELProtocolV0::sendAttack(boost::int16_t target){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int16(target);
	send(networkbuffer, MessageTypeToServerV0::CTS_ATTACK_SOMEONE);
}

void
ELProtocolV0::sendLookAtInventoryItem(boost::int8_t pos){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(pos);
	send(networkbuffer, MessageTypeToServerV0::CTS_LOOK_AT_INVENTORY_ITEM);
}

void
ELProtocolV0::sendUseInventoryItem(boost::int8_t pos){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(pos);
	send(networkbuffer, MessageTypeToServerV0::CTS_USE_INVENTORY_ITEM);
}

void
ELProtocolV0::sendDropItem(boost::int8_t pos, boost::int32_t quantity){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(pos);
	networkbuffer.write_LE_int32(quantity);
	send(networkbuffer, MessageTypeToServerV0::CTS_DROP_ITEM);
}

void
ELProtocolV0::sendTouchPlayer(boost::int16_t target){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int16(target);
	send(networkbuffer, MessageTypeToServerV0::CTS_TOUCH_PLAYER);
}

void
ELProtocolV0::sendRespondToNpc(boost::int16_t npc, boost::int16_t response){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int16(npc);
	networkbuffer.write_LE_int16(response);
	send(networkbuffer, MessageTypeToServerV0::CTS_RESPOND_TO_NPC);
}

void
ELProtocolV0::sendInspectBag(boost::int8_t bag){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(bag);
	send(networkbuffer, MessageTypeToServerV0::CTS_INSPECT_BAG);
}

void
ELProtocolV0::sendPickUpItem(boost::int8_t pos, boost::int32_t quantity){//from bag
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(pos);
	networkbuffer.write_LE_int32(quantity);
	send(networkbuffer, MessageTypeToServerV0::CTS_PICK_UP_ITEM);
}

void
ELProtocolV0::sendMoveInventoryItem(boost::int8_t pos,boost::int8_t newpos){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(pos);
	networkbuffer.write_LE_int8(newpos);
	send(networkbuffer, MessageTypeToServerV0::CTS_MOVE_INVENTORY_ITEM);
}

void
ELProtocolV0::sendLookAtMapObject(boost::int32_t object_id){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int32(object_id);
	send(networkbuffer, MessageTypeToServerV0::CTS_LOOK_AT_MAP_OBJECT);
}

void
ELProtocolV0::sendUseMapObject(boost::int32_t object_id, boost::int32_t inventory_item){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int32(object_id);
	networkbuffer.write_LE_int32(inventory_item);
	send(networkbuffer, MessageTypeToServerV0::CTS_USE_MAP_OBJECT);
}
//public static void harvestMessage(Player from, ByteBuffer msg) {
//    assert (msg.get(0) == ToServerProtocol.HARVEST.value);//21
//    short objectmapid = msg.getShort(3);
//    HarvestInitiator.handleHarvestingRequest(from, objectmapid);
//}

void
ELProtocolV0::sendHarvest(boost::int16_t object_id){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int16(object_id);
	send(networkbuffer, MessageTypeToServerV0::CTS_HARVEST);

}

//public static void manufactureThisMessage(Player from, ByteBuffer msg) {
//    //TODO : implements flags in item and send it to client to a possibility of test this
//    assert (msg.get(0) == ToServerProtocol.MANUFACTURE_THIS.value);//21
//    byte nbitems = msg.get(3);
//    byte itemspos[] = new byte[nbitems];
//    short itemsq[] = new short[nbitems];
//    for (int i = 0; i < nbitems; ++i) {
//        itemspos[i] = msg.get(3 + i + 1);
//        itemsq[i] = msg.get(3 + i + 1 + 1);
//    }
//    from.initManufacture(itemspos, itemsq);
//}

void
ELProtocolV0::sendManufactureThis(boost::int16_t count, boost::int8_t item_pos_quantity[][2]){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int16(count);
	for(int i = 0; i < count ; i++){
		networkbuffer.write_LE_int8(item_pos_quantity[i][0]);
		networkbuffer.write_LE_int8(item_pos_quantity[i][1]);
	}
	send(networkbuffer, MessageTypeToServerV0::CTS_MANUFACTURE_THIS);
}

//public static void setActiveChannelMessage(NetworkClient from, ByteBuffer msg) {
//    assert (msg.get(0) == ToServerProtocol.SET_ACTIVE_CHANNEL.value);//61
//    byte n = msg.get(3);
//    from.setActiveChannel(n);
//}

void
ELProtocolV0::sendSetActiveChannel(boost::int8_t channel ){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(channel);
	send(networkbuffer, MessageTypeToServerV0::CTS_SET_ACTIVE_CHANNEL);
}

//public static void castSpellMessage(Player from, ByteBuffer msg) {
//    assert(msg.get(0)==ToServerProtocol.CAST_SPELL.value);
//    byte number = msg.get(3);
//    byte[]sigils = new byte[number];
//    for(int i = 0 ; i <sigils.length;i++){
//        sigils[i]=msg.get(i+4);
//    }
//    Spell s = Spell.getSpell(sigils);
//    if(s!=null){
//        if(s.distant)from.spellRequest(s);
//        else from.spellRequest(s, null);//TODO get player and other
//    }
//
//
//}

void
ELProtocolV0::sendCastSpell(boost::int8_t channel, boost::int8_t sigil[]){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int8(channel);
	for(int i = 0 ; i < channel ; i++){
		networkbuffer.write_LE_int8(sigil[i]);
	}
	send(networkbuffer, MessageTypeToServerV0::CTS_CAST_SPELL);
}


void
ELProtocolV0::sendPong(boost::int32_t payload){
	Network::Buffer networkbuffer;
	networkbuffer.write_LE_int32(payload);
	send(networkbuffer, MessageTypeToServerV0::CTS_PING_RESPONSE);
}


void
ELProtocolV0::send(Network::Buffer& networkbuffer, char type){
/*	Game::Message to_send = getGameManager().GetToSend();
	sendMessage(to_send,networkbuffer,type);*/
	Network::Buffer * out = new Network::Buffer();
	networkbuffer.makeReadable();
	out->write_LE_int8(type);
	out->write_LE_int16(networkbuffer.in_avail()+1);
	out->sputn(
			boost::asio::buffer_cast<const char*>(networkbuffer.data()),
			networkbuffer.in_avail());
	getNetworkSender().send(out);
}

int
ELProtocolV0::getAmountToRead(){
	if(packet_size_ >= 0){
		return packet_size_;
	}else{
		return 3; //1 byte packet type + 2 bytes packet size
	}
}


//TODO Check if two successive calls do not have enough data.
void
ELProtocolV0::parse(Network::Buffer & message){
	if(packet_size_ == -1){
		if(message.in_avail()>=3){
			// Read packet header

			packet_type_ = message.read_LE_uint8();
			packet_size_ = message.read_LE_uint16()-1;
			std::cout << "Got packet of type " << packet_type_ << " and size " << packet_size_ << std::endl;
		}else{
			return;
		}
	}

	if(message.in_avail() >= packet_size_){

		switch(packet_type_){
			case MessageTypeV0::RAW_TEXT :
			{
				std::string text 	= message.read_c_string();
				getGameManager().giveRawMessage(text);
				break;
			}
			case MessageTypeV0::ADD_NEW_ACTOR :
				/*
				msg.putShort((short) (20 + 1 + mob.getContent().name.length()));
				msg.putShort(mob.id); // actor id
				if (mob.isInvisible()) {
					msg.putShort((short) (mob.getXpos() | 0x800));
				} else {
					msg.putShort(mob.getXpos());
				}
				msg.putShort(mob.getYpos()); //y+buffs
				msg.putShort((short) 0); //z pos, others values is for bird, not really used in french
				msg.putShort(mob.getContent().zRot); //z rot
				msg.put(mob.getContent().race.type); // actor type
				msg.put(mob.getFrame().value);
				msg.putShort((short) 0);
				msg.putShort(mob.lifeStatus());
				msg.put(KindOfActor.mob.value);
				for (int i = 0; i < mob.getContent().name.length(); i++) {
					msg.put((byte) mob.getContent().name.charAt(i));
				}
				msg.put((byte) 0);
				// scalability in 2bytes
				msg.putShort((short) 0x4000);
				   scalability its funny, 0x4000 is standard value
				 * 0x7FFF is maxvalue
				 * 0x1000 is the smallest value where a beaver is recognizable, at 0x0100 it's just few pixels in my 1280x1024 resolution
				 */
			{
				boost::int16_t actor_id = message.read_LE_int16();
				bool invisible = false;
				boost::int16_t x_pos = message.read_LE_int16();
				if(x_pos&0x800){
					x_pos &= 0x7ff;
					invisible = true;
				}
				boost::int16_t y_pos = message.read_LE_int16();
				boost::int16_t z_pos = message.read_LE_int16();

				boost::int16_t z_rotation = message.read_LE_int16();

				boost::uint8_t actor_race = message.read_LE_uint8();
				boost::uint8_t actor_frame = message.read_LE_uint8();

				message.read_LE_int16(); // Reads zero, undocumented

				boost::int16_t actor_life = message.read_LE_int16();
				boost::int16_t actor_type = message.read_LE_int16();
				/*	normal(1), // most players
					npc(2), // can be talked with
					redName(4), // pkable, agressive for mob
					mob(6); // yellow name, attackable */

				std::string actor_name = message.read_c_string();
				boost::int16_t actor_scalability = message.read_LE_int16();
				//TODO write actual code
				break;
			}
			case MessageTypeV0::ADD_ACTOR_COMMAND :
			{
				/*for (int i = 0; i < actors.length; ++i) {
					   msg.putShort(actors[i].id);
					   msg.put(cmds[i].value);
				}*/

				while(message.in_avail()){
					boost::int16_t actor  = message.read_LE_int16();
					boost::int8_t command = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::YOU_ARE :
			{
				boost::int16_t player_actor = message.read_LE_int16();
				getGameManager().givePlayerId(player_actor);
				break;
			}
			case MessageTypeV0::SYNC_CLOCK ://Actually this message is nothing
			{
				boost::int32_t clock = message.read_LE_int32(); //always 0
				std::cout << "clock is " << (int)clock << std::endl;
				//TODO find a use
				break;
			}
			case MessageTypeV0::NEW_MINUTE :
			{
				boost::int16_t game_time = message.read_LE_int16();
				getGameManager().giveTime(game_time/60, game_time%60);
			}
			case MessageTypeV0::REMOVE_ACTOR :
			{
				while(message.in_avail()){
					boost::int16_t actor = message.read_LE_int16();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::CHANGE_MAP :
			{
				std::string map_name = message.read_c_string();
				getGameManager().giveNewMap(map_name);
				break;
			}
			case MessageTypeV0::COMBAT_MODE :
			{
				//unimplemented on server
				break;
			}
			case MessageTypeV0::KILL_ALL_ACTORS :
				// no data needed
				//TODO write actual code
				break;
			case MessageTypeV0::GET_TELEPORTERS_LIST :
					//list of knows teleport,
					// msg is : num of tp, [x,y,type] x y is short, type byte and unused
	/*		{
				while(message.in_avail()){
					boost::int16_t pos_x = message.read_LE_int16();
					boost::int16_t pos_y = message.read_LE_int16();
					boost::int8_t type = message.read_LE_int8();
				}
				//todo check if implementation is good for specification
				//TODO write actual code
				break;
			}*/
				//unimplemented on server
				break;
			case MessageTypeV0::PONG :
			{
				boost::int32_t payload = message.read_LE_int32();
				//TODO write actual code
				break;
			}
			case MessageTypeV0::TELEPORT_IN :
					// is to show the particles associated with teleportaion
					// msg is : x(short) y (short)
			{
				boost::int16_t pos_x = message.read_LE_int16();
				boost::int16_t pos_y = message.read_LE_int16();
				//TODO write actual code
				break;
			}
			case MessageTypeV0::TELEPORT_OUT :
					// same as teleport in but for particule to quit an area
			{
				boost::int16_t pos_x = message.read_LE_int16();
				boost::int16_t pos_y = message.read_LE_int16();
				//TODO write actual code
				break;
			}
			case MessageTypeV0::PLAY_SOUND :
			case MessageTypeV0::START_RAIN : // delete later on
			case MessageTypeV0::STOP_RAIN : // delete later on
			case MessageTypeV0::THUNDER :
				//not implemented on server
				//TODO maybe something
				break;
			case MessageTypeV0::HERE_YOUR_STATS :
			{
				/*
				msg.putShort(hisContent.phyCur);
				msg.putShort(hisContent.phyBase);
				msg.putShort(hisContent.coordCur);
				msg.putShort(hisContent.coordBase);
				msg.putShort(hisContent.reacCur);
				msg.putShort(hisContent.reacBase);
				msg.putShort(hisContent.willCur);
				msg.putShort(hisContent.willBase);
				msg.putShort(hisContent.instCur);
				msg.putShort(hisContent.instBase);
				msg.putShort(hisContent.vitCur);
				msg.putShort(hisContent.vitBase);*/

				boost::int16_t phy_current 	 = message.read_LE_int16();
				boost::int16_t phy_base    	 = message.read_LE_int16();
				boost::int16_t coord_current = message.read_LE_int16();
				boost::int16_t coord_base    = message.read_LE_int16();
				boost::int16_t reac_current  = message.read_LE_int16();
				boost::int16_t reac_base     = message.read_LE_int16();
				boost::int16_t will_current  = message.read_LE_int16();
				boost::int16_t will_base     = message.read_LE_int16();
				boost::int16_t inst_current  = message.read_LE_int16();
				boost::int16_t inst_base     = message.read_LE_int16();
				boost::int16_t vit_current   = message.read_LE_int16();
				boost::int16_t vit_base      = message.read_LE_int16();
				//TODO clearer names

				/* nexuses
				msg.putShort(hisContent.humanNexCur);
				msg.putShort(hisContent.humanNexBase);
				msg.putShort(hisContent.animalNexCur);
				msg.putShort(hisContent.animalNexBase);
				msg.putShort(hisContent.vegetalNexCur);
				msg.putShort(hisContent.vegetalNexBase);
				msg.putShort(hisContent.inorganicNexCur);
				msg.putShort(hisContent.inorganicNexBase);
				msg.putShort(hisContent.artificialNexCur);
				msg.putShort(hisContent.artificialNexBase);
				msg.putShort(hisContent.magicNexCur);
				msg.putShort(hisContent.magicNexBase);*/

				boost::int16_t human_nexus_current 	    = message.read_LE_int16();
				boost::int16_t human_nexus_base    	    = message.read_LE_int16();
				boost::int16_t animal_nexus_current     = message.read_LE_int16();
				boost::int16_t animal_nexus_base        = message.read_LE_int16();
				boost::int16_t vegetal_nexus_current    = message.read_LE_int16();
				boost::int16_t vegetal_nexus_base       = message.read_LE_int16();
				boost::int16_t inorganic_nexus_current  = message.read_LE_int16();
				boost::int16_t inorganic_nexus_base     = message.read_LE_int16();
				boost::int16_t artificial_nexus_current = message.read_LE_int16();
				boost::int16_t artificial_nexus_base    = message.read_LE_int16();
				boost::int16_t magic_nexus_current      = message.read_LE_int16();
				boost::int16_t magic_nexus_base         = message.read_LE_int16();

				/* skill levels
				msg.putShort(hisContent.manuCur);
				msg.putShort(hisContent.manuBase);
				msg.putShort(hisContent.harvCur);
				msg.putShort(hisContent.harvBase);
				msg.putShort(hisContent.alchCur);
				msg.putShort(hisContent.alchBase);
				msg.putShort(hisContent.overCur);
				msg.putShort(hisContent.overBase);
				msg.putShort(hisContent.attCur);
				msg.putShort(hisContent.attBase);
				msg.putShort(hisContent.defCur);
				msg.putShort(hisContent.defBase);
				msg.putShort(hisContent.magCur);
				msg.putShort(hisContent.magBase);
				msg.putShort(hisContent.potCur);
				msg.putShort(hisContent.potBase);*/

				boost::int16_t manufacture_current = message.read_LE_int16();
				boost::int16_t manufacture_base    = message.read_LE_int16();
				boost::int16_t harvest_current     = message.read_LE_int16();
				boost::int16_t harvest_base        = message.read_LE_int16();
				boost::int16_t alchemy_current     = message.read_LE_int16();
				boost::int16_t alchemy_base        = message.read_LE_int16();
				boost::int16_t overall_current     = message.read_LE_int16();
				boost::int16_t overall_base        = message.read_LE_int16();
				boost::int16_t attack_current      = message.read_LE_int16();
				boost::int16_t attack_base         = message.read_LE_int16();
				boost::int16_t defence_current     = message.read_LE_int16();
				boost::int16_t defence_base        = message.read_LE_int16();
				boost::int16_t magic_current       = message.read_LE_int16();
				boost::int16_t magic_base          = message.read_LE_int16();
				boost::int16_t potion_current      = message.read_LE_int16();
				boost::int16_t potion_base         = message.read_LE_int16();

				/* misc
				msg.putShort(hisContent.carryCur);
				msg.putShort(hisContent.carryBase);
				msg.putShort(hisContent.healthCur);
				msg.putShort(hisContent.healthBase);
				msg.putShort(hisContent.manaCur);
				msg.putShort(hisContent.manaBase);
				msg.putShort(hisContent.foodLevel);

				msg.putShort((short) 0);// research completed
				msg.putShort((short) 0); // unknow*/

				boost::int16_t carry_current  = message.read_LE_int16();
				boost::int16_t carry_base     = message.read_LE_int16();
				boost::int16_t health_current = message.read_LE_int16();
				boost::int16_t health_base    = message.read_LE_int16();
				boost::int16_t mana_current   = message.read_LE_int16();
				boost::int16_t mana_base      = message.read_LE_int16();

				boost::int16_t food_level     = message.read_LE_int16();

				message.read_LE_int16();//TODO find what they do
				message.read_LE_int16();

				/* experience
				msg.putInt(hisContent.manuExp);
				msg.putInt(hisContent.manuNextLvl);
				msg.putInt(hisContent.harvExp);
				msg.putInt(hisContent.harvNextLvl);
				msg.putInt(hisContent.alchExp);
				msg.putInt(hisContent.alchNextLvl);
				msg.putInt(hisContent.overExp);
				msg.putInt(hisContent.overNextLvl);
				msg.putInt(hisContent.attExp);
				msg.putInt(hisContent.attNextLvl);
				msg.putInt(hisContent.defExp);
				msg.putInt(hisContent.defNextLvl);
				msg.putInt(hisContent.magicExp);
				msg.putInt(hisContent.magicNextLvl);
				msg.putInt(hisContent.potExp);
				msg.putInt(hisContent.potNextLvl);*/

				boost::int32_t manufacture_exp        = message.read_LE_int32();
				boost::int32_t manufacture_next_level = message.read_LE_int32();
				boost::int32_t harvest_exp            = message.read_LE_int32();
				boost::int32_t harvest_next_level     = message.read_LE_int32();
				boost::int32_t alchemy_exp            = message.read_LE_int32();
				boost::int32_t alchemy_next_level     = message.read_LE_int32();
				boost::int32_t overall_exp            = message.read_LE_int32();
				boost::int32_t overall_next_level     = message.read_LE_int32();
				boost::int32_t attack_exp             = message.read_LE_int32();
				boost::int32_t attack_next_level      = message.read_LE_int32();
				boost::int32_t defence_exp            = message.read_LE_int32();
				boost::int32_t defence_next_level     = message.read_LE_int32();
				boost::int32_t magic_exp              = message.read_LE_int32();
				boost::int32_t magic_next_level       = message.read_LE_int32();
				boost::int32_t potion_exp             = message.read_LE_int32();
				boost::int32_t potion_next_level      = message.read_LE_int32();

				/*msg.putShort((short) 0);//unknow
				msg.putShort((short) 0);//researching
				msg.putShort((short) 0);//research total
				// skill levels / experience mixed
				msg.putShort(hisContent.summonCur);
				msg.putShort(hisContent.summonBase);
				msg.putInt(hisContent.summonExp);
				msg.putInt(hisContent.summonNextLvl);
				msg.putShort((short) 0);// crafting cur
				msg.putShort((short) 0);//base
				msg.putInt(0);//exp
				msg.putInt(0);//exp next*/

				message.read_LE_int16();//TODO find what they do
				message.read_LE_int16();
				message.read_LE_int16();

				boost::int16_t summon_current    = message.read_LE_int16();
				boost::int16_t summon_base       = message.read_LE_int16();
				boost::int32_t summon_exp        = message.read_LE_int32();
				boost::int32_t summon_next_level = message.read_LE_int32();

				boost::int16_t crafting_current    = message.read_LE_int16();
				boost::int16_t crafting_base       = message.read_LE_int16();
				boost::int32_t exp        = message.read_LE_int32();
				boost::int32_t next_level = message.read_LE_int32();

				/*msg.putShort((short) 0);//charisme
				msg.putShort((short) 0);//religion
				msg.putShort((short) 0);//niv_religion
				msg.putShort((short) 0);//race
				msg.putShort((short) 0);//charisme next
				msg.putShort((short) 0);//charisme lvl
				msg.putShort((short) 0);//charisme rang*/
				boost::int16_t charisma=0,religion=0,religion_level=0,race=0,charisma_next=0,charisma_level=0,charisma_rank=0;

				if(packet_size_ > 199){ // probably shouldn't have an if here
					charisma       = message.read_LE_int16();
					religion       = message.read_LE_int16();
					religion_level = message.read_LE_int16();
					race           = message.read_LE_int16();
					charisma_next  = message.read_LE_int16();
					charisma_level = message.read_LE_int16();
					charisma_rank  = message.read_LE_int16();
				}

				getGameManager().getPlayer().setStats(
						phy_current,phy_base,
						coord_current,coord_base,
						reac_current,reac_base,
						will_current,will_base,
						inst_current,inst_base,
						vit_current,vit_base,
						human_nexus_current,human_nexus_base,
						animal_nexus_current, animal_nexus_base,
						vegetal_nexus_current,vegetal_nexus_base,
						inorganic_nexus_current, inorganic_nexus_base,
						artificial_nexus_current, artificial_nexus_base,
						magic_nexus_current, magic_nexus_base,
						manufacture_current, manufacture_base,
						harvest_current, harvest_base,
						alchemy_current, alchemy_base,
						overall_current, overall_base,
						attack_current, attack_base,
						defence_current, defence_base,
						magic_current, magic_base,
						potion_current, potion_base,
						carry_current, carry_base,
						health_current, health_base,
						mana_current, mana_base,
						food_level,
						manufacture_exp, manufacture_next_level,
						harvest_exp, harvest_next_level,
						alchemy_exp,alchemy_next_level,
						overall_exp, overall_next_level,
						attack_exp, attack_next_level,
						defence_exp, defence_next_level,
						magic_exp, magic_next_level,
						potion_exp, potion_next_level,
						summon_current, summon_base, summon_exp, summon_next_level,
						crafting_current, crafting_base,
						exp, next_level,
						charisma,
						religion, religion_level,
						race,
						charisma_next, charisma_level, charisma_rank);
				break;
			}
			case MessageTypeV0::HERE_YOUR_INVENTORY :
			{
				/*
				msg.put(size); // total items
				ItemDatabase id;
				for (int i = 0; i < 44; i++) {
					id = p.getInventory().getItemByPos(i);
					if (id != null && id != ItemDatabase.none) {
						msg.putShort(id.baseitem.getImgId());
						msg.putInt(p.getInventory().getItemQuantity(i));
						msg.put((byte) i);
						msg.put(id.baseitem.flags);
					}
				}
				*/
				int quantity = message.read_LE_uint8();

				Game::Inventory& inventory = getGameManager().getPlayer().getInventory();
				for(int i = 0; i < quantity; i++){
					boost::int16_t item_id       = message.read_LE_int16();
					boost::int32_t item_quantity = message.read_LE_int32();
					boost::int8_t  item_position = message.read_LE_int8();
					boost::int8_t  item_flags    = message.read_LE_int8();
					inventory[item_position].setAll(item_id,item_quantity,item_flags);
				}
				inventory.print();
				break;
			}
			case MessageTypeV0::INVENTORY_ITEM_TEXT :
			{
				/*  msg.put((byte) (TextColor.c_red1.value + 127));
					msg.put(txt.getBytes(iso88591)); */
				int 		first 	= message.read_LE_uint8();
				std::string text 	= message.read_c_string();
				if(first > 127){
					text.insert(first,0);
	//				out = new RawTextMessage(text);
				}else{
	//				out = new RawTextMessage(text,first);
				}

				//TODO write actual code
				break;
			}
			case MessageTypeV0::GET_NEW_INVENTORY_ITEM :
			{
				while(message.in_avail()){
					boost::int16_t item_id       = message.read_LE_int16();
					boost::int32_t item_quantity = message.read_LE_int32();
					boost::int8_t  item_position = message.read_LE_int8();
					boost::int8_t  item_flags    = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::REMOVE_ITEM_FROM_INVENTORY :
			{
				while(message.in_avail()){
					boost::int8_t  item_position = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::HERE_YOUR_GROUND_ITEMS :
			{
				int quantity = message.read_LE_uint8();
				for(int i = 0; i < quantity; i++){
					boost::int16_t item_id       = message.read_LE_int16();
					boost::int32_t item_quantity = message.read_LE_int32();
					boost::int8_t  item_position = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::GET_NEW_GROUND_ITEM :
			{
				while(message.in_avail()){
					boost::int16_t item_id       = message.read_LE_int16();
					boost::int32_t item_quantity = message.read_LE_int32();
					boost::int8_t  item_position = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::REMOVE_ITEM_FROM_GROUND :
				//Not implemented on server
				//TODO implement
				break;
			case MessageTypeV0::CLOSE_BAG :
				//no data
				//TODO write actual code
			case MessageTypeV0::GET_NEW_BAG :
			{
				while(message.in_avail()){
					boost::int16_t pos_x       = message.read_LE_int16();
					boost::int16_t pos_y       = message.read_LE_int16();
					boost::int8_t  bag_id = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::GET_BAGS_LIST :
			{
				int quantity = message.read_LE_uint8();
				for(int i = 0; i < quantity; i++){
					boost::int16_t pos_x       = message.read_LE_int16();
					boost::int16_t pos_y       = message.read_LE_int16();
					boost::int8_t  bag_id = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::DESTROY_BAG :
			{
				while(message.in_avail()){
					boost::int8_t  bag_id = message.read_LE_int8();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::NPC_TEXT :
				//todo java implementation is strange
			case MessageTypeV0::NPC_OPTIONS_LIST :
				/*
				//size of an option in US client is 3 + text len +2+2
				//size of an option in FR client is 3 + text len +2+4 because the response_id is 32bits instead of 16
				short packetLength = (short) (9 * list.numOptions);
				for (int i = 0; i < list.numOptions; i++) {
					packetLength += list.options[i].text.length();
				}
				packetLength++;
				msg.putShort(packetLength);
				for (int i = 0; i < list.numOptions; i++) {
					msg.putShort((short) (list.options[i].text.length() + 1));
					msg.put(list.options[i].text.getBytes(iso88591));
					msg.put((byte) 0);
					msg.putInt(list.options[i].responseId);
					msg.putShort(toNPCActor.id);
				}
				*/
			{
				while(message.in_avail()){
					boost::int8_t  bag_id = message.read_LE_int8();
				}
				//TODO report WTF
				break;
			}

			case MessageTypeV0::CLOSE_NPC_MENU :
				//not implemented on server
				break;
			case MessageTypeV0::SEND_NPC_INFO :
				/*
				msg.put(name.getBytes());
				for (int i = 0; i < 20 - name.length(); i++) {
					msg.put((byte) 0);
				}
				msg.put(icon);*/
				//TODO WTF

			{
				std::string name = message.read_c_string();
				for(int i = name.length()+1; i < 20; i++){
					message.read_LE_int8(); //zero padding to 20 chars
				}
				boost::int8_t icon = message.read_LE_int8();
				//todo write actual code
				break;
			}

			case MessageTypeV0::GET_TRADE_INFO : // delete later on
			case MessageTypeV0::GET_TRADE_OBJECT :
			case MessageTypeV0::GET_TRADE_ACCEPT :
			case MessageTypeV0::GET_TRADE_REJECT :
			case MessageTypeV0::GET_TRADE_EXIT :
			case MessageTypeV0::REMOVE_TRADE_OBJECT :
			case MessageTypeV0::GET_YOUR_TRADEOBJECTS :
			case MessageTypeV0::GET_TRADE_PARTNER_NAME :
				// to be deleted
				break;

			case MessageTypeV0::GET_YOUR_SIGILS :
			{
				boost::int32_t sigil = message.read_LE_int32();
				getGameManager().giveSigils(sigil);
				break;
			}
			case MessageTypeV0::SPELL_ITEM_TEXT :
			case MessageTypeV0::GET_ACTIVE_SPELL :
				//not implemented on server
				break;
			case MessageTypeV0::GET_ACTIVE_SPELL_LIST :
			{
				std::vector<boost::int8_t> active_spells;
					//list of ten active spell,
					// a byte whos is number in the texture/sigils.bmp, -1 is no spell
				while(message.in_avail()){
					boost::int8_t spell = message.read_LE_int8();
					active_spells.push_back(spell);
				}
				getGameManager().giveActiveSpells(active_spells);

			}
			case MessageTypeV0::REMOVE_ACTIVE_SPELL :
				//not implemented on server
				break;
			case MessageTypeV0::GET_ACTOR_DAMAGE :
			{
				boost::int16_t actor_id = message.read_LE_int16();
				boost::int16_t damage = message.read_LE_int16();
				boost::int16_t life_status = message.read_LE_int16();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::GET_ACTOR_HEAL :
			{
				boost::int16_t actor_id = message.read_LE_int16();
				boost::int16_t heal = message.read_LE_int16();
				boost::int16_t life_status = message.read_LE_int16();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::SEND_PARTIAL_STAT :
			{
				/* msg.put(name.value);
				   msg.putInt(value);*/
				while(message.in_avail()){
					boost::int8_t  name  = message.read_LE_int8();
					boost::int32_t value = message.read_LE_int32();
				}
				//TODO write actual code
				break;
			}
			case MessageTypeV0::SPAWN_BAG_PARTICLES :
				//not implemented on server
				break;
			case MessageTypeV0::ADD_NEW_ENHANCED_ACTOR :
			{
				/*	msg.putShort(which.id);
					if (which.isInvisible()) {
						msg.putShort((short) (which.getContent().xPos | 0x800));
					} else {
						msg.putShort(which.getContent().xPos);
					}
					msg.putShort(which.getContent().yPos);
					msg.putShort(which.getContent().zPos);
					msg.putShort(which.getContent().zRot);
					msg.put(which.getContent().race.type);
					msg.put((byte) 0); // ???
					msg.put(which.getContent().skin.value);
					msg.put(which.getContent().hair.value);
					msg.put(which.getWornShirt());
					msg.put(which.getWornPants());
					msg.put(which.getWornBoots());
					msg.put(which.getContent().head.value);
					msg.put(which.getWornShield());
					msg.put(which.getWornWeapon());
					msg.put(which.getWornCape());
					msg.put(which.getWornHelmet());
					msg.put(ActorFrame.frame_idle.value);
					if (itsMe) {
						msg.putShort(which.getContent().healthBase);
						msg.putShort(which.getContent().healthCur);
					} else {
						msg.putShort((short) 0);
						msg.putShort(which.lifeStatus());
					}
					msg.put(which.getContent().kindOfActor.value);
					for (int i = 0; i < which.getContent().name.length(); i++) {
						msg.put((byte) which.getContent().name.charAt(i));
					}
					msg.put((byte) 0);
					// scalability in 2bytes
					msg.putShort((short) 0x4000);*/
				boost::int16_t id = msg.putShort(which.id);


				bool invisible = false;
				boost::int16_t x_pos = message.read_LE_int16();
				boost::int16_t y_pos = message.read_LE_int16();
				boost::int16_t z_pos = message.read_LE_int16();
				if(x_pos&0x800){
					x_pos &= 0x7ff;
					invisible = true;
				}

				boost::int16_t z_rotation = message.read_LE_int16();

				boost::int8_t race = message.read_LE_int8();
				message.read_LE_int8(); //TODO guess what it is
				boost::int8_t skin = message.read_LE_int8();
				boost::int8_t hair = message.read_LE_int8();

				boost::int8_t shirt = message.read_LE_int8();
				boost::int8_t pants = message.read_LE_int8();
				boost::int8_t boots = message.read_LE_int8();
				boost::int8_t head  = message.read_LE_int8();
				boost::int8_t shield = message.read_LE_int8();
				boost::int8_t weapon = message.read_LE_int8();
				boost::int8_t cape = message.read_LE_int8();
				boost::int8_t helmet = message.read_LE_int8();

				boost::int8_t frame = message.read_LE_int8();

				boost::int16_t health_base = message.read_LE_int16();
				boost::int16_t health_cur = message.read_LE_int16();
				boost::int8_t type = message.read_LE_int8();

				std::string name = message.read_c_string();

				boost::int16_t scalability = message.read_LE_int16();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::ACTOR_WEAR_ITEM :
			{
				/*  msg.putShort(actor.id);
					msg.put(item.getType().value);
					msg.put(item.get3DObjectClientId()); */
				boost::int16_t actor_id       = message.read_LE_int16();
				boost::int8_t  item_type      = message.read_LE_int8();
				boost::int8_t  item_client_id = message.read_LE_int8();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::ACTOR_UNWEAR_ITEM :
			{
				boost::int16_t actor_id       = message.read_LE_int16();
				boost::int8_t  item_type      = message.read_LE_int8();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::PLAY_MUSIC :
				//not implemented on server
			case MessageTypeV0::GET_KNOWLEDGE_LIST :
			{
					//send size of list and a list of bit with id of knowledge
					// (see knowledge.lst in client) is position in message,
					// the bit represent if knowledge is learn(1) or not (0)
				std::vector<bool>& knownledges = getGameManager().getPlayer().getKnownledges();
				while(message.in_avail()){
					boost::int8_t  knownledge_flags  = message.read_LE_int8();
					for(int j = 0 ; j < 8 ; j++){
						knownledges.push_back(knownledge_flags&1);
						knownledge_flags >>= 1;
					}
				}
				break;
			}
			case MessageTypeV0::GET_NEW_KNOWLEDGE :
			{
				boost::int16_t actor_id       = message.read_LE_int16();

				//TODO write actual code
				break;
			}
			case MessageTypeV0::GET_KNOWLEDGE_TEXT :
			case MessageTypeV0::BUDDY_EVENT :
					// byte 1 (true) 0 (false)--> add or remove,
					// byte type (format unknow), String playername

				//not implemented on server
				break;
			case MessageTypeV0::PING_REQUEST :
			{
				boost::int32_t payload = message.read_LE_int32();
				sendPong(payload);
				//TODO pong
				break;
			}

			case MessageTypeV0::FIRE_PARTICLES :
			case MessageTypeV0::REMOVE_FIRE_AT :
			case MessageTypeV0::DISPLAY_CLIENT_WINDOW :
			case MessageTypeV0::OPEN_BOOK :
			case MessageTypeV0::READ_BOOK :
			case MessageTypeV0::CLOSE_BOOK :
			case MessageTypeV0::STORAGE_LIST :
			case MessageTypeV0::STORAGE_ITEMS :
			case MessageTypeV0::STORAGE_TEXT :
			case MessageTypeV0::SPELL_CAST :
				//not implemented on server
				getGameManager().giveError("not implemented");
				break;
			case MessageTypeV0::GET_ACTIVE_CHANNELS :
			{
				boost::int8_t activecc = message.read_LE_int8();
				while(message.in_avail()){
					boost::int32_t  channel  = message.read_LE_int32();
				}
				break;
			}
			case MessageTypeV0::MAP_FLAGS :
				//not implemented on server
				getGameManager().giveError("not implemented");
				break;
			case MessageTypeV0::GET_ACTOR_HEALTH :
			{
				/*  msg.putShort(a.id);
					if (itsMe) {
						msg.putShort(a.getContent().healthBase);
						msg.putShort((short) 0);
					} else {
						msg.putShort((short) 0);
						msg.putShort(a.lifeStatus());
					} */
				boost::int16_t actor_id       = message.read_LE_int16();
				boost::int16_t health_base       = message.read_LE_int16();
				boost::int16_t life_status       = message.read_LE_int16();

				getGameManager().giveError("not implemented GET_ACTOR_HEALTH");

				break;
			}
			case MessageTypeV0::GET_3D_OBJ_LIST :
			case MessageTypeV0::GET_3D_OBJ :
			case MessageTypeV0::REMOVE_3D_OBJ :
			case MessageTypeV0::GET_ITEMS_COOLDOWN :
			case MessageTypeV0::SEND_BUFFS :
			case MessageTypeV0::SEND_SPECIAL_EFFECT :
			case MessageTypeV0::SEND_WEATHER :

					//MANU_ITEM_TEXT(20), // devrait devenir( 127), a terme -
					//actuellement non utilisé
			case MessageTypeV0::DISPLAY_COORD :
					// reserved for future expansion( 220),-229, not being used in the server
					// yet
			case MessageTypeV0::MAP_SET_OBJECTS :
					//^ is used for send object 2d or 3d to client,
					//need more dev, send the type of obj 0 -> 2d, 1 -> 3d
					//structure is type (byte) raw data
					//probably not used
			case MessageTypeV0::MAP_STATE_OBJECTS :
					//probably not used

			case MessageTypeV0::UPGRADE_NEW_VERSION :
					// TODO: Consider combining all this into one
					// packet followed by one byte (plus optional
					// text)
			case MessageTypeV0::UPGRADE_TOO_OLD :
			case MessageTypeV0::REDEFINE_YOUR_COLORS :
				//not implemented on server

				getGameManager().giveError("Implemented");
				break;
			case MessageTypeV0::YOU_DONT_EXIST :
			{
				//no parameters
				std::cout << "kikoo\n";
				getGameManager().giveError("exist");
				break;
			}
			case MessageTypeV0::LOG_IN_OK :
			{
				//no parameters

				getGameManager().giveOk("login");
				break;
			}
			case MessageTypeV0::LOG_IN_NOT_OK :
			{
				std::string error_message = message.read_c_string();

				getGameManager().giveError("login",error_message);
				break;
			}
			case MessageTypeV0::CREATE_CHAR_OK :
			{
				//no parameters

				getGameManager().giveOk("character");
				break;
			}
			case MessageTypeV0::CREATE_CHAR_NOT_OK :
			{
				std::string error_message = message.read_c_string();

				getGameManager().giveError("character",error_message);
				break;
			}
			case MessageTypeV0::BYE :
			break;
			default :
				std::cout << "how much is " << packet_type_ << "?" << std::endl;
		}
		packet_size_ = -1;
	}
}

}
