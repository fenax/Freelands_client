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
 * Class representing an actor header.
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <boost/cstdint.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <OgreEntity.h>

namespace Game
{

class Actor
{

protected:
	Ogre::Entity* entity_;

	boost::int16_t id_;

	boost::int8_t current_action_;//TODO maybe an queue
	boost::posix_time::ptime start_time;

	boost::int16_t position_x_;
	boost::int16_t position_y_;
	boost::int16_t position_z_;

	boost::int16_t rotation_z_;

	boost::uint8_t actor_race_;
	boost::uint8_t actor_frame_;

	boost::int16_t actor_life_;
	boost::int16_t actor_type_;

	std::string actor_name_;
	boost::int16_t actor_scalability_;

	bool visible_;
public:
	Actor();
	Actor(	boost::int16_t id, bool visible,
			boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
			boost::int16_t rotation_z,
			boost::uint8_t actor_race, boost::uint8_t actor_frame,
			boost::int16_t actor_life, boost::int16_t actor_type,
			std::string& actor_name, boost::int16_t actor_scalability);
	virtual ~Actor();

	void setAll(boost::int16_t id, bool visible,
			boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
			boost::int16_t rotation_z,
			boost::uint8_t actor_race, boost::uint8_t actor_frame,
			boost::int16_t actor_life, boost::int16_t actor_type,
			std::string& actor_name, boost::int16_t actor_scalability);

	boost::int16_t getId();
	std::string& getName();
	void setAction(int action);
	void finishAction();

	virtual void tick();

};

}

#endif /* ACTOR_H_ */
