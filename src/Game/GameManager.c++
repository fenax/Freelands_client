/**
 * @file
 * @author  Guillaume Minet "Fenax" <mail@fenax.name>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * General class managing the game implementation.
 */

#include <iostream>

#include "GameManager.h"

namespace Game
{

	bool
	OrderLoadMap::process(){
//		MapLoader
		return true;
	}


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
		std::cout << "should not get player of Actor type" << std::endl;
	}else{
		actors_.push_back(*new Actor(actor));
		std::cout << "Added non player actor : " << actor.getName() << std::endl;
	}
}

void
GameManager::giveNewActor(EnhancedActor& actor){
	if(actor.getId() == player_id_){
		player_.setAll(actor);
		std::cout << "Added player actor : " << actor.getName() << std::endl;
	}else{
		actors_.push_back(*new Actor(actor));
		std::cout << "Added non player actor : " << actor.getName() << std::endl;
	}
}


void
GameManager::giveRemoveActor(boost::int16_t id){
	for( std::deque<Actor>::iterator it = actors_.begin(); it != actors_.end() ; it++){
		if( it->getId() == id ){
			std::cout << "deleting actor : " << it->getName() << ":" << it->getId() << std::endl;
			actors_.erase(it);//also delete the element
			return;
		}
	}
	std::cout << "could not find actor " <<id <<" to delete \n";
}

void
GameManager::giveActorCommand(boost::int16_t id,boost::int8_t command){
	for( std::deque<Actor>::iterator it = actors_.begin(); it != actors_.end() ; it++){
		if( it->getId() == id ){
			std::cout << "giving actor : " << it->getName() << ":" << it->getId() << " command : " << (int)command << std::endl;
			it->setAction(command);
			return;
		}
	}
	std::cout << "could not find actor to give command \n";
}

void
GameManager::thread(){
	while(1){
		Order* order = orders_queue_.blockingPop();
		if(!order->process()){
			break;
		}
	}
}


void
GameManager::start(){
    assert(!thread_);
	thread_ = boost::shared_ptr<boost::thread>(
			new boost::thread(
					boost::bind(&GameManager::thread, this)));
}
void
GameManager::stop(){
	assert(thread_);
//	stoprequested_ = true;
//	TODO put stop order in queue
	thread_->join();
}

}



