#include "../headers/today.h"

Today::Today()
{
	time_t raw_time;

	time (&raw_time);
	time_info = localtime (&raw_time);

	year 	= time_info->tm_year;
	month 	= time_info->tm_mon;
	day 	= time_info->tm_wday;

}

Today::~Today() {}

void Today::print()
{
	printf ("%s", asctime (time_info));
}
