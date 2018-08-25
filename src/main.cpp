#include <iostream>
//#include "../date/include/date/date.h"
//#include "../date/include/date/tz.h"
#include "../headers/format.h"
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

//	auto today = date::floor<date::days>(std::chrono::system_clock::now());
//	std::cout << today << '\n';

	Today today;
	today.print();


	return 0;
}
