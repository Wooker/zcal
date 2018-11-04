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

	today.print ();
	today.print_day ();

	return 0;
}
