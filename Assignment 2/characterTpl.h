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

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <string>
#include "character.h"

namespace seneca {

	template<typename T>
	class CharacterTpl : public Character {

		size_t m_healthMax{};
		T m_health{};
		std::string m_char{};


	public:
		CharacterTpl(){};
		CharacterTpl(const char* charName, size_t maxHealth); 
		void takeDamage(int dmg) override;
		int getHealth() const override;
		int getHealthMax() const override;
		void setHealth(int health) override;
		void setHealthMax(int health) override;

	};


	template<typename T>
	inline CharacterTpl<T>::CharacterTpl(const char* charName, size_t maxHealth)
		:Character(charName)	
	{
		m_healthMax = maxHealth;
		m_health = maxHealth;
	}

	template<typename T>
	inline void CharacterTpl<T>::takeDamage(int dmg)
	{
		m_health -= dmg;
	

		if (m_health <= 0) {
			std::cout << "    " <<  getName() << " has been defeated!" << std::endl;
			m_health = 0;
		}
		else {
			std::cout << "    " << getName() << " took " << dmg << " damage, " << m_health << " health remaining." << std::endl;
		}
	}

	template<typename T>
	inline int CharacterTpl<T>::getHealth() const
	{
		return static_cast<int>(m_health);
	}

	template<typename T>
	inline int CharacterTpl<T>::getHealthMax() const
	{
		return static_cast<int>(m_healthMax);
	}

	template<typename T>
	inline void CharacterTpl<T>::setHealth(int health)
	{
		m_health = health;
	}

	template<typename T>
	inline void CharacterTpl<T>::setHealthMax(int health)
	{
		
		m_healthMax = health;
		m_health = health;

	}


}
#endif // !SENECA_CHARACTERTPL_H
