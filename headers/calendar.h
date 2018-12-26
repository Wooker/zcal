#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "../headers/event.h"

#include <string>
#include <vector>

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show (Day);

	void print_events (std::vector< Event >);

	void print_weeks (std::vector< std::vector< std::string > >);
	std::vector< std::vector<std::string> > get_weeks (Day);
	std::vector< std::vector<std::string> > highlight_days (std::vector< std::vector<std::string> >, Day);

	std::vector<std::string> get_month_dates (Day);

	std::vector<int> get_month_total_days (Month);
};

#endif  // CALENDAR_H_
