/* 
 * File:   ElmLoader.h
 * Author: fenax
 *
 * Created on 3 décembre 2010, 17:08
 */

#ifndef ELMLOADER_H
#define	ELMLOADER_H

#include "FileLoader.h"


class MapLoader : public FileLoader{
public:
    MapLoader(Game::GameManager & game_manager);
    virtual void loadFile(std::string filename);

private:

};

#endif	/* ELMLOADER_H */

