#include "../headers/day.h"

#include <iostream>

Day::Day (Month month_var, int wday, int day)
{
	wday_num = wday;

	m_month = month_var;

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
}

Day::~Day () {}

inline int Day::day () { return day_num; }

inline int Day::wday_n () { return wday_num; }

inline std::string Day::wday_s () { return wday_str; }

inline Month Day::month () { return m_month; }

void Day::print ()
{
	printf ("%s (%d), ", month().month_s().c_str(), month().month_n());
	printf ("%s (%d), ", wday_s().c_str(), wday_n());
	printf ("Day: %d, ", day());
	printf ("Year: %d, ", month().year());
	printf ("\n");
}
