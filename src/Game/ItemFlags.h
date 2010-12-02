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
 * Item flags constants.
 */


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
