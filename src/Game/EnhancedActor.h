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
 * Class representing an humanoid actor header.
 */

#ifndef ENHANCEDACTOR_H_
#define ENHANCEDACTOR_H_

#include "Actor.h"

namespace Game
{

class EnhancedActor: public Game::Actor
{
	boost::int8_t skin_;
	boost::int8_t hair_;

	boost::int8_t shirt_;
	boost::int8_t pants_;
	boost::int8_t boots_;
	boost::int8_t head_;
	boost::int8_t shield_;
	boost::int8_t weapon_;
	boost::int8_t cape_;
	boost::int8_t helmet_;

	boost::int16_t health_base_;
	boost::int16_t health_cur_;

public:
	EnhancedActor();
	EnhancedActor(
			boost::int16_t id, bool visible_,
			boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
			boost::int16_t rotation_z,
			boost::uint8_t actor_race, boost::uint8_t actor_frame,
			boost::int16_t actor_type,
			std::string& actor_name, boost::int16_t actor_scalability,
			boost::int8_t skin, boost::int8_t hair,
			boost::int8_t shirt, boost::int8_t pants, boost::int8_t boots,
			boost::int8_t head, boost::int8_t shield, boost::int8_t weapon,
			boost::int8_t cape,	boost::int8_t helmet,
			boost::int16_t health_base, boost::int16_t health_cur);

	void setAll(	boost::int16_t id, bool visible_,
					boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
					boost::int16_t rotation_z,
					boost::uint8_t actor_race, boost::uint8_t actor_frame,
					boost::int16_t actor_type,
					std::string& actor_name, boost::int16_t actor_scalability,
					boost::int8_t skin, boost::int8_t hair,
					boost::int8_t shirt, boost::int8_t pants, boost::int8_t boots,
					boost::int8_t head, boost::int8_t shield, boost::int8_t weapon,
					boost::int8_t cape,	boost::int8_t helmet,
					boost::int16_t health_base, boost::int16_t health_cur);

	void setAll(EnhancedActor& enhanced_actor){
		setAll(enhanced_actor.id_, enhanced_actor.visible_,
				enhanced_actor.position_x_, enhanced_actor.position_y_, enhanced_actor.position_z_,
				enhanced_actor.rotation_z_,
				enhanced_actor.actor_race_, enhanced_actor.actor_frame_,
				enhanced_actor.actor_type_,
				enhanced_actor.actor_name_, enhanced_actor.actor_scalability_,
				enhanced_actor.skin_, enhanced_actor.hair_,
				enhanced_actor.shirt_, enhanced_actor.pants_,
				enhanced_actor.boots_, enhanced_actor.head_,
				enhanced_actor.shield_, enhanced_actor.weapon_,
				enhanced_actor.cape_, enhanced_actor.helmet_,
				enhanced_actor.health_base_, enhanced_actor.health_cur_);
	}

	virtual ~EnhancedActor();
};

}

#endif /* ENHANCEDACTOR_H_ */
