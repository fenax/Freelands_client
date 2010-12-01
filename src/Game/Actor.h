/*
 * Actor.h
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <boost/cstdint.hpp>

#include <OgreEntity.h>

namespace Game
{

class Actor
{
public:
	Actor();
	Actor(	boost::int16_t id, bool visible_,
			boost::int16_t position_x,	boost::int16_t position_y,	boost::int16_t position_z,
			boost::int16_t rotation_z,
			boost::uint8_t actor_race, boost::uint8_t actor_frame,
			boost::int16_t actor_life, boost::int16_t actor_type,
			std::string actor_name, boost::int16_t actor_scalability);
	virtual ~Actor();

private:
	Ogre::Entity* entity;

	boost::int16_t id_;

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
};

}

#endif /* ACTOR_H_ */
