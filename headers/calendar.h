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

	std::vector<std::string> get_dates (Day);

	std::vector< std::vector<std::string> > get_weeks (Day);
	void print_weeks (std::vector< std::vector<std::string> > weeks);

	std::string fmt (size_t margin, size_t t_width, std::string text);

	int sync_days_now (Day);
	int sync_days_before (Day);
	int sync_days_next (Day);

	std::vector<int> sync_months (Day);
	std::vector<std::string> combine_days(int days_before, int days_now, int days_next);
};

#endif  // CALENDAR_H_
