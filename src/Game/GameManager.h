/*
 * GameManager.h
 *
 *  Created on: 22 nov. 2010
 *      Author: fenax
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <vector>
#include <deque>
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
	std::deque<Actor> actors_;//TODO maybe use a list
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
    void giveActiveSpells(std::vector<boost::int8_t> active_spells);
    void giveRawMessage(std::string message);
    void giveNewMap(std::string map);
    virtual void giveNewActor(Actor& actor);
    virtual void giveNewActor(EnhancedActor& actor);

    void giveRemoveActor(boost::int16_t id);
    void giveActorCommand(boost::int16_t id, boost::int8_t command);

    Actor& getActor(boost::int16_t id);

    Player& getPlayer();



};

}

#endif /* GAMEMANAGER_H_ */
