#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "../headers/today.h"

#include <string>
#include <vector>

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show (Today);

	std::vector<std::string> get_dates (Today);

	std::vector< std::vector<std::string> > get_weeks (Today);
	void print_weeks (std::vector< std::vector<std::string> > weeks);

	std::string fmt (size_t margin, size_t t_width, std::string text);

	int sync_days_now (Today);
	int sync_days_before (Today);
	int sync_days_next (Today);

	std::vector<int> sync_months (Today);
	std::vector<std::string> combine_days(int days_before, int days_now, int days_next);
};

#endif  // CALENDAR_H_
