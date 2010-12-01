/*
 * Player.c++
 *
 *  Created on: 30 nov. 2010
 *      Author: fenax
 */

#include "Player.h"

namespace Game
{

Player::Player()
{
	// TODO Auto-generated constructor stub

}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

void
Player::setSigils(boost::uint32_t sigils){
	sigils_ = sigils;
}

void
Player::addSigils(boost::uint32_t sigils){
	sigils_ |= sigils;
}

void
Player::removeSigils(boost::uint32_t sigils){
	sigils_ &= ~sigils;
}

bool
Player::haveSigils(boost::uint32_t sigils){
	return sigils_ & sigils;
}

void
Player::setActiveSpells(std::vector<boost::int8_t>& active_spells){
	active_spells_ = active_spells;
}

std::vector<boost::int8_t>&
Player::getActiveSpells(){
	return active_spells_;
}

Inventory&
Player::getInventory(){
	return inventory_;
}

std::vector<bool>&
Player::getKnownledges(){
	return knownledge_;
}


void
Player::setStats(	boost::int16_t phy_current,
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
					boost::int16_t charisma_rank){
	phy_current_ = phy_current;
	phy_base_ = phy_base;
	coord_current_ = coord_current;
	coord_base_ = coord_base;
	reac_current_ = reac_current;
	reac_base_ = reac_base;
	will_current_ = will_current;
	will_base_ = will_base;
	inst_current_ = inst_current;
	inst_base_ = inst_base;
	vit_current_ = vit_current;
	vit_base_ = vit_base;
	//TODO clearer names

	// nexuses


	human_nexus_current_ = human_nexus_current;
	human_nexus_base_ = human_nexus_base;
	animal_nexus_current_ = animal_nexus_current;
	animal_nexus_base_ = animal_nexus_base;
	vegetal_nexus_current_ = vegetal_nexus_current;
	vegetal_nexus_base_ = vegetal_nexus_base;
	inorganic_nexus_current_ = inorganic_nexus_current;
	inorganic_nexus_base_ = inorganic_nexus_base;
	artificial_nexus_current_ = artificial_nexus_current;
	artificial_nexus_base_ = artificial_nexus_base;
	magic_nexus_current_ = magic_nexus_current;
	magic_nexus_base_ = magic_nexus_base;

	// skill levels

	manufacture_current_ = manufacture_current;
	manufacture_base_ = manufacture_base;
	harvest_current_ = harvest_current;
	harvest_base_ = harvest_base;
	alchemy_current_ = alchemy_current;
	alchemy_base_ = alchemy_base;
	overall_current_ = overall_current;
	overall_base_ = overall_base;
	attack_current_ = attack_current;
	attack_base_ = attack_base;
	defence_current_ = defence_current;
	defence_base_ = defence_base;
	magic_current_ = magic_current;
	magic_base_ = magic_base;
	potion_current_ = potion_current;
	potion_base_ = potion_base;

	carry_current_ = carry_current;
	carry_base_ = carry_base;
	health_current_ = health_current;
	health_base_ = health_base;
	mana_current_ = mana_current;
	mana_base_ = mana_base;

	food_level_ = food_level;


	manufacture_exp_ = manufacture_exp;
	manufacture_next_level_ = manufacture_next_level;
	harvest_exp_ = harvest_exp;
	harvest_next_level_ = harvest_next_level;
	alchemy_exp_ = alchemy_exp;
	alchemy_next_level_ = alchemy_next_level;
	overall_exp_ = overall_exp;
	overall_next_level_ = overall_next_level;
	attack_exp_ = attack_exp;
	attack_next_level_ = attack_next_level;
	defence_exp_ = defence_exp;
	defence_next_level_ = defence_next_level;
	magic_exp_ = magic_exp;
	magic_next_level_ = magic_next_level;
	potion_exp_ = potion_exp;
	potion_next_level_ = potion_next_level;

	summon_current_ = summon_current;
	summon_base_ = summon_base;
	summon_exp_ = summon_exp;
	summon_next_level_ = summon_next_level;

	crafting_current_ = crafting_current;
	crafting_base_ = crafting_base;
	exp_ = exp;
	next_level_ = next_level;


	charisma_ = charisma;
	religion_ = religion;
	religion_level_ = religion_level;
	race_ = race;
	charisma_next_ = charisma_next;
	charisma_level_ = charisma_level;
	charisma_rank_ = charisma_rank;
}
}

