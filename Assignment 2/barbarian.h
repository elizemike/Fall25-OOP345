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

#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include "characterTpl.h"
#include "character.h"
#include <string>

namespace seneca {

	template <typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T> {

		size_t m_baseDefense{};
		size_t m_baseAttack{};
		Ability_t m_ability;
		Weapon_t m_weapon[2];

	public:
		Barbarian() {};
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;
		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg) override;


	};

	template<typename T, typename Ability_t, typename Weapon_t>
	inline Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
		: CharacterTpl<T>(name, healthMax)
	{
		m_baseDefense = baseDefense;
		m_baseAttack = baseAttack;
		
		m_weapon[0] = primaryWeapon;
		m_weapon[1] = secondaryWeapon;

	}

	template<typename T, typename Ability_t, typename Weapon_t>
	inline int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const
	{

		double dmg1 = static_cast<double>(m_weapon[0]);
		double dmg2 = static_cast<double>(m_weapon[1]);

		double total = m_baseAttack + (dmg1 / 2.0) + (dmg2 / 2.0);

		int finalDmg = static_cast<int>(total);

		return finalDmg;
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	inline int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const
	{

		return m_baseDefense;
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	inline Character* Barbarian<T, Ability_t, Weapon_t>::clone() const
	{

		Barbarian* c = new Barbarian<T, Ability_t, Weapon_t>(*this);

		return c;
	}

	template<typename T, typename Ability_t, typename Weapon_t>
	inline void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy)
	{
		std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

		m_ability.useAbility(this);

		int dmg = this->getAttackAmnt();

		m_ability.transformDamageDealt(dmg);

		int enhancedDmg = dmg;

		std::cout << "    Barbarian deals " << enhancedDmg << " melee damage!" << std::endl;

		enemy->takeDamage(enhancedDmg);

	}

	template<typename T, typename Ability_t, typename Weapon_t>
	inline void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg)
	{

		std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "    Barbarian has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;

		int reducedDmg = dmg - getDefenseAmnt();

		if (reducedDmg < 0) {
			reducedDmg = 0;
		}

		m_ability.transformDamageReceived(reducedDmg);


		CharacterTpl<T>::takeDamage(reducedDmg);


	}

}
#endif // !SENECA_BARBARIAN_H