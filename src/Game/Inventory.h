/*
 * Inventory.h
 *
 *  Created on: 1 déc. 2010
 *      Author: fenax
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <Game/InventoryItem.h>

namespace Game
{

class Inventory
{
private:
	InventoryItem * content_;
	int size_;

	void initialize(int size);
public:
	Inventory();
	Inventory(int size);
	virtual ~Inventory();
	virtual InventoryItem& operator[](int i);
	void print();
};

}

#endif /* INVENTORY_H_ */
