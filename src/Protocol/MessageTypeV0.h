/*
 * MessageTypeV0.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef MESSAGETYPEV0_H_
#define MESSAGETYPEV0_H_

#include <boost/cstdint.hpp>

namespace Protocol
{
// made a copy from the server without thinking, should probably attribute
// copyright to Michael Fraipont, I'll see to that someday I get motivated to
// make GPL headers in files
class MessageTypeV0
{
public:
	static const int
    RAW_TEXT = 0,
    ADD_NEW_ACTOR = 1,
    ADD_ACTOR_COMMAND = 2,
    YOU_ARE = 3,
    SYNC_CLOCK = 4,//Actually this message is nothing
    NEW_MINUTE = 5,
    REMOVE_ACTOR = 6,
    CHANGE_MAP = 7,
    COMBAT_MODE = 8,
    KILL_ALL_ACTORS = 9,
    GET_TELEPORTERS_LIST = 10,
    //list of knows teleport,
    // msg is : num of tp, [x,y,type] x y is short, type byte and unused
    PONG = 11,
    TELEPORT_IN = 12,
    // is to show the particles associated with teleportaion
    // msg is : x(short) y (short)
    TELEPORT_OUT = 13,
    // same as teleport in but for particule to quit an area
    PLAY_SOUND = 14,
    START_RAIN = 15, // delete later on
    STOP_RAIN = 16, // delete later on
    THUNDER = 17,
    HERE_YOUR_STATS = 18,
    HERE_YOUR_INVENTORY = 19,
    INVENTORY_ITEM_TEXT = 20,
    GET_NEW_INVENTORY_ITEM = 21,
    REMOVE_ITEM_FROM_INVENTORY = 22,
    HERE_YOUR_GROUND_ITEMS = 23,
    GET_NEW_GROUND_ITEM = 24,
    REMOVE_ITEM_FROM_GROUND = 25,
    CLOSE_BAG = 26,
    GET_NEW_BAG = 27,
    GET_BAGS_LIST = 28,
    DESTROY_BAG = 29,
    NPC_TEXT = 30,
    NPC_OPTIONS_LIST = 31,
    CLOSE_NPC_MENU = 32,
    SEND_NPC_INFO = 33,
    GET_TRADE_INFO = 34, // delete later on
    GET_TRADE_OBJECT = 35,
    GET_TRADE_ACCEPT = 36,
    GET_TRADE_REJECT = 37,
    GET_TRADE_EXIT = 38,
    REMOVE_TRADE_OBJECT = 39,
    GET_YOUR_TRADEOBJECTS = 40,
    GET_TRADE_PARTNER_NAME = 41,
    GET_YOUR_SIGILS = 42,//
    SPELL_ITEM_TEXT = 43,
    GET_ACTIVE_SPELL = 44,
    GET_ACTIVE_SPELL_LIST = 45,
    //list of ten active spell,
    // a byte whos is number in the texture/sigils.bmp, -1 is no spell
    REMOVE_ACTIVE_SPELL = 46,
    GET_ACTOR_DAMAGE = 47,
    GET_ACTOR_HEAL = 48,
    SEND_PARTIAL_STAT = 49,
    SPAWN_BAG_PARTICLES = 50,
    ADD_NEW_ENHANCED_ACTOR = 51,
    ACTOR_WEAR_ITEM = 52,
    ACTOR_UNWEAR_ITEM = 53,
    PLAY_MUSIC = 54,
    GET_KNOWLEDGE_LIST = 55,
    //send size of list and a list of bit with id of knowledge
    // (see knowledge.lst in client) is position in message,
    // the bit represent if knowledge is learn(1) or not (0)
    GET_NEW_KNOWLEDGE = 56,
    GET_KNOWLEDGE_TEXT = 57,
    BUDDY_EVENT = 59,
    // byte 1 (true) 0 (false)--> add or remove,
    // byte type (format unknow), String playername
    PING_REQUEST = 60,
    FIRE_PARTICLES = 61,
    REMOVE_FIRE_AT = 62,
    DISPLAY_CLIENT_WINDOW = 63,
    OPEN_BOOK = 64,
    READ_BOOK = 65,
    CLOSE_BOOK = 66,
    STORAGE_LIST = 67,
    STORAGE_ITEMS = 68,
    STORAGE_TEXT = 69,
    SPELL_CAST = 70,
    GET_ACTIVE_CHANNELS = 71,
    MAP_FLAGS = 72,
    GET_ACTOR_HEALTH = 73,
    GET_3D_OBJ_LIST = 74,
    GET_3D_OBJ = 75,
    REMOVE_3D_OBJ = 76,
    GET_ITEMS_COOLDOWN = 77,
    SEND_BUFFS = 78,
    SEND_SPECIAL_EFFECT = 79,
    SEND_WEATHER = 80,

    //MANU_ITEM_TEXT(20), // devrait devenir( 127), a terme -
    //actuellement non utilisé
    DISPLAY_COORD = 128,
    // reserved for future expansion( 220),-229, not being used in the server
    // yet
    MAP_SET_OBJECTS = 220,
    //^ is used for send object 2d or 3d to client,
    //need more dev, send the type of obj 0 -> 2d, 1 -> 3d
    //structure is type (byte) raw data
    //probably not used
    MAP_STATE_OBJECTS = 221,
    //probably not used

    UPGRADE_NEW_VERSION = 240,
    // TODO: Consider combining all this into one
    // packet followed by one byte (plus optional
    // text)
    UPGRADE_TOO_OLD = 241,
    REDEFINE_YOUR_COLORS = 248,
    YOU_DONT_EXIST = 249,
    LOG_IN_OK = 250,
    LOG_IN_NOT_OK = 251,
    CREATE_CHAR_OK = 252,
    CREATE_CHAR_NOT_OK = 253,
    BYE = 255;
};

}

#endif /* MESSAGETYPEV0_H_ */
