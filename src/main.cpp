#include <iostream>

#include "../headers/calendar.h"
#include "../headers/today.h"


int main (int argc, char* argv[])
{
	/*
	if (argc == 1)
		std::cout << "Usage: ./main arg1" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << std::endl;
	}
	*/

	///////////////////////////////////////////////////////
	
	time_t raw_time;

	time (&raw_time);
	tm *time_info = localtime (&raw_time);

	Calendar cal;

	Day today (Month (time_info->tm_mon + 1, time_info->tm_year + 1900), 
			time_info->tm_wday, 
			time_info->tm_mday);

	Day new_year (Month (1, 2018), 1, 1);
	today.print ();

	std::vector<int> months_sync1 = cal.sync_months (new_year);

	return 0;
}
