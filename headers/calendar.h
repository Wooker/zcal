#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "../headers/day.h"

#include <string>
#include <vector>

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show (Day);


	std::vector< std::vector<std::string> > get_weeks (Day);
	void print_weeks (std::vector< std::vector<std::string> > weeks);

	std::vector<std::string> get_month_dates (Month);

	std::vector<int> get_month_total_days (Month);
};

#endif  // CALENDAR_H_
