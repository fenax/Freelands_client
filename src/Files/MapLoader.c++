/* 
 * File:   ElmLoader.c++
 * Author: fenax
 * 
 * Created on 3 décembre 2010, 17:08
 */

#include "MapLoader.h"
#include "Network/Buffer.h"
#include "Graphics/HeightMap.h"

MapLoader::MapLoader(Game::GameManager & game_manager):FileLoader(game_manager) {
    
}

void
MapLoader::loadFile(std::string filename){
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
    //    char res_2
    //    char res_3
    //    char res_4
    file.consume(3);


    float ambient_r = file.read_float();
    float ambient_g = file.read_float();
    float ambient_b = file.read_float();

    boost::int32_t particles_struct_len = file.read_LE_int32();
    boost::int32_t particles_no = file.read_LE_int32();
    boost::int32_t particles_offset = file.read_LE_int32();

    //    int reserved_8,
    //    int reserved_9,
    //    int reserved_10,
    //    int reserved_11,
    //    int reserved_12,
    //    int reserved_13,
    //    int reserved_14,
    //    int reserved_15,
    //    int reserved_16,
    //    int reserved_17 : 10 entiers réservé pour l'avenir soit 40 octets

    file.pubseekoff(tile_map_offet,std::ios::beg,std::ios::in);
    char texture[tile_map_y_len*tile_map_x_len];
    file.sgetn((char*)texture, tile_map_y_len*tile_map_x_len);
//    for(int y = 0; y < tile_map_y_len; y++){
//        for(int x = 0; x < tile_map_x_len; x++){
//            boost::uint8_t texture = file.read_LE_uint8();
//        }
//    }

    file.pubseekoff(height_map_offset,std::ios::beg,std::ios::in);
    char height[tile_map_y_len*tile_map_x_len*6*6];
    file.sgetn((char*)height, tile_map_y_len*tile_map_x_len*6*6);

//    for(int y = 0; y < tile_map_y_len*6; y++){
//        for(int x = 0; x < tile_map_x_len*6; x++){
//            boost::uint8_t height = file.read_LE_uint8();
//            // la hauteur est comprise entre -2 et +4 m par pas de 0.2m
//            // la hauteur de -2.2m signifie non marchable
//            // il y a 6.2 *0.2 positions soit 31 états différents
//            // en valeur char 0x00 veut dire non marchable,
//            // 0x01 la plus basse hauteur et 0x1f soit 31 la plus haute
//            // 0x0B la valeur standard (soit 11)
//        }
//    }
    // read 3D objects
    for(int i = 0; i < obj_3d_no; i++){
        file.pubseekoff(obj_3d_offset + obj_3d_struct_len*i,
                        std::ios::beg, std::ios::in);
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
    }

    //read 2D objects
    for(int i = 0; i < obj_2d_no; i++){
        file.pubseekoff(obj_2d_offset + obj_2d_struct_len*i,
                        std::ios::beg, std::ios::in);
        std::string filename = file.read_string(80);

        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();

        float x_rot = file.read_float();
        float y_rot = file.read_float();
        float z_rot = file.read_float();
    }

    // Read lights.
    for(int i = 0; i < lights_no; i++){
        file.pubseekoff(lights_offset + lights_struct_len*i,
                        std::ios::beg, std::ios::in);
        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();

        float r = file.read_float();
        float g = file.read_float();
        float b = file.read_float();
    }

    // Read particles.
    for(int i=0; i< particles_no; i++){
        file.pubseekoff(particles_offset + particles_struct_len*i,
                        std::ios::beg, std::ios::in);
        std::string filename = file.read_string(80);

        float x_pos = file.read_float();
        float y_pos = file.read_float();
        float z_pos = file.read_float();
    }
    HeightMap map(tile_map_x_len, tile_map_y_len, 6);
    map.BuildFromElmArray(height,texture);
    map.BuildMesh();
}
