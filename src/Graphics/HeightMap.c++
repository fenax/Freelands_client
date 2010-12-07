/* 
 * File:   HeightMap.c++
 * Author: fenax
 * 
 * Created on 7 décembre 2010, 09:16
 */

#include "HeightMap.h"
#include <OGRE/OgreMeshManager.h>
#include <OGRE/OgreMaterialManager.h>
#include <OGRE/OgreTextureManager.h>
#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <OGRE/OgreTechnique.h>

using namespace Ogre;

HeightMap::HeightMap(int width, int height, int tile_size) {
    width_ = width;
    height_ = height;
    tile_size_ = tile_size;

    array_width_ = width_ * tile_size + 1;
    array_height_ = height_ * tile_size + 1;

    height_map_ = new [array_height_][array_width_] float;
    texture_map_ = new [height_][width_] size_t;
}

float HeightMap::ElmToAltitude(int alt){
    return (alt - elm_base_altitude) * altitude_unit;
}

void
HeightMap::BuildFromElmArray(char * orig_map, char * orig_texture_map){
    int orig_array_width = array_width_ - 1;
    int orig_array_height = array_height_ - 1;
    //Corners
    height_map_[0][0] = ElmToAltitude(orig_map[0]);
    height_map_[0][array_width_-1] = ElmToAltitude(orig_map[orig_array_width-1]);
    height_map_[array_height_-1][0] =
            ElmToAltitude(orig_map[orig_array_width*(orig_array_height-1)]);
    height_map_[array_height_-1][array_width_] =
            ElmToAltitude(orig_map[orig_array_height*orig_array_width-1]);

    //Borders
    //top and bottom.
    for(int i = 1; i < array_width_ - 2; i++){
        height_map_[0][i] = ( ElmToAltitude(orig_map[i-1])
                     + ElmToAltitude(orig_map[i])
                     )  / 2.0;
        height_map_[array_height_ - 1][i] =
                     ( ElmToAltitude(
                         orig_map[orig_array_width*(orig_array_height-1)+i-1])
                     + ElmToAltitude(
                         orig_map[orig_array_width*(orig_array_height-1)+i])
                     )  / 2.0;
    }
    //left and right
    for(int i = 1; i < array_height_ - 2; i++){
        height_map_[i][0] = ( ElmToAltitude(orig_map[(i-1)*orig_array_width])
                     + ElmToAltitude(orig_map[(i)*orig_array_width])
                     ) / 2.0;
        height_map_[i][array_width_-1] =
                     ( ElmToAltitude(
                        orig_map[(i-1)*orig_array_width+orig_array_width-1])
                     * ElmToAltitude(
                        orig_map[(i)*orig_array_width+orig_array_width-1])
                     ) / 2.0;
    }

    //Middle
    for(int i = 1; i < array_height_ - 2; i++){
        for(int j = 1; j < array_width_ - 2; j++){
            height_map_[i][j] =
                    (
                      ElmToAltitude(orig_map[i-1 + orig_array_width*(j-1)])
                    + ElmToAltitude(orig_map[i-1 + orig_array_width*(j  )])
                    + ElmToAltitude(orig_map[i   + orig_array_width*(j-1)])
                    + ElmToAltitude(orig_map[i   + orig_array_width*(j  )])
                    ) / 4.0;
        }
    }


    std::map<size_t,size_t> texture_id_association;
    size_t x = 0;
    for(size_t i = 0; i<height_-1; i++){
        for(size_t j = 0; j<width_-1; j++){
            size_t current;
            try{
                current = texture_id_association.at(orig_texture_map[i][j]);
            }catch(std::out_of_range error){
                texture_id_association[orig_texture_map[i][j]] = x;
                current = x;
                x++;
            }
            texture_map_[i][j] = current;
        }
    }
    textures_.reserve(x);
    for(std::map<size_t,size_t>::iterator it = texture_id_association.begin();
            it != texture_id_association.end();
            it++){
        char temp[20];
        sprintf(temp,"tiles/tile%2d.bmp", it->first);
        textures_[it->second] =  new String(temp);
    }

}

MeshPtr
HeightMap::BuildMesh(){
    MeshPtr mesh = MeshManager::getSingleton().createManual("Heightmap", "Map");
    SubMesh* sub_mesh = mesh->createSubMesh();

    size_t nVertices = array_height_*array_width_;
    size_t vertex_size = 3+3+2;
    size_t vertex_buffer_size = vertex_size*nVertices;
    float vertex_buffer[vertex_buffer_size];
    size_t vertex_buffer_cursor = 0;

    for(int i = 0; i < array_height_; i++){
        for(int j = 0; j < array_width_; j++){
            // X position
            vertex_buffer[vertex_buffer_cursor + 0] = j * 0.5;
            // Y position
            vertex_buffer[vertex_buffer_cursor + 1] = height_map_[i][j];
            // Z position
            vertex_buffer[vertex_buffer_cursor + 2] = i * -0.5;


            // X Y Z normal
            if(i==0 || j==0 || i==array_height_-1 || j==array_width_-1){
                //lazy method, we do not calculate, normal is "up"
                vertex_buffer[vertex_buffer_cursor + 3] = 0.0;
                vertex_buffer[vertex_buffer_cursor + 4] = 1.0;
                vertex_buffer[vertex_buffer_cursor + 5] = 0.0;
            }else{
                float delta_y_x = map[i][j-1] - map[i][j+1];
                float delta_y_z = map[i+1][j] - map[i-1][j];
                float magnitude =
                        sqrt(delta_y_x*delta_y_x + delta_y_z*delta_y_z + 1.0f);


                vertex_buffer[vertex_buffer_cursor + 3] = delta_y_x/magnitude;
                vertex_buffer[vertex_buffer_cursor + 4] = 1.0/magnitude;
                vertex_buffer[vertex_buffer_cursor + 5] = delta_y_z/magnitude;
            }

            // Texture X,Y

            vertex_buffer[vertex_buffer_cursor + 6] =
                    (1.0 / tile_size_) * (j%tile_size_);
            vertex_buffer[vertex_buffer_cursor + 7] =
                    (1.0 / tile_size_) * (i%tile_size_);

            vertex_buffer_cursor += vertex_size;
        }
    }

    for(int i = 0; i < textures_.size(); i++){
        MaterialPtr material =
                MaterialManager::getSingleton().create("material"+i,"Map");
        TexturePtr texture =
                TextureManager::getSingleton().prepare(textures_[i],"Map");

        material->getTechnique(0)->getPass(0)
            ->createTextureUnitState(textures_[i]);
        

        for(int y = 0; y < height_; y++){
            for(int x = 0; x < width_; x++){
                if(texture_map_[y][x] == i){
                    for(int y_tile = 0; y_tile < tile_size_; y_tile++){
                        for(int x_tile = 0; x_tile < tile_size_; x_tile++){

                        }
                    }
                }
            }
        }
    }

}


//HeightMap::HeightMap(const HeightMap& orig) {
//}

HeightMap::~HeightMap() {
    delete [] height_map_;
}

