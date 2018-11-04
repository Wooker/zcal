#include "../headers/day.h"

#include <iostream>

Day::Day (Month month, int wday, int day) : Month(month)
{
	wday_num = wday;

	switch (wday_num)
	{
		case 0: wday_str = "Su"; break;
		case 1: wday_str = "Mo"; break;
		case 2: wday_str = "Tu"; break;
		case 3: wday_str = "We"; break;
		case 4: wday_str = "Th"; break;
		case 5: wday_str = "Fr"; break;
		case 6: wday_str = "Sa"; break;
	}

	day_num = day;

	year_num = month.year_num;
}

Day::~Day () {}

void Day::print ()
{
	printf ("%s (%d), ", month_str.c_str(), month_num);
	printf ("%s (%d), ", wday_str.c_str(), wday_num);
	printf ("Day: %d, ", day_num);
	printf ("Year: %d, ", year_num);
	printf ("\n");
}
