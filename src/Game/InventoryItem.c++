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
 * Class to represent the player's actor implementation.
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
