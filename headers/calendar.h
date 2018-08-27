#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <string>
#include <vector>
#include "../headers/today.h"

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show (Today today);
	void show_dates (std::vector<std::string> days_vec);
	std::string fmt (size_t margin, 
			size_t t_width, std::string text);
	int sync_days_now (Today today);
	int sync_days_before (Today today);
	std::vector<std::string> combine_days(int days);
};

#endif  // CALENDAR_H_
