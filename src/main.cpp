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
	

	Today today;

	Calendar cal;
	int days_now = cal.sync_days_now (today);
	int days_before = cal.sync_days_before (today);

	cal.show_dates (cal.combine_days (cal.sync_days_now (today)));
	
	return 0;
}
