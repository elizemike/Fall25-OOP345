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

#define _CRT_SECURE_NO_WARNINGS
#include "team.h"

namespace seneca {

	Team::Team(const char* name)
	{
		m_teamName = name;
		m_numOfMembers = 0;
		m_teamChar = nullptr;

	}

	Team::Team(const Team& src)
	{
		*this = src;

	}

	Team& Team::operator=(const Team& src)
	{

		if (this != &src){

			for (auto i = 0u; i < m_numOfMembers; i++) {
				delete m_teamChar[i];
			}

			delete[] m_teamChar;
			m_teamChar = nullptr;
			m_numOfMembers = 0;


			m_teamName = src.m_teamName;

			if (src.m_numOfMembers > 0) {

				m_teamChar = new Character* [src.m_numOfMembers];

				for (auto i = 0u; i < src.m_numOfMembers; i++) {
					m_teamChar[i] = src.m_teamChar[i]->clone(); //overides to the derived character class clone function
																//gives a deep copy.
				}

				
			}

			m_numOfMembers = src.m_numOfMembers;
		}

		return *this;
	}

	Team::Team(Team&& src)
	{

		*this = std::move(src);
		
	}

	Team& Team::operator=(Team&& src)
	{
		if (this != &src) {

			for (auto i = 0u; i < m_numOfMembers; i++) {
				delete m_teamChar[i];
			}
			delete[] m_teamChar;
			m_teamChar = nullptr;

			m_numOfMembers = src.m_numOfMembers;
			src.m_numOfMembers = 0;

			m_teamName = src.m_teamName;
			src.m_teamName = "";

			m_teamChar = src.m_teamChar;
			src.m_teamChar = nullptr;
		}


		return *this;
	}

	Team::~Team()
	{
		for (auto i = 0u; i < m_numOfMembers; i++) {
			delete m_teamChar[i];
		}
		delete[] m_teamChar;
		m_teamChar = nullptr;
		m_teamName = "";
		m_numOfMembers = 0;

	}

	void Team::addMember(const Character* c)
	{


		for (auto i = 0u; i < m_numOfMembers; i++) {

			if (c->getName() == m_teamChar[i]->getName()) {

				return;

			}
		}

		Character** newArr = new Character * [m_numOfMembers + 1];

		for (auto i = 0u; i < m_numOfMembers; i++) {

			newArr[i] = m_teamChar[i];
		}

		newArr[m_numOfMembers] = c->clone(); //deepcopy
		delete[] m_teamChar;
		m_teamChar = nullptr;

		m_teamChar = newArr;
		m_numOfMembers++;

	}

	void Team::removeMember(const std::string& c)
	{

		for (auto i = 0u; i < m_numOfMembers; i++) {

			if (c != m_teamChar[i]->getName()) {

				delete m_teamChar[i];

				size_t rNewMem = m_numOfMembers - 1;

				for (auto j = i; j < rNewMem; j++ ) {

					m_teamChar[j] = m_teamChar[j + 1];

				}

				m_teamChar[rNewMem] = nullptr;

				m_numOfMembers = rNewMem;

				break;
			}
		}


	}

	Character* Team::operator[](size_t idx) const
	{
		if (idx >= m_numOfMembers) {
			return nullptr;
		}

		return m_teamChar[idx];

	}

	void Team::showMembers() const
	{
		if (!m_teamName.empty()) {

			std::cout << "[Team] " << m_teamName << std::endl;
			for (auto i = 0u; i < m_numOfMembers; i++) {

				std::cout << "    " << i + 1 << ": " << *m_teamChar[i] << std::endl;

			}
		}
		else {

			std::cout << "No team." << std::endl;
		}
	}



}