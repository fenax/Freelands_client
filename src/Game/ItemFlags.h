#ifndef GAME_ITEM_FLAGS_H_
#define GAME_ITEM_FLAGS_H_


namespace Game{
class ItemFlags{
	static const int ITEM_REAGENT=1,
					 ITEM_RESOURCE=2,
					 ITEM_STACKABLE=4,
					 ITEM_INVENTORY_USABLE=8,
					 ITEM_TILE_USABLE=16,
					 ITEM_PLAYER_USABLE=32,
					 ITEM_OBJECT_USABLE=64,
					 ITEM_ON_OFF=-128;
};
}

#endif //GAME_ITEM_FLAGS_H_
