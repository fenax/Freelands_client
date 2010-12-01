/*
 * InventoryItem.h
 *
 *  Created on: 1 déc. 2010
 *      Author: fenax
 */

#ifndef INVENTORYITEM_H_
#define INVENTORYITEM_H_

#include <boost/cstdint.hpp>


namespace Game
{

class InventoryItem
{
	boost::int16_t id_;
	boost::int32_t quantity_;
//	boost::int8_t  item_position on est dans l'inventaire, on le saura bien ou c'est !
	boost::int8_t  flags_;

public:
	InventoryItem();
	virtual ~InventoryItem();
	void setAll(boost::int16_t,boost::int32_t,boost::int8_t);

	boost::int16_t getId();
	boost::int32_t getQuantity();

	boost::int8_t  getFlags();
	bool haveFlag(int);
};

}

#endif /* INVENTORYITEM_H_ */
