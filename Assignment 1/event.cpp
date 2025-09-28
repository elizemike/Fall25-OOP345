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
#include "event.h"
#include <string>
#include <chrono>
#include <iostream>
#include "settings.h"


namespace seneca {

	static int cnt{0};
	
	Event::Event(const std::string& name, const std::chrono::nanoseconds& duration)
	{

		m_name = name;
		m_duration = duration;

	}

	std::ostream& operator<<(std::ostream& os, const Event& obj)
	{
		static int cnt{ 0 };
		cnt++;


		os.setf(std::ios::right);
		os.width(2);
		os.fill(' ');
		os << cnt;
		os.unsetf(std::ios::right);

		os << ": ";

		os.setf(std::ios::right);
		os.width(40);
		os.fill(' ');
		os << obj.m_name;
		os.unsetf(std::ios::right);

		os << " -> ";

		os.setf(std::ios::right);

		if (g_settings.m_time_units == "seconds") {
			os.width(2);
			os.fill(' ');
			os << std::chrono::duration_cast<std::chrono::seconds>(obj.m_duration).count();
		}
		else if (g_settings.m_time_units == "milliseconds") {
			os.width(5);
			os.fill(' ');
			os << std::chrono::duration_cast<std::chrono::milliseconds>(obj.m_duration).count();
		} 
		else if(g_settings.m_time_units == "microseconds"){
		
			os.width(8);
			os.fill(' ');
			os << std::chrono::duration_cast<std::chrono::microseconds>(obj.m_duration).count();
		}
		else if(g_settings.m_time_units == "nanoseconds"){
		
			os.width(11);
			os.fill(' ');
			os << std::chrono::duration_cast<std::chrono::nanoseconds>(obj.m_duration).count();

		}

		os.fill(' ');
		os.unsetf(std::ios::right);

		os << ' ' << g_settings.m_time_units;


		return os;
	}

}