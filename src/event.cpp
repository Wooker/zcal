#include "../headers/event.h"

Event::Event () {}

Event::Event (Day day_given, std::string discr_given)
{
	event_day = day_given;

	event_discr = discr_given;
}

Event::~Event () {}

inline Day Event::day () { return event_day; }

inline std::string Event::discr () { return event_discr; }

void Event::print () 
{
	std::cout << discr() << std::endl;
}

std::vector< Event > Event::read_events(std::string file_name)
{
	std::ofstream file;
	file.open (file_name);
	if (file.is_open ()) {

	}
}

void Event::write_event (std::string file_name)
{
	Day day (Month (11, 2018), Fr, 30);
	Event event (day, "abc");

	std::string date, description;

	std::cout << "What is the date of your event? ";
	std::cin >> date;
	std::cout << "Event description: ";
	std::cin >> description;

	std::ofstream file;
	file.open (file_name);
	if (file.is_open ()) {
		file << std::to_string(event.day().day()) 	      << "."
		     << std::to_string(event.day().month().month_n()) << "."
		     << std::to_string(event.day().month().year())    << ":" 
		     << event.discr() << std::endl;
	} else
		std::cout << "Error: problem while opening the file" << std::endl;
}
