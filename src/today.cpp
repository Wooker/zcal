#include "../headers/today.h"

// Constructor
Today::Today ()
{
	time_t raw_time;

	time (&raw_time);
	time_info = localtime (&raw_time);

	// time_info - main time var

	// Parsing strings from time_info
	char buff[30];
	sprintf (buff, "%d", time_info->tm_year + 1900);
	year = buff;
	sprintf (buff, "%.3s", wkday_name[time_info->tm_wday]);
	day_str = buff;
	day_num = time_info->tm_wday;
	sprintf (buff, "%.3s", month_name[time_info->tm_mon]);
	month_str = buff;
	month_num = time_info->tm_mon;
}

// Destructor
Today::~Today () {}


// Print entire date
void Today::print ()
{
	printf ("%s", asctime (time_info));
}
