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


#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include "character.h"

namespace seneca {


	class Team {

		Character** m_teamChar{}; //Composition: belongs to Team; destroyed along with Team
		size_t m_numOfMembers{};
		std::string m_teamName{};

	public:

		//Rule of 5
		Team() {};
		Team(const char* name);
		Team(const Team& src);
		Team& operator=(const Team& src);
		Team(Team&& src);
		Team& operator=(Team&& src);
		~Team();

		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;

	};

}
#endif // !SENECA_TEAM_H