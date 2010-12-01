/*
 * EnhancedActor.c++
 *
 *  Created on: 1 déc. 2010
 *      Author: fenax
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
