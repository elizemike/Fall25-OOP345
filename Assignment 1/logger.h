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

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include <iostream>
#include <string>

namespace seneca {

	class Event;

	class Logger {

		Event* m_arr{};
		size_t m_arrSize{};

	public:
		//Constructor
		Logger(){};

		//Copy Operation Disabled
		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& src) = delete;

		//Move Operations
		Logger(Logger&& src);
		Logger& operator=(Logger&& src);


		void addEvent(const Event& event);

		//Destructor
		~Logger();

		friend std::ostream& operator<<(std::ostream& os, const Logger& obj);

	};
}

#endif // SENECA_LOGGER_H

