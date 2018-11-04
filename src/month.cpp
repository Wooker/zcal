#include "../headers/month.h"

// Constructor
Month::Month (int month, int year)
{
	month_num = month - 1;
	month_str = month_name[month_num];

	year_num = year;

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

void Month::print ()
{
	printf ("%s (%d), ", month_str.c_str (), month_num);
	printf ("Year: %d, ", year_num);
	printf ("Days: %d", total_days);
	printf ("\n");
}
