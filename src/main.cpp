#include <iostream>

#include "../headers/calendar.h"

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

	Day day (Month (12, 2018), Th, 27);

	cal.show (day);

	return 0;
}
