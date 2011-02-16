/* 
 * File:   ElmLoader.c++
 * Author: fenax
 * 
 * Created on 3 décembre 2010, 17:08
 */

#include "MapLoader.h"
#include "Network/Buffer.h"

MapLoader::MapLoader(/*Game::GameManager & game_manager*/):FileLoader(/*game_manager*/) {
    
}

void
MapLoader::loadFile(std::string filename){

}

void
MapLoader::loadMap(std::string filename, Ogre::SceneNode* new_map, Ogre::SceneManager* scene_manager){
    Network::Buffer & file = readFile(filename);

    std::string magic = file.read_string(4);
    if(magic.compare("elmf") != 0){
        std::cerr << "incompatible file, could not read\n";
        exit(-1);
        //TODO cleaner thing
    }

    boost::int32_t tile_map_x_len = file.read_LE_int32();
    boost::int32_t tile_map_y_len = file.read_LE_int32();

    boost::int32_t tile_map_offet = file.read_LE_int32();
    boost::int32_t height_map_offset = file.read_LE_int32();

    boost::int32_t obj_3d_struct_len = file.read_LE_int32();
    boost::int32_t obj_3d_no = file.read_LE_int32();
    boost::int32_t obj_3d_offset = file.read_LE_int32();

    boost::int32_t obj_2d_struct_len = file.read_LE_int32();
    boost::int32_t obj_2d_no = file.read_LE_int32();
    boost::int32_t obj_2d_offset = file.read_LE_int32();

    boost::int32_t lights_struct_len = file.read_LE_int32();
    boost::int32_t lights_no = file.read_LE_int32();
    boost::int32_t lights_offset = file.read_LE_int32();

    boost::int8_t dungeon = file.read_LE_int8();

    file.consume(3);


    float ambient_r = file.read_float();
    float ambient_g = file.read_float();
    float ambient_b = file.read_float();

    boost::int32_t particles_struct_len = file.read_LE_int32();
    boost::int32_t particles_no = file.read_LE_int32();
    boost::int32_t particles_offset = file.read_LE_int32();


    file.consume(40);


    // === read textured heightmap
    char texture[tile_map_y_len*tile_map_x_len];
    file.sgetn((char*)texture, tile_map_y_len*tile_map_x_len);

    char height[tile_map_y_len*tile_map_x_len*6*6];
    file.sgetn((char*)height, tile_map_y_len*tile_map_x_len*6*6);

    HeightMap map(tile_map_x_len, tile_map_y_len, 6);
    map.BuildFromElmArray(height,texture);

    Ogre::Entity * entity_map = scene_manager->createEntity(map.BuildMesh()->getName());

    new_map->attachObject(entity_map);

    std::cout <<  obj_3d_offset << " + " << obj_3d_struct_len << " x " << obj_3d_no << std::endl;
    // read 3D objects

    for(int i = 0; i < obj_3d_no; i++){
        std::string filename = file.read_string(80);

        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();

        float x_rot = file.read_float();
        float y_rot = file.read_float();
        float z_rot = file.read_float();

        //sort of glow in the dark
        boost::int8_t self_lit = file.read_LE_int8();
        boost::int8_t blended  = file.read_LE_int8();
        file.consume(2);

        float r = file.read_float();
        float g = file.read_float();
        float b = file.read_float();

        file.consume(24);

        std::cout << "3D object : " << filename << std::endl;
        std::cout << "     x : " << x_pos << " y : " << y_pos << " z : " << z_pos << std::endl;
    }

    //read 2D objects
    for(int i = 0; i < obj_2d_no; i++){
        std::string filename = file.read_string(80);

        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();

        float x_rot = file.read_float();
        float y_rot = file.read_float();
        float z_rot = file.read_float();
        file.consume(24);
        std::cout << "2D object : " << filename << std::endl;
        std::cout << "     x : " << x_pos << " y : " << y_pos << " z : " << z_pos << std::endl;
   }

    // Read lights.
    for(int i = 0; i < lights_no; i++){
        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();

        float r = file.read_float();
        float g = file.read_float();
        float b = file.read_float();
        file.consume(16);
    }

    // Read particles.
    for(int i=0; i< particles_no; i++){
        file.pubseekoff(particles_offset + particles_struct_len*i,
                        std::ios::beg, std::ios::in);
        std::string filename = file.read_string(80);

        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();
        file.consume(12);

    }

}

