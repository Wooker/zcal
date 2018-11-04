#include "../headers/today.h"

// Constructor
Today::Today () : Day (0, 0, 0, 0)
{
	time_t raw_time;

	time (&raw_time);
	time_info = localtime (&raw_time);

	// time_info - main time var

	// Parsing strings from time_info
	char buff[30];

	year_num = time_info->tm_year + 1900;

	// To be in range of 1-12 add 1
	month_num = time_info->tm_mon + 1;
	month_str = month_name[month_num - 1];

	// To be in range of 1-7 add 1
	wday_num = time_info->tm_wday + 1;
	wday_str = wkday_name[wday_num - 1];

	day_num = time_info->tm_mday;
}

// Destructor
Today::~Today () {}


// Print entire date
void Today::print ()
{
	printf ("%s", asctime (time_info));
}
