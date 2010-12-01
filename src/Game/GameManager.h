/*
 * GameManager.h
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <vector>
#include <boost/noncopyable.hpp>

#include "Tools/Queue.h"
#include "Game/Actor.h"
#include "Game/Player.h"

#include "Message.h"

namespace Game
{

class GameManager : boost::noncopyable
{
private:
	int64_t player_id_;
	std::vector<Actor> actors_;
	Player player_;
	boost::uint8_t hour_;
	boost::uint8_t minute_;

public:
	GameManager();
	virtual ~GameManager();

	void giveError(std::string type, std::string message="");
	void giveOk(std::string type, std::string message="");
	void givePlayerId(boost::int64_t player_id);
    void giveTime(boost::int8_t hour, boost::int8_t minute);
    void giveSigils(boost::int32_t sigils);
    void giveActiveSpells(std::vector<boost::uint8_t> active_spells);
    void giveRawMessage(std::string message);



};

}

#endif /* GAMEMANAGER_H_ */
