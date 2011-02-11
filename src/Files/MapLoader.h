/* 
 * File:   ElmLoader.h
 * Author: fenax
 *
 * Created on 3 décembre 2010, 17:08
 */

#ifndef ELMLOADER_H
#define	ELMLOADER_H

#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "FileLoader.h"
#include "Graphics/HeightMap.h"


class MapLoader : public FileLoader{
public:
    MapLoader(/*Game::GameManager & game_manager*/);
    virtual void loadFile(std::string filename);

    virtual void loadMap(std::string filename, Ogre::SceneNode* new_map, Ogre::SceneManager* scene_manager);
private:

};

#endif	/* ELMLOADER_H */

