/*
 * GameManager.c++
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#include <iostream>

#include "GameManager.h"

namespace Game
{

GameManager::GameManager()
{
	// TODO Auto-generated constructor stub

}

GameManager::~GameManager()
{
	// TODO Auto-generated destructor stub
}

void
GameManager::giveError(std::string type, std::string message){
	std::cout << "error, could not " << type << " : " << message << std::endl;
}

void
GameManager::giveOk(std::string type, std::string message){
	std::cout << type << "Ok " << " : " << message << std::endl;
}

void
GameManager::giveRawMessage(std::string message){
	std::cout << message << std::endl;
}

void
GameManager::givePlayerId(boost::int64_t player_id){
	player_id_ = player_id;
	std::cout << "player id is : " << player_id << std::endl;
}

void
GameManager::giveTime(boost::int8_t hour, boost::int8_t minute){
	hour_ = hour;
	minute_ = minute;
	std::cout << "time changed to : " << (int)hour << ":" << (int)minute << std::endl;
}

void
GameManager::giveSigils(boost::int32_t sigils){
	player_.setSigils(sigils);
	std::cout << "sigils are " << sigils << std::endl;
}

void
GameManager::giveActiveSpells(std::vector<boost::int8_t> active_spells){
	player_.setActiveSpells(active_spells);
	std::cout << "active spells set \n";
}

Player&
GameManager::getPlayer(){
	std::cout << "player requested \n";
	return player_;
}

void
GameManager::giveNewMap(std::string map){
	std::cout << "going to new map : " << map << std::endl;
	//TODO Actually do something.
}

void
GameManager::giveNewActor(Actor& actor){
	if(actor.getId() == player_id_){
		player_.setAll(dynamic_cast<EnhancedActor&>(actor));
		std::cout << "Added player actor : " << actor.getName() << std::endl;
	}else{
		actors_.push_back(actor);
		std::cout << "Added non player actor : " << actor.getName() << std::endl;
	}
}



}



