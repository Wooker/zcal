#include "../headers/day.h"

#include <iostream>

Day::Day (int month, int wday, int day, int year)
{
	month_num = month;
	month_str = month_name[month_num - 1];

	wday_num = wday;
	wday_str = wkday_name[wday_num - 1];

	day_num = day;

	year_num = year;
}

Day::~Day () {}

void Day::print_day ()
{
	printf ("%s (%d), ", month_str.c_str(), month_num);
	printf ("%s (%d), ", wday_str.c_str(), wday_num);
	printf ("Day: %d, ", day_num);
	printf ("Year: %d, ", year_num);
	printf ("\n");
}
