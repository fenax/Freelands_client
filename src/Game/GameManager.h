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
 * General class managing the game header.
 */


#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <vector>
#include <deque>
#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>

#include "Tools/Queue.h"
#include "Game/Actor.h"
#include "Game/Player.h"

namespace Game
{

	class Order
	{
		public:
			virtual bool process()=0;
	};

	class OrderLoadMap : Order
	{
		public:
			std::string filename;
			virtual bool process();
	};

class GameManager : boost::noncopyable
{
private:
	int64_t 		  player_id_;
	std::deque<Actor> actors_;//TODO maybe use a list
	Player 		   	  player_;
	boost::uint8_t 	  hour_;
	boost::uint8_t    minute_;
	boost::shared_ptr<boost::thread> thread_;
	Tools::Queue<Order*>		orders_queue_;



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

	void thread();
	void start();
    void stop();



};

}

#endif /* GAMEMANAGER_H_ */
