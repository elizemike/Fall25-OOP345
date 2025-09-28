
////////////////////////////////////////////////////////////////////
// Name : Elizabeth Esede
// Email : eesede@myseneca.ca
// Student ID: 120651245
// Date Completed: 
//////////////////////////////////
// I declare that this submission is the result of my own work 
// and I only copied the code that my professor provided to complete
// my assignments.This submitted piece of work has not been shared 
// with any other student or 3rd party content provider.
////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "logger.h"
#include "event.h"
#include<iostream>
#include <cstring>
#include <string>

namespace seneca
{

	seneca::Logger::Logger(Logger&& src)
	{
		*this = std::move(src);

	}

	Logger& Logger::operator=(Logger&& src)
	{

		if (this != &src) {

			delete[] m_arr;
			m_arr = nullptr;

			m_arr = src.m_arr;
			src.m_arr = nullptr;

			m_arrSize = src.m_arrSize;
			src.m_arrSize = 0;

		}

		return *this;
	}

	void Logger::addEvent(const Event& event)
	{
		
		Event* temp = new Event[m_arrSize + 1];

		for (auto i = 0u; i < m_arrSize; i++) {

			temp[i] = m_arr[i];

		}

		temp[m_arrSize] = event;


		delete[] m_arr;
		m_arr = temp;
		m_arrSize++;

	}

	Logger::~Logger()
	{

		delete[] m_arr;
		m_arr = nullptr;

		m_arrSize = 0;

	}

	std::ostream& operator<<(std::ostream& os, const Logger& obj)
	{

		for (auto i = 0u; i < obj.m_arrSize; i++) {
			os << obj.m_arr[i] << "\n";
		}

		return os;

	}

}