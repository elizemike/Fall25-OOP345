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

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <iostream>
#include <string>
#include <chrono>


namespace seneca {

	class Event;

	class TimeMonitor {

		std::string m_eventName;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		std::chrono::nanoseconds m_dur{};


	public:

		void startEvent(const char* name);
		Event stopEvent();

	};

}


#endif // !

