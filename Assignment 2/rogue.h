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

#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include <string>

namespace seneca {


	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T> {

		size_t m_baseDefense{}; 
		size_t m_baseAttack{};
		FirstAbility_t m_firstAbility{};
		SecondAbility_t m_secondAbility{};
		seneca::Dagger m_weapon{};

	public:
		Rogue() {};
		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
		int getAttackAmnt() const override;
		int getDefenseAmnt() const override;
		Character* clone() const override;
		void attack(Character* enemy) override;
		void takeDamage(int dmg) override;




	};

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
		:CharacterTpl<T>(name, healthMax)
	{
		m_baseDefense = baseDefense;
		m_baseAttack = baseAttack;

	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const
	{

		int attackDmg = m_baseAttack + static_cast<int>(2 * m_weapon);

		return attackDmg;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const
	{
		return m_baseDefense;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const
	{
		Rogue* r = new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);

		return r;

	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy)
	{

		std::cout << this->getName() << " is attacking " << enemy->getName() << ".";
		
		m_firstAbility.useAbility(this);
		m_secondAbility.useAbility(this);

		int charDmg = getAttackAmnt();

		m_firstAbility.transformDamageDealt(charDmg);

		m_secondAbility.transformDamageDealt(charDmg);

		int enhDmg = charDmg;

		std::cout << "Rogue deals " << enhDmg << " melee damage!" << std::endl;

		enemy->takeDamage(enhDmg);

	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	inline void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg)
	{
		std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
		std::cout << "Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;


		int blockedDmg = dmg - getDefenseAmnt();

		if (blockedDmg < 0) {
			blockedDmg = 0;
		}

		m_firstAbility.transformDamageReceived(blockedDmg);
		m_secondAbility.transformDamageReceived(blockedDmg);

		int reducedDmg = blockedDmg;

		CharacterTpl<T>::takeDamage(reducedDmg);

	}

}
#endif // !SENECA_ROGUE_H