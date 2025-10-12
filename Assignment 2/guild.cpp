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
#include "guild.h"

namespace seneca {

    Guild::Guild(const char* name)
    {
        m_guildName = name;
        m_numOfMembers = 0;
        m_guildChar = nullptr;

    }
    Guild::Guild(const Guild& src)
    {

        *this = src;
    }

    Guild& Guild::operator=(const Guild& src)
    {

        if (this != &src) {
            
            delete[] m_guildChar;
            m_guildChar = nullptr;

            m_guildName = src.m_guildName;

            if (src.m_numOfMembers > 0) {

                
                m_guildChar = new Character * [src.m_numOfMembers];

                for (auto i = 0u; i < src.m_numOfMembers; i++) {
                    m_guildChar[i] = src.m_guildChar[i];
                }
            }

            m_numOfMembers = src.m_numOfMembers;

        }

        return *this;
    }

    Guild::Guild(Guild&& src)
    {
        *this = std::move(src);

    }

    Guild& Guild::operator=(Guild&& src)
    {
        if (this != &src) {

            delete[] m_guildChar;
            m_guildChar = nullptr;

            m_guildName = src.m_guildName;
            src.m_guildName = "";

            m_numOfMembers = src.m_numOfMembers;
            src.m_numOfMembers = 0;

            m_guildChar = src.m_guildChar;
            src.m_guildChar = nullptr;

        }
        return *this;
    }

    Guild::~Guild()
    {
        delete[] m_guildChar;
        m_guildChar = nullptr;
        m_numOfMembers = 0;
        m_guildName = "";

    }

    void Guild::addMember(Character* c)
    {
        for (auto i = 0u; i < m_numOfMembers; i++) {
            if (c == m_guildChar[i]) {
                return;
            }
        }

        int base = c->getHealthMax();
        base += 300;
        c->setHealthMax(base);


        Character** newArr = new Character* [m_numOfMembers + 1];

        for (auto i = 0u; i < m_numOfMembers; i++) {

            newArr[i] = m_guildChar[i];
        }

        newArr[m_numOfMembers] = c;
        delete[] m_guildChar;

        m_guildChar = newArr;
        m_numOfMembers++;

    }

    void Guild::removeMember(const std::string& c)
    {
        for (auto i = 0u; i < m_numOfMembers; i++) {
            if (c == m_guildChar[i]->getName()) {

                int base = m_guildChar[i]->getHealthMax();
                base -= 300;
                m_guildChar[i]->setHealthMax(base);


                size_t newNum = m_numOfMembers - 1;

                for (size_t j = i; j < newNum; j++) {

                    m_guildChar[j] = m_guildChar[j + 1];


                }

                m_guildChar[newNum] = nullptr;
                m_numOfMembers = newNum;

                break;
            }
        }

    }

    Character* Guild::operator[](size_t idx) const
    {
        if (idx > m_numOfMembers) {
            return nullptr;
        }
        return m_guildChar[idx];
    }

    void Guild::showMembers() const
    {
        if (!m_guildName.empty()) {

           
            std::cout << "[Guild] " << m_guildName << std::endl;
            
            for (auto i = 0u; i < m_numOfMembers; i++) {

                std::cout << "    " << i + 1 << ": " << *m_guildChar[i] << std::endl;

            }
        }
        else {

            std::cout << "No guild." << std::endl;

        }

    }

}