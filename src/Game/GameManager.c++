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

}
