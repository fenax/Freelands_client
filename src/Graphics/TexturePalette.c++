/* 
 * File:   TexturePalette.c++
 * Author: fenax
 * 
 * Created on 7 décembre 2010, 09:19
 */

#include "TexturePalette.h"
using namespace std;
using namespace Ogre;

TexturePalette::TexturePalette() {
    palette = vector<Texture>(1000);
}

TexturePalette::~TexturePalette() {
}

Ogre::Texture&
TexturePalette::getTexture(int id){
    if(id < 1000 && id >=0){
        
    }
}
