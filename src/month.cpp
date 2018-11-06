#include "../headers/month.h"

#include <iostream>

// Constructors
Month::Month () {}

Month::Month (int month, int year)
{
	month_num = month;

	year_num = year;

	if (month_num < 1) {
		month_num = 12 - month_num;
		year_num -= 1;
	} else if (month_num > 12) {
		month_num = month_num - 12;
		year_num += 1;
	}

	switch (month_num)
	{
		case 1: month_str = "Jan"; break;
		case 2: month_str = "Feb"; break;
		case 3: month_str = "Mar"; break;
		case 4: month_str = "Apr"; break;
		case 5: month_str = "May"; break;
		case 6: month_str = "Jun"; break;
		case 7: month_str = "Jul"; break;
		case 8: month_str = "Aug"; break;
		case 9: month_str = "Sep"; break;
		case 10: month_str = "Oct"; break;
		case 11: month_str = "Nov"; break;
		case 12: case 0: month_str = "Dec"; break;
	}


	if (month_num == 1 || month_num == 3 || month_num == 5 || month_num == 7 ||
 	    month_num == 8 || month_num == 10 || month_num == 12)
		total_days = 31;
	else if (month_num == 2) {
		if ((year_num % 4 == 0 && year_num % 100 != 0) || (year_num % 400 == 0))
			total_days = 29;
		else 
			total_days = 28;
	}
	else
		total_days = 30;
}

// Destructor
Month::~Month () {}

inline int Month::year () { return year_num; }

inline int Month::days () { return total_days; }

inline int Month::month_n () { return month_num; }

inline std::string Month::month_s () { return month_str; }

void Month::print ()
{
	printf ("%s (%d), ", month_s().c_str (), month_n());
	printf ("Year: %d, ", year());
	printf ("Days: %d", days());
	printf ("\n");
}
