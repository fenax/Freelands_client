/*
 * GraphicsManager.h
 *
 *  Created on: 16 févr. 2011
 *      Author: fenax
 */

#ifndef GRAPHICSMANAGER_H_
#define GRAPHICSMANAGER_H_

namespace Graphics
{

class GraphicsManager
{
public:
	virtual GraphicsManager()=0;
	virtual ~GraphicsManager()=0;

	virtual void SwitchMap(std::string filename)=0;
	virtual void PlaceOnMap(Game::Actor actor)=0;
};

}

#endif /* GRAPHICSMANAGER_H_ */
