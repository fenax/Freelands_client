/*
 * ELProtocolV0.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include "ELProtocolV0.h"
#include "MessageTypeV0.h"

namespace Protocol {

ELProtocolV0::ELProtocolV0() {
	// TODO Auto-generated constructor stub

}

ELProtocolV0::~ELProtocolV0() {
	// TODO Auto-generated destructor stub
}

Message
ELProtocolV0::Parse(NetworkBuffer message, boost::uint8_t type){
	MessageTypeV0 message_type = type;
	Message * out;
	switch(message_type){
		case MessageTypeV0::RAW_TEXT :
			int 		first 	= message.read_LE_uint8();
			std::string text 	= message.read_c_string();
			if(first > 127){
				text.insert(0,first);
				out = new RawTextMessage(text);
			}else{
				out = new RawTextMessage(text,first);
			}
			break;
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
			boost::int16_t x_pos = message.read_LE_int16();
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
		case MessageTypeV0::ADD_ACTOR_COMMAND :
			/*for (int i = 0; i < actors.length; ++i) {
			       msg.putShort(actors[i].id);
			       msg.put(cmds[i].value);
			}*/

			while(message.in_avail()){
				boost::int16_t actor = message.read_LE_int16();
				boost::int8_t command = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		case MessageTypeV0::YOU_ARE :
			boost::int16_t player_actor = message.read_LE_int16();
			//TODO write actual code
			break;
		case MessageTypeV0::SYNC_CLOCK ://Actually this message is nothing
			boost::int32_t clock = message.read_LE_int32(); //always 0
			//TODO find a use
			break;
		case MessageTypeV0::NEW_MINUTE :
			//TODO understand
		case MessageTypeV0::REMOVE_ACTOR :
			while(message.in_avail()){
				boost::int16_t actor = message.read_LE_int16();
			}
			//TODO write actual code
			break;
		case MessageTypeV0::CHANGE_MAP :
		case MessageTypeV0::COMBAT_MODE :
		case MessageTypeV0::KILL_ALL_ACTORS :
		case MessageTypeV0::GET_TELEPORTERS_LIST :
			    //list of knows teleport,
			    // msg is : num of tp, [x,y,type] x y is short, type byte and unused
		case MessageTypeV0::PONG :
		case MessageTypeV0::TELEPORT_IN :
			    // is to show the particles associated with teleportaion
			    // msg is : x(short) y (short)
		case MessageTypeV0::TELEPORT_OUT :
			    // same as teleport in but for particule to quit an area
		case MessageTypeV0::PLAY_SOUND :
		case MessageTypeV0::START_RAIN : // delete later on
		case MessageTypeV0::STOP_RAIN : // delete later on
		case MessageTypeV0::THUNDER :
		case MessageTypeV0::HERE_YOUR_STATS :
		case MessageTypeV0::HERE_YOUR_INVENTORY :
		case MessageTypeV0::INVENTORY_ITEM_TEXT :
		case MessageTypeV0::GET_NEW_INVENTORY_ITEM :
		case MessageTypeV0::REMOVE_ITEM_FROM_INVENTORY :
		case MessageTypeV0::HERE_YOUR_GROUND_ITEMS :
		case MessageTypeV0::GET_NEW_GROUND_ITEM :
		case MessageTypeV0::REMOVE_ITEM_FROM_GROUND :
		case MessageTypeV0::CLOSE_BAG :
		case MessageTypeV0::GET_NEW_BAG :
		case MessageTypeV0::GET_BAGS_LIST :
		case MessageTypeV0::DESTROY_BAG :
		case MessageTypeV0::NPC_TEXT :
		case MessageTypeV0::NPC_OPTIONS_LIST :
		case MessageTypeV0::CLOSE_NPC_MENU :
		case MessageTypeV0::SEND_NPC_INFO :
		case MessageTypeV0::GET_TRADE_INFO : // delete later on
		case MessageTypeV0::GET_TRADE_OBJECT :
		case MessageTypeV0::GET_TRADE_ACCEPT :
		case MessageTypeV0::GET_TRADE_REJECT :
		case MessageTypeV0::GET_TRADE_EXIT :
		case MessageTypeV0::REMOVE_TRADE_OBJECT :
		case MessageTypeV0::GET_YOUR_TRADEOBJECTS :
		case MessageTypeV0::GET_TRADE_PARTNER_NAME :
		case MessageTypeV0::GET_YOUR_SIGILS :
		case MessageTypeV0::SPELL_ITEM_TEXT :
		case MessageTypeV0::GET_ACTIVE_SPELL :
		case MessageTypeV0::GET_ACTIVE_SPELL_LIST :
			    //list of ten active spell,
			    // a byte whos is number in the texture/sigils.bmp, -1 is no spell
		case MessageTypeV0::REMOVE_ACTIVE_SPELL :
		case MessageTypeV0::GET_ACTOR_DAMAGE :
		case MessageTypeV0::GET_ACTOR_HEAL :
		case MessageTypeV0::SEND_PARTIAL_STAT :
		case MessageTypeV0::SPAWN_BAG_PARTICLES :
		case MessageTypeV0::ADD_NEW_ENHANCED_ACTOR :
		case MessageTypeV0::ACTOR_WEAR_ITEM :
		case MessageTypeV0::ACTOR_UNWEAR_ITEM :
		case MessageTypeV0::PLAY_MUSIC :
		case MessageTypeV0::GET_KNOWLEDGE_LIST :
			    //send size of list and a list of bit with id of knowledge
			    // (see knowledge.lst in client) is position in message,
			    // the bit represent if knowledge is learn(1) or not (0)
		case MessageTypeV0::GET_NEW_KNOWLEDGE :
		case MessageTypeV0::GET_KNOWLEDGE_TEXT :
		case MessageTypeV0::BUDDY_EVENT :
			    // byte 1 (true) 0 (false)--> add or remove,
			    // byte type (format unknow), String playername
		case MessageTypeV0::PING_REQUEST :
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
		case MessageTypeV0::GET_ACTIVE_CHANNELS :
		case MessageTypeV0::MAP_FLAGS :
		case MessageTypeV0::GET_ACTOR_HEALTH :
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
		case MessageTypeV0::YOU_DONT_EXIST :
		case MessageTypeV0::LOG_IN_OK :
		case MessageTypeV0::LOG_IN_NOT_OK :
		case MessageTypeV0::CREATE_CHAR_OK :
		case MessageTypeV0::CREATE_CHAR_NOT_OK :
		case MessageTypeV0::BYE :
	}
}

}
