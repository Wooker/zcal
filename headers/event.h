#ifndef EVENT_H_
#define EVENT_H_

#include "../headers/day.h"

#include <iostream>
#include <fstream>
#include <vector>

class Event
{
	Day event_day;

	std::string event_discr;

public:
	Event ();
	Event (Day day_given, std::string discr_given);
	~Event ();

	Day day();
	std::string discr();

	void print ();
	void write_event (std::string file_name);
	std::vector< Event > read_events(std::string file_name); 
};

#endif // EVENT_H_
