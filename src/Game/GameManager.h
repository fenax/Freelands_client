/*
 * GameManager.h
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Tools/Queue.h"

#include "Message.h"
#include <boost/noncopyable.hpp>

namespace Game
{

class GameManager : boost::noncopyable
{
private:
	Tools::Queue<Message> receiving_queue_;
//	Tools::Queue<Message> sending_queue_;//TODO add priorities
public:
	GameManager();
	virtual ~GameManager();

	void giveError(std::string type, std::string message="");
	void giveOk(std::string type, std::string message="");
	//void giverError(enum , string)
};

}

#endif /* GAMEMANAGER_H_ */
