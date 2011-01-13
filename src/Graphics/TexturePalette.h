/* 
 * File:   TexturePalette.h
 * Author: fenax
 *
 * Created on 7 décembre 2010, 09:19
 */

#ifndef TEXTUREPALETTE_H
#define	TEXTUREPALETTE_H

#include <string>

#include <OGRE/OgreTexture.h>

class TexturePalette {
private:
    std::string prepend;
    std::string append;
    std::vector<Ogre::Texture> palette;
public:
    TexturePalette();
    virtual ~TexturePalette();

    Ogre::Texture& getTexture(int id);
};

#endif	/* TEXTUREPALETTE_H */

