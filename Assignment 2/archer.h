////////////////////////////////////////////////////////////////////
// Name : Elizabeth Esede
// Email : eesede@myseneca.ca
// Student ID: 120651245
// Date Completed: 2025-10-11
//////////////////////////////////
// I declare that this submission is the result of my own work 
// and I only copied the code that my professor provided to complete
// my assignments.This submitted piece of work has not been shared 
// with any other student or 3rd party content provider.
////////////////////////////////////////////////////////////////////

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include <string>
#include "characterTpl.h"
#include "character.h"

namespace seneca {

	template<typename Weapon_t>
	class Archer : public CharacterTpl<seneca::SuperHealth>{

		size_t m_baseDefense{};
		size_t m_baseAttack{};
		Weapon_t m_weapon{};

	public:
		Archer() {};
		Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;
		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg);


	};

	template<typename Weapon_t>
	inline Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
		:CharacterTpl<seneca::SuperHealth>(name,healthMax)
	{
		m_baseAttack = baseAttack;
		m_baseDefense = baseDefense;
		m_weapon = weapon;

	}

	template<typename Weapon_t>
	inline int Archer<Weapon_t>::getAttackAmnt() const
	{

		int dmg = 1.3 * m_baseAttack;

		return dmg;
	}

	template<typename Weapon_t>
	inline int Archer<Weapon_t>::getDefenseAmnt() const
	{

		int def = 1.2 * m_baseDefense;
		return def;
	}

	template<typename Weapon_t>
	inline Character* Archer<Weapon_t>::clone() const
	{
		Archer* a = new Archer<Weapon_t>(*this);

		return a;
	}

	template<typename Weapon_t>
	inline void Archer<Weapon_t>::attack(Character* enemy)
	{
		std::cout << this->getName() << " is attacking " << enemy->getName() << std::endl;

		int enhDmg = getAttackAmnt();
		
		std::cout << "Archer deals " << enhDmg << " ranged damage!" << std::endl;

		enemy->takeDamage(enhDmg);
	}

	template<typename Weapon_t>
	inline void Archer<Weapon_t>::takeDamage(int dmg)
	{

		std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;

		int blockedDmg = dmg - getDefenseAmnt();

		if (blockedDmg < 0) {
			blockedDmg = 0;
		}

		CharacterTpl<seneca::SuperHealth>::takeDamage(blockedDmg);

	}

}
#endif // !SENECA_ARCHER_H
