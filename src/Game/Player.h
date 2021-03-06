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
 * Class to represent the player's actor header.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include <boost/cstdint.hpp>

#include "Game/Inventory.h"
#include "Game/EnhancedActor.h"

namespace Game
{

class Player: public Game::EnhancedActor
{
private:
	boost::uint32_t sigils_;
	std::vector<boost::int8_t> active_spells_;
	std::vector<bool> knownledge_;



	boost::int16_t phy_current_;
	boost::int16_t phy_base_;
	boost::int16_t coord_current_;
	boost::int16_t coord_base_;
	boost::int16_t reac_current_;
	boost::int16_t reac_base_;
	boost::int16_t will_current_;
	boost::int16_t will_base_;
	boost::int16_t inst_current_;
	boost::int16_t inst_base_;
	boost::int16_t vit_current_;
	boost::int16_t vit_base_;
	//TODO clearer names

	// nexuses


	boost::int16_t human_nexus_current_;
	boost::int16_t human_nexus_base_;
	boost::int16_t animal_nexus_current_;
	boost::int16_t animal_nexus_base_;
	boost::int16_t vegetal_nexus_current_;
	boost::int16_t vegetal_nexus_base_;
	boost::int16_t inorganic_nexus_current_;
	boost::int16_t inorganic_nexus_base_;
	boost::int16_t artificial_nexus_current_;
	boost::int16_t artificial_nexus_base_;
	boost::int16_t magic_nexus_current_;
	boost::int16_t magic_nexus_base_;

	// skill levels

	boost::int16_t manufacture_current_;
	boost::int16_t manufacture_base_;
	boost::int16_t harvest_current_;
	boost::int16_t harvest_base_;
	boost::int16_t alchemy_current_;
	boost::int16_t alchemy_base_;
	boost::int16_t overall_current_;
	boost::int16_t overall_base_;
	boost::int16_t attack_current_;
	boost::int16_t attack_base_;
	boost::int16_t defence_current_;
	boost::int16_t defence_base_;
	boost::int16_t magic_current_;
	boost::int16_t magic_base_;
	boost::int16_t potion_current_;
	boost::int16_t potion_base_;

	boost::int16_t carry_current_;
	boost::int16_t carry_base_;
	boost::int16_t health_current_;
	boost::int16_t health_base_;
	boost::int16_t mana_current_;
	boost::int16_t mana_base_;

	boost::int16_t food_level_;


	boost::int32_t manufacture_exp_;
	boost::int32_t manufacture_next_level_;
	boost::int32_t harvest_exp_;
	boost::int32_t harvest_next_level_;
	boost::int32_t alchemy_exp_;
	boost::int32_t alchemy_next_level_;
	boost::int32_t overall_exp_;
	boost::int32_t overall_next_level_;
	boost::int32_t attack_exp_;
	boost::int32_t attack_next_level_;
	boost::int32_t defence_exp_;
	boost::int32_t defence_next_level_;
	boost::int32_t magic_exp_;
	boost::int32_t magic_next_level_;
	boost::int32_t potion_exp_;
	boost::int32_t potion_next_level_;

	boost::int16_t summon_current_;
	boost::int16_t summon_base_;
	boost::int32_t summon_exp_;
	boost::int32_t summon_next_level_;

	boost::int16_t crafting_current_;
	boost::int16_t crafting_base_;
	boost::int32_t exp_;
	boost::int32_t next_level_;


	boost::int16_t charisma_;
	boost::int16_t religion_;
	boost::int16_t religion_level_;
	boost::int16_t race_;
	boost::int16_t charisma_next_;
	boost::int16_t charisma_level_;
	boost::int16_t charisma_rank_;

	Inventory inventory_;

public:
	Player();
	virtual ~Player();
	void setSigils(boost::uint32_t sigils);
	void addSigils(boost::uint32_t sigils);
	void removeSigils(boost::uint32_t sigils);
	bool haveSigils(boost::uint32_t sigils);
	void setActiveSpells(std::vector<boost::int8_t>& active_spells);
	std::vector<boost::int8_t>& getActiveSpells();
	Inventory& getInventory();
	std::vector<bool>& getKnownledges();

	//TODO make this less huge and fugly
	void setStats(	boost::int16_t phy_current,
					boost::int16_t phy_base,
					boost::int16_t coord_current,
					boost::int16_t coord_base,
					boost::int16_t reac_current,
					boost::int16_t reac_base,
					boost::int16_t will_current,
					boost::int16_t will_base,
					boost::int16_t inst_current,
					boost::int16_t inst_base,
					boost::int16_t vit_current,
					boost::int16_t vit_base,
					boost::int16_t human_nexus_current,
					boost::int16_t human_nexus_base,
					boost::int16_t animal_nexus_current,
					boost::int16_t animal_nexus_base,
					boost::int16_t vegetal_nexus_current,
					boost::int16_t vegetal_nexus_base,
					boost::int16_t inorganic_nexus_current,
					boost::int16_t inorganic_nexus_base,
					boost::int16_t artificial_nexus_current,
					boost::int16_t artificial_nexus_base,
					boost::int16_t magic_nexus_current,
					boost::int16_t magic_nexus_base,
					boost::int16_t manufacture_current,
					boost::int16_t manufacture_base,
					boost::int16_t harvest_current,
					boost::int16_t harvest_base,
					boost::int16_t alchemy_current,
					boost::int16_t alchemy_base,
					boost::int16_t overall_current,
					boost::int16_t overall_base,
					boost::int16_t attack_current,
					boost::int16_t attack_base,
					boost::int16_t defence_current,
					boost::int16_t defence_base,
					boost::int16_t magic_current,
					boost::int16_t magic_base,
					boost::int16_t potion_current,
					boost::int16_t potion_base,
					boost::int16_t carry_current,
					boost::int16_t carry_base,
					boost::int16_t health_current,
					boost::int16_t health_base,
					boost::int16_t mana_current,
					boost::int16_t mana_base,
					boost::int16_t food_level,

					boost::int32_t manufacture_exp,
					boost::int32_t manufacture_next_level,
					boost::int32_t harvest_exp,
					boost::int32_t harvest_next_level,
					boost::int32_t alchemy_exp,
					boost::int32_t alchemy_next_level,
					boost::int32_t overall_exp,
					boost::int32_t overall_next_level,
					boost::int32_t attack_exp,
					boost::int32_t attack_next_level,
					boost::int32_t defence_exp,
					boost::int32_t defence_next_level,
					boost::int32_t magic_exp,
					boost::int32_t magic_next_level,
					boost::int32_t potion_exp,
					boost::int32_t potion_next_level,

					boost::int16_t summon_current,
					boost::int16_t summon_base,
					boost::int32_t summon_exp,
					boost::int32_t summon_next_level,
					boost::int16_t crafting_current,
					boost::int16_t crafting_base,
					boost::int32_t exp,
					boost::int32_t next_level,
					boost::int16_t charisma,
					boost::int16_t religion,
					boost::int16_t religion_level,
					boost::int16_t race,
					boost::int16_t charisma_next,
					boost::int16_t charisma_level,
					boost::int16_t charisma_rank);
};

}

#endif /* PLAYER_H_ */
