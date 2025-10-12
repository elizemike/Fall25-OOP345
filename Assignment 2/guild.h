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

#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include "character.h"

namespace seneca {

	class Guild {

		Character** m_guildChar{};
		size_t m_numOfMembers{};
		std::string m_guildName{};

	public: 

		Guild() {};
		Guild(const char* name);

		Guild(const Guild& src);
		Guild& operator=(const Guild& src);
		Guild(Guild&& src);
		Guild& operator=(Guild&& src);

		~Guild();

		void addMember(Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;

	};


}
#endif // !SENECA_GUILD_H
