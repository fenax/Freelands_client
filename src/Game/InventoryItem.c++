/*
 * InventoryItem.c++
 *
 *  Created on: 1 déc. 2010
 *      Author: fenax
 */

#include "InventoryItem.h"

namespace Game
{

InventoryItem::InventoryItem():
		id_(0),
		quantity_(0),
		flags_(0)
{
	// TODO Auto-generated constructor stub

}

InventoryItem::~InventoryItem()
{
	// TODO Auto-generated destructor stub
}

void
InventoryItem::setAll(boost::int16_t id,boost::int32_t quantity,boost::int8_t flags){

}

boost::int16_t
InventoryItem::getId(){
	return id_;
}

boost::int32_t
InventoryItem::getQuantity(){
	return quantity_;
}

boost::int8_t
InventoryItem::getFlags(){
	return flags_;
}

bool
InventoryItem::haveFlag(int flags){
	return flags & flags_;
}

}
