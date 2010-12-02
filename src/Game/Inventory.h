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
 * Class to represent the player's inventory header.
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
