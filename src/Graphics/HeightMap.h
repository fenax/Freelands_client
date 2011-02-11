/* 
 * File:   HeightMap.h
 * Author: fenax
 *
 * Created on 7 décembre 2010, 09:16
 */

#ifndef HEIGHTMAP_H
#define	HEIGHTMAP_H

#include <string>
#include <vector>

#include <OgreMesh.h>

#include <Tools/Grid.h>

class HeightMap {
    private:
        int width_;
        int height_;
        int tile_size_;
        int array_width_;
        int array_height_;
        Grid<float> height_map_;
        Grid<size_t> texture_map_;
        std::map<std::size_t, std::string> textures_;

        float ElmToAltitude(int alt);
    public:
        static const float altitude_unit = 0.2f;
        static const int elm_base_altitude = 0x1b;
        
        HeightMap(int width, int height, int tile_size = 6);
        void BuildFromElmArray(char * orig_map, char * orig_texture_map);
        Ogre::MeshPtr BuildMesh();

//        HeightMap(const HeightMap& orig);
        virtual ~HeightMap();


};

#endif	/* HEIGHTMAP_H */

