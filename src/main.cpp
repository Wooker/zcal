#include <iostream>
//#include <time.h>
#include "../headers/format.h"

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


	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "now it's %I:%M %p.", timeinfo);
	puts(buffer);

	std::cout << std::left << std::setw(12) << "John Smith"
		  << std::right << std::setw(3) << 23
		  << '\n';
	std::cout << std::left << std::setw(12) << "Sam Brown"
		  << std::right << std::setw(3) << 8
		  << '\n';
	*/

	///////////////////////////////////////////////////////
	
	Calendar cal;
	cal.show();

	return 0;
}
