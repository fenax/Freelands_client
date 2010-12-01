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
	virtual ~Actor();

private:
	Ogre::Entity* entity;

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
