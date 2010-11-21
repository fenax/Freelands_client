/*
 * ELProtocolV0.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include "ELProtocolV0.h"
#include "MessageTypeV0.h"
#include "RawTextMessage.h"

namespace Protocol {

ELProtocolV0::ELProtocolV0() {
	// TODO Auto-generated constructor stub

}

ELProtocolV0::~ELProtocolV0() {
	// TODO Auto-generated destructor stub
}

Message
ELProtocolV0::Parse(NetworkBuffer message, int type){
	MessageTypeV0 message_type = (MessageTypeV0)type;
	Message * out;
	switch(message_type){
		case RAW_TEXT :
		{
			int 		first 	= message.read_LE_uint8();
			std::string text 	= message.read_c_string();
			if(first > 127){
				text.insert(first,0);
				out = new RawTextMessage(text);
			}else{
				out = new RawTextMessage(text,first);
			}
			break;
		}
		case ADD_NEW_ACTOR :
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
		}
		case ADD_ACTOR_COMMAND :
		{
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
		}
		case YOU_ARE :
		{
			boost::int16_t player_actor = message.read_LE_int16();
			//TODO write actual code
			break;
		}
		case SYNC_CLOCK ://Actually this message is nothing
		{
			boost::int32_t clock = message.read_LE_int32(); //always 0
			//TODO find a use
			break;
		}
		case NEW_MINUTE :
		{
			boost::int16_t game_time = message.read_LE_int16();
			//TODO write actual code
		}
		case REMOVE_ACTOR :
		{
			while(message.in_avail()){
				boost::int16_t actor = message.read_LE_int16();
			}
			//TODO write actual code
			break;
		}
		case CHANGE_MAP :
		case COMBAT_MODE :
		case KILL_ALL_ACTORS :
		case GET_TELEPORTERS_LIST :
			    //list of knows teleport,
			    // msg is : num of tp, [x,y,type] x y is short, type byte and unused
		case PONG :
		case TELEPORT_IN :
			    // is to show the particles associated with teleportaion
			    // msg is : x(short) y (short)
		case TELEPORT_OUT :
			    // same as teleport in but for particule to quit an area
		case PLAY_SOUND :
		case START_RAIN : // delete later on
		case STOP_RAIN : // delete later on
		case THUNDER :
		case HERE_YOUR_STATS :
		case HERE_YOUR_INVENTORY :
		case INVENTORY_ITEM_TEXT :
		case GET_NEW_INVENTORY_ITEM :
		case REMOVE_ITEM_FROM_INVENTORY :
		case HERE_YOUR_GROUND_ITEMS :
		case GET_NEW_GROUND_ITEM :
		case REMOVE_ITEM_FROM_GROUND :
		case CLOSE_BAG :
		case GET_NEW_BAG :
		case GET_BAGS_LIST :
		case DESTROY_BAG :
		case NPC_TEXT :
		case NPC_OPTIONS_LIST :
		case CLOSE_NPC_MENU :
		case SEND_NPC_INFO :
		case GET_TRADE_INFO : // delete later on
		case GET_TRADE_OBJECT :
		case GET_TRADE_ACCEPT :
		case GET_TRADE_REJECT :
		case GET_TRADE_EXIT :
		case REMOVE_TRADE_OBJECT :
		case GET_YOUR_TRADEOBJECTS :
		case GET_TRADE_PARTNER_NAME :
		case GET_YOUR_SIGILS :
		case SPELL_ITEM_TEXT :
		case GET_ACTIVE_SPELL :
		case GET_ACTIVE_SPELL_LIST :
			    //list of ten active spell,
			    // a byte whos is number in the texture/sigils.bmp, -1 is no spell
		case REMOVE_ACTIVE_SPELL :
		case GET_ACTOR_DAMAGE :
		case GET_ACTOR_HEAL :
		case SEND_PARTIAL_STAT :
		case SPAWN_BAG_PARTICLES :
		case ADD_NEW_ENHANCED_ACTOR :
		case ACTOR_WEAR_ITEM :
		case ACTOR_UNWEAR_ITEM :
		case PLAY_MUSIC :
		case GET_KNOWLEDGE_LIST :
			    //send size of list and a list of bit with id of knowledge
			    // (see knowledge.lst in client) is position in message,
			    // the bit represent if knowledge is learn(1) or not (0)
		case GET_NEW_KNOWLEDGE :
		case GET_KNOWLEDGE_TEXT :
		case BUDDY_EVENT :
			    // byte 1 (true) 0 (false)--> add or remove,
			    // byte type (format unknow), String playername
		case PING_REQUEST :
		case FIRE_PARTICLES :
		case REMOVE_FIRE_AT :
		case DISPLAY_CLIENT_WINDOW :
		case OPEN_BOOK :
		case READ_BOOK :
		case CLOSE_BOOK :
		case STORAGE_LIST :
		case STORAGE_ITEMS :
		case STORAGE_TEXT :
		case SPELL_CAST :
		case GET_ACTIVE_CHANNELS :
		case MAP_FLAGS :
		case GET_ACTOR_HEALTH :
		case GET_3D_OBJ_LIST :
		case GET_3D_OBJ :
		case REMOVE_3D_OBJ :
		case GET_ITEMS_COOLDOWN :
		case SEND_BUFFS :
		case SEND_SPECIAL_EFFECT :
		case SEND_WEATHER :

			    //MANU_ITEM_TEXT(20), // devrait devenir( 127), a terme -
			    //actuellement non utilisé
		case DISPLAY_COORD :
			    // reserved for future expansion( 220),-229, not being used in the server
			    // yet
		case MAP_SET_OBJECTS :
			    //^ is used for send object 2d or 3d to client,
			    //need more dev, send the type of obj 0 -> 2d, 1 -> 3d
			    //structure is type (byte) raw data
			    //probably not used
		case MAP_STATE_OBJECTS :
			    //probably not used

		case UPGRADE_NEW_VERSION :
			    // TODO: Consider combining all this into one
			    // packet followed by one byte (plus optional
			    // text)
		case UPGRADE_TOO_OLD :
		case REDEFINE_YOUR_COLORS :
		case YOU_DONT_EXIST :
		case LOG_IN_OK :
		case LOG_IN_NOT_OK :
		case CREATE_CHAR_OK :
		case CREATE_CHAR_NOT_OK :
		case BYE :
		break;
	}
};

}
