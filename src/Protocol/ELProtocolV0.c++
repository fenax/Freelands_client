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
		case ADD_ACTOR_COMMAND :
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
		{
			std::string map_name = message.read_c_string();
			//TODO write actual code
			break;
		}
		case COMBAT_MODE :
		{
			//unimplemented on server
			break;
		}
		case KILL_ALL_ACTORS :
			// no data needed
			//TODO write actual code
			break;
		case GET_TELEPORTERS_LIST :
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
		case PONG :
		{
			boost::int32_t payload = message.read_LE_int32();
			//TODO write actual code
			break;
		}
		case TELEPORT_IN :
			    // is to show the particles associated with teleportaion
			    // msg is : x(short) y (short)
		{
			boost::int16_t pos_x = message.read_LE_int16();
			boost::int16_t pos_y = message.read_LE_int16();
			//TODO write actual code
			break;
		}
		case TELEPORT_OUT :
			    // same as teleport in but for particule to quit an area
		{
			boost::int16_t pos_x = message.read_LE_int16();
			boost::int16_t pos_y = message.read_LE_int16();
			//TODO write actual code
			break;
		}
		case PLAY_SOUND :
		case START_RAIN : // delete later on
		case STOP_RAIN : // delete later on
		case THUNDER :
			//not implemented on server
			//TODO maybe something
			break;
		case HERE_YOUR_STATS :
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
			boost::int16_t inwt_base     = message.read_LE_int16();
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

			boost::int16_t manufacture_exp        = message.read_LE_int16();
			boost::int16_t manufacture_next_level = message.read_LE_int16();
			boost::int16_t harvest_exp            = message.read_LE_int16();
			boost::int16_t harvest_next_level     = message.read_LE_int16();
			boost::int16_t alchemy_exp            = message.read_LE_int16();
			boost::int16_t alchemy_next_level     = message.read_LE_int16();
			boost::int16_t overall_exp            = message.read_LE_int16();
			boost::int16_t overall_next_level     = message.read_LE_int16();
			boost::int16_t attack_exp             = message.read_LE_int16();
			boost::int16_t attack_next_level      = message.read_LE_int16();
			boost::int16_t defence_exp            = message.read_LE_int16();
			boost::int16_t defence_next_level     = message.read_LE_int16();
			boost::int16_t magic_exp              = message.read_LE_int16();
			boost::int16_t magic_next_level       = message.read_LE_int16();
			boost::int16_t potion_exp             = message.read_LE_int16();
			boost::int16_t potion_next_level      = message.read_LE_int16();

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
			boost::int16_t summon_exp        = message.read_LE_int16();
			boost::int16_t summon_next_level = message.read_LE_int16();


			/*msg.putShort((short) 0);//charisme
			msg.putShort((short) 0);//religion
			msg.putShort((short) 0);//niv_religion
			msg.putShort((short) 0);//race
			msg.putShort((short) 0);//charisme next
			msg.putShort((short) 0);//charisme lvl
			msg.putShort((short) 0);//charisme rang*/

			if(message.in_avail()){ // probably shouldn't have an if here
				boost::int16_t charisma       = message.read_LE_int16();
				boost::int16_t religion       = message.read_LE_int16();
				boost::int16_t religion_level = message.read_LE_int16();
				boost::int16_t race           = message.read_LE_int16();
				boost::int16_t charisma_next  = message.read_LE_int16();
				boost::int16_t charisma_level = message.read_LE_int16();
				boost::int16_t charisma_rank  = message.read_LE_int16();
			}


			//TODO write actual code
			break;
		}
		case HERE_YOUR_INVENTORY :
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
			for(int i = 0; i < quantity; i++){
				boost::int16_t item_id       = message.read_LE_int16();
				boost::int32_t item_quantity = message.read_LE_int32();
				boost::int8_t  item_position = message.read_LE_int8();
				boost::int8_t  item_flags    = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case INVENTORY_ITEM_TEXT :
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
		case GET_NEW_INVENTORY_ITEM :
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
		case REMOVE_ITEM_FROM_INVENTORY :
		{
			while(message.in_avail()){
				boost::int8_t  item_position = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case HERE_YOUR_GROUND_ITEMS :
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
		case GET_NEW_GROUND_ITEM :
		{
			while(message.in_avail()){
				boost::int16_t item_id       = message.read_LE_int16();
				boost::int32_t item_quantity = message.read_LE_int32();
				boost::int8_t  item_position = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case REMOVE_ITEM_FROM_GROUND :
			//Not implemented on server
			//TODO implement
			break;
		case CLOSE_BAG :
			//no data
			//TODO write actual code
		case GET_NEW_BAG :
		{
			while(message.in_avail()){
				boost::int16_t pos_x       = message.read_LE_int16();
				boost::int16_t pos_y       = message.read_LE_int16();
				boost::int8_t  bag_id = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case GET_BAGS_LIST :
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
		case DESTROY_BAG :
		{
			while(message.in_avail()){
				boost::int8_t  bag_id = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case NPC_TEXT :
			//todo java implementation is strange
		case NPC_OPTIONS_LIST :
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

		case CLOSE_NPC_MENU :
			//not implemented on server
			break;
		case SEND_NPC_INFO :
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

		case GET_TRADE_INFO : // delete later on
		case GET_TRADE_OBJECT :
		case GET_TRADE_ACCEPT :
		case GET_TRADE_REJECT :
		case GET_TRADE_EXIT :
		case REMOVE_TRADE_OBJECT :
		case GET_YOUR_TRADEOBJECTS :
		case GET_TRADE_PARTNER_NAME :
			// to be deleted
			break;

		case GET_YOUR_SIGILS :
		{
			boost::int32_t sigil = message.read_LE_int32();
			//TODO write actual code
			break;
		}
		case SPELL_ITEM_TEXT :
		case GET_ACTIVE_SPELL :
			//not implemented on server
			break;
		case GET_ACTIVE_SPELL_LIST :
		{
			    //list of ten active spell,
			    // a byte whos is number in the texture/sigils.bmp, -1 is no spell
			while(message.in_avail()){
				boost::int8_t spell = message.read_LE_int8();
			}
		}
		case REMOVE_ACTIVE_SPELL :
			//not implemented on server
			break;
		case GET_ACTOR_DAMAGE :
		{
			boost::int16_t actor_id = message.read_LE_int16();
			boost::int16_t damage = message.read_LE_int16();
			boost::int16_t life_status = message.read_LE_int16();

			//TODO write actual code
			break;
		}
		case GET_ACTOR_HEAL :
		{
			boost::int16_t actor_id = message.read_LE_int16();
			boost::int16_t heal = message.read_LE_int16();
			boost::int16_t life_status = message.read_LE_int16();

			//TODO write actual code
			break;
		}
		case SEND_PARTIAL_STAT :
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
		case SPAWN_BAG_PARTICLES :
			//not implemented on server
			break;
		case ADD_NEW_ENHANCED_ACTOR :
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
			boost::int16_t health_base = message.read_LE_int16();
			boost::int16_t health_cur = message.read_LE_int16();
			boost::int8_t type = message.read_LE_int8();

			std::string name = message.read_c_string();

			boost::int16_t scalability = message.read_LE_int16();

			//TODO write actual code
			break;
		}
		case ACTOR_WEAR_ITEM :
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
		case ACTOR_UNWEAR_ITEM :
		{
			boost::int16_t actor_id       = message.read_LE_int16();
			boost::int8_t  item_type      = message.read_LE_int8();

			//TODO write actual code
			break;
		}
		case PLAY_MUSIC :
			//not implemented on server
		case GET_KNOWLEDGE_LIST :
		{
			    //send size of list and a list of bit with id of knowledge
			    // (see knowledge.lst in client) is position in message,
			    // the bit represent if knowledge is learn(1) or not (0)
			while(message.in_avail()){
				boost::int8_t  knownledge_flags  = message.read_LE_int8();
			}
			//TODO write actual code
			break;
		}
		case GET_NEW_KNOWLEDGE :
		{
			boost::int16_t actor_id       = message.read_LE_int16();

			//TODO write actual code
			break;
		}
		case GET_KNOWLEDGE_TEXT :
		case BUDDY_EVENT :
			    // byte 1 (true) 0 (false)--> add or remove,
			    // byte type (format unknow), String playername

			//not implemented on server
			break;
		case PING_REQUEST :
		{
			boost::int32_t payload = message.read_LE_int32();
			//TODO pong
			break;
		}

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
			//not implemented on server
			break;
		case GET_ACTIVE_CHANNELS :
		{
			boost::int8_t activecc = message.read_LE_int8();
			while(message.in_avail()){
				boost::int32_t  channel  = message.read_LE_int32();
			}

		}
		case MAP_FLAGS :
			//not implemented on server
			break;
		case GET_ACTOR_HEALTH :
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

		}
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
			//not implemented on server
		case YOU_DONT_EXIST :
		{
			//no parameters
			//TODO write actual code
			break;
		}
		case LOG_IN_OK :
		{
			//no parameters
			//TODO write actual code
			break;
		}
		case LOG_IN_NOT_OK :
		{
			std::string error_message = message.read_c_string();
			//TODO write actual code
			break;
		}
		case CREATE_CHAR_OK :
		{
			//no parameters
			//TODO write actual code
			break;
		}
		case CREATE_CHAR_NOT_OK :
		{
			std::string error_message = message.read_c_string();
			//TODO write actual code
			break;
		}
		case BYE :
		break;
	}
};

}
