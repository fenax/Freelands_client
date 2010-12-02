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
 * Class representing an actor implementation.
 */

#include "Actor.h"

namespace Game
{

Actor::Actor():
		current_action_(0)
{
	// TODO Auto-generated constructor stub

}

Actor::Actor(	boost::int16_t id, bool visible,
		boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
		boost::int16_t rotation_z,
		boost::uint8_t actor_race, boost::uint8_t actor_frame,
		boost::int16_t actor_life, boost::int16_t actor_type,
		std::string& actor_name, boost::int16_t actor_scalability):current_action_(0){

	id_ = id;

	position_x_ = position_x;
	position_y_ = position_y;
	position_z_ = position_z;

	rotation_z_ = rotation_z;

	actor_race_ = actor_race;
	actor_frame_ = actor_frame;

	actor_life_ = actor_life;
	actor_type_ = actor_type;

	actor_name_ = actor_name;
	actor_scalability_ = actor_scalability;

	visible_ = visible;

}

void
Actor::setAll(	boost::int16_t id, bool visible,
		boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
		boost::int16_t rotation_z,
		boost::uint8_t actor_race, boost::uint8_t actor_frame,
		boost::int16_t actor_life, boost::int16_t actor_type,
		std::string& actor_name, boost::int16_t actor_scalability){

	id_ = id;

	position_x_ = position_x;
	position_y_ = position_y;
	position_z_ = position_z;

	rotation_z_ = rotation_z;

	actor_race_ = actor_race;
	actor_frame_ = actor_frame;

	actor_life_ = actor_life;
	actor_type_ = actor_type;

	actor_name_ = actor_name;
	actor_scalability_ = actor_scalability;

	visible_ = visible;
}

Actor::~Actor()
{
	// TODO Auto-generated destructor stub
}

boost::int16_t
Actor::getId(){
	return id_;
}
std::string&
Actor::getName(){
	return actor_name_;
}

void
Actor::setAction(int action){//check for still running action and stuff;
	current_action_ = action;
	start_time = boost::posix_time::microsec_clock::universal_time();
}

void
Actor::finishAction(){
	//TODO write
}

void
Actor::tick(){
	//TODO write
}

}


