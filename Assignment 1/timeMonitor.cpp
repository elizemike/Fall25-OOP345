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
#include "timeMonitor.h"
#include "event.h"
#include <string>
#include <chrono>


namespace seneca {


	void TimeMonitor::startEvent(const char* name)
	{
		m_eventName = name;

		m_startTime = std::chrono::steady_clock::now();

	}

	Event TimeMonitor::stopEvent()
	{

		m_endTime = std::chrono::steady_clock::now();

		m_dur = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);

		Event e(m_eventName, m_dur);

		return e;
	}



}