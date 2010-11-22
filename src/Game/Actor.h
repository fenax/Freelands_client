/*
 * Actor.h
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <OgreEntity.h>

namespace Game
{

class Actor
{
public:
	Actor();
	virtual ~Actor();

private:
	Ogre::Entity& entity;

};

}

#endif /* ACTOR_H_ */
