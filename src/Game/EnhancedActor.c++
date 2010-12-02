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
 * Class representing an humanoid actor implementation.
 */

#include "EnhancedActor.h"

namespace Game
{

EnhancedActor::EnhancedActor()
{
	// TODO Auto-generated constructor stub

}

EnhancedActor::EnhancedActor(	boost::int16_t id, bool visible,
		boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
		boost::int16_t rotation_z,
		boost::uint8_t actor_race, boost::uint8_t actor_frame,
		boost::int16_t actor_type,
		std::string& actor_name, boost::int16_t actor_scalability,
		boost::int8_t skin, boost::int8_t hair,
		boost::int8_t shirt, boost::int8_t pants, boost::int8_t boots,
		boost::int8_t head, boost::int8_t shield, boost::int8_t weapon,
		boost::int8_t cape,	boost::int8_t helmet,
		boost::int16_t health_base, boost::int16_t health_cur):
		Actor(id, visible, position_x, position_y, position_z, rotation_z,
				actor_race, actor_frame, (health_base==0)?0:(health_cur*4/health_base),
				actor_type, actor_name, actor_scalability){
	skin_ = skin;
	hair_ = hair;
	shirt_ = shirt;
	pants_ = pants;
	boots_ = boots;
	head_ = head;
	shield_ = shield;
	weapon_ = weapon;
	cape_ = cape;
	helmet_ = helmet;
	health_base_ = health_base;
	health_cur_ = health_cur;
}

void
EnhancedActor::setAll(	boost::int16_t id, bool visible,
		boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
		boost::int16_t rotation_z,
		boost::uint8_t actor_race, boost::uint8_t actor_frame,
		boost::int16_t actor_type,
		std::string& actor_name, boost::int16_t actor_scalability,
		boost::int8_t skin, boost::int8_t hair,
		boost::int8_t shirt, boost::int8_t pants, boost::int8_t boots,
		boost::int8_t head, boost::int8_t shield, boost::int8_t weapon,
		boost::int8_t cape,	boost::int8_t helmet,
		boost::int16_t health_base, boost::int16_t health_cur){
	Actor::setAll(id, visible, position_x, position_y, position_z, rotation_z,
					actor_race, actor_frame, (health_base==0)?0:(health_cur*4/health_base),
					actor_type, actor_name, actor_scalability);
	skin_ = skin;
	hair_ = hair;
	shirt_ = shirt;
	pants_ = pants;
	boots_ = boots;
	head_ = head;
	shield_ = shield;
	weapon_ = weapon;
	cape_ = cape;
	helmet_ = helmet;
	health_base_ = health_base;
	health_cur_ = health_cur;
}


EnhancedActor::~EnhancedActor()
{
	// TODO Auto-generated destructor stub
}

}
