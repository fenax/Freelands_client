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
 * Class to represent the items in the player's inventory header.
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
