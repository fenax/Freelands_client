namespace Protocol{
	enum MessageTypeToServer{
		RAW_TEXT = 0,
		MOVE_TO = 1,
		SEND_PM = 2,
		GET_PLAYER_INFO = 5,
		RUN_TO = 6,
		SIT_DOWN = 7,
		SEND_ME_MY_ACTORS = 8,
		SEND_OPENING_SCREEN = 9,
		SEND_VERSION = 10,
		TURN_LEFT = 11,
		TURN_RIGHT = 12,
		PING = 13,
		HEART_BEAT = 14,
		LOCATE_ME = 15,
		USE_MAP_OBJECT = 16,
		SEND_MY_STATS = 17,
		SEND_MY_INVENTORY = 18,
		LOOK_AT_INVENTORY_ITEM = 19,
		MOVE_INVENTORY_ITEM = 20,
		HARVEST = 21,
		DROP_ITEM = 22,
		PICK_UP_ITEM = 23,
		LOOK_AT_GROUND_ITEM = 24,
		INSPECT_BAG = 25,
		S_CLOSE_BAG = 26,
		LOOK_AT_MAP_OBJECT = 27,
		TOUCH_PLAYER = 28,
		RESPOND_TO_NPC = 29,
		MANUFACTURE_THIS = 30,
		USE_INVENTORY_ITEM = 31,
		TRADE_WITH = 32,
		ACCEPT_TRADE = 33,
		REJECT_TRADE = 34,
		EXIT_TRADE = 35,
		PUT_OBJECT_ON_TRADE = 36,
		REMOVE_OBJECT_FROM_TRADE = 37,
		LOOK_AT_TRADE_ITEM = 38,
		CAST_SPELL = 39,
		ATTACK_SOMEONE = 40,
		GET_KNOWLEDGE_INFO = 41,
		ITEM_ON_ITEM = 42,
		SEND_BOOK = 43,
		GET_STORAGE_CATEGORY = 44,
		DEPOSITE_ITEM = 45,
		WITHDRAW_ITEM = 46,
		LOOK_AT_STORAGE_ITEM = 47,
		SPELL_NAME = 48,
		SALUT = 49,
		PING_RESPONSE = 60,
		SET_ACTIVE_CHANNEL = 61,
		LOG_IN = 140,
		CREATE_CHAR = 141,
		GET_DATE = 230,
		GET_TIME = 231,
		SERVER_STATS = 232,
		ORIGINAL_IP = 233,
		BYE = 255
	};
}