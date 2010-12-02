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
 * Messages types sent by the client constants.
 */


#ifndef PROTOCOL_MESSAGE_TYPE_TO_SERVER_V0
#define PROTOCOL_MESSAGE_TYPE_TO_SERVER_V0

namespace Protocol{
	class MessageTypeToServerV0{
	public:
		static const int
		CTS_RAW_TEXT = 0,
		CTS_MOVE_TO = 1,
		CTS_SEND_PM = 2,
		CTS_GET_PLAYER_INFO = 5,
		CTS_RUN_TO = 6,
		CTS_SIT_DOWN = 7,
		CTS_SEND_ME_MY_ACTORS = 8,
		CTS_SEND_OPENING_SCREEN = 9,
		CTS_SEND_VERSION = 10,
		CTS_TURN_LEFT = 11,
		CTS_TURN_RIGHT = 12,
		CTS_PING = 13,
		CTS_HEART_BEAT = 14,
		CTS_LOCATE_ME = 15,
		CTS_USE_MAP_OBJECT = 16,
		CTS_SEND_MY_STATS = 17,
		CTS_SEND_MY_INVENTORY = 18,
		CTS_LOOK_AT_INVENTORY_ITEM = 19,
		CTS_MOVE_INVENTORY_ITEM = 20,
		CTS_HARVEST = 21,
		CTS_DROP_ITEM = 22,
		CTS_PICK_UP_ITEM = 23,
		CTS_LOOK_AT_GROUND_ITEM = 24,
		CTS_INSPECT_BAG = 25,
		CTS_S_CLOSE_BAG = 26,
		CTS_LOOK_AT_MAP_OBJECT = 27,
		CTS_TOUCH_PLAYER = 28,
		CTS_RESPOND_TO_NPC = 29,
		CTS_MANUFACTURE_THIS = 30,
		CTS_USE_INVENTORY_ITEM = 31,
		CTS_TRADE_WITH = 32,
		CTS_ACCEPT_TRADE = 33,
		CTS_REJECT_TRADE = 34,
		CTS_EXIT_TRADE = 35,
		CTS_PUT_OBJECT_ON_TRADE = 36,
		CTS_REMOVE_OBJECT_FROM_TRADE = 37,
		CTS_LOOK_AT_TRADE_ITEM = 38,
		CTS_CAST_SPELL = 39,
		CTS_ATTACK_SOMEONE = 40,
		CTS_GET_KNOWLEDGE_INFO = 41,
		CTS_ITEM_ON_ITEM = 42,
		CTS_SEND_BOOK = 43,
		CTS_GET_STORAGE_CATEGORY = 44,
		CTS_DEPOSITE_ITEM = 45,
		CTS_WITHDRAW_ITEM = 46,
		CTS_LOOK_AT_STORAGE_ITEM = 47,
		CTS_SPELL_NAME = 48,
		CTS_SALUT = 49,
		CTS_PING_RESPONSE = 60,
		CTS_SET_ACTIVE_CHANNEL = 61,
		CTS_LOG_IN = 140,
		CTS_CREATE_CHAR = 141,
		CTS_GET_DATE = 230,
		CTS_GET_TIME = 231,
		CTS_SERVER_STATS = 232,
		CTS_ORIGINAL_IP = 233,
		CTS_BYE = 255;
	};
}

#endif // PROTOCOL_MESSAGE_TYPE_TO_SERVER_V0
