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
	
	Calendar cal;
	cal.show ();

	Today today;
	today.print ();
	
	std::string date_str = cal.as_str (today.time_info);
	std::cout << date_str << std::endl;

	std::cout << today.day_str << std::endl;

	return 0;
}
