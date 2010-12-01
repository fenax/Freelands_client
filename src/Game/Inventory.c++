/*
 * Inventory.c++
 *
 *  Created on: 1 déc. 2010
 *      Author: fenax
 */

#include <iostream>

#include "Inventory.h"

namespace Game
{
void Inventory::initialize(int size){
	content_ = new InventoryItem[size];
	size_ = size;
}

Inventory::Inventory()
{
	initialize(44);
}

Inventory::Inventory(int size){
	initialize(size);
}

Inventory::~Inventory()
{
	//No warning, just a segfault if you forget the [] part
	delete [] content_;
}

InventoryItem&
Inventory::operator[](int i){
	//TODO replace with an exception
	return content_[(i<size_)?i:0];
}

void
Inventory::print(){
	for(int i = 0; i < size_; i++ ){
		int quantity = content_[i].getQuantity();
		std::cout << "Slot " << i << " : ";
		if (quantity > 0) {
			std::cout << quantity
					  << " : "
					  << content_[i].getId()
					  << " : "
					  << content_[i].getFlags();
		}else{
			std::cout << "Empty";
		}
		std::cout << std::endl;
	}
}
}
