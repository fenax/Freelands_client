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
 * Class to represent the player's inventory implementation.
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
