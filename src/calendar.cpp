#include <iomanip>
#include <iostream>
#include "../headers/calendar.h"


Calendar::Calendar () {}

Calendar::~Calendar () {}

// Main format function for calendar
// It should combine in one string:
// 	week days
// 	days numbers
// 	months
// 	events

// Display function for calendar
void Calendar::show (Day day)
{
	// Titles
	std::cout << "\033[1;37m";
	std::cout << std::setw(25) << "Mo Tu We Th Fr Sa Su\n"
		  << std::left<< day.month.month_s () + "\033[0m";

	// Numbers
	std::vector< std::vector<std::string> > weeks = get_weeks (day);

	print_weeks (weeks);

}

void Calendar::print_weeks (std::vector< std::vector<std::string> > weeks)
{
	for (int i = 0; i < weeks.size (); i++) {
		for (int j = 0; j < weeks.at (0).size (); j++) {
			if (stoi (weeks.at (i).at (j)) < 10)
				std::cout << "  " << weeks.at (i).at (j);
			else
				std::cout << " " << weeks.at (i).at (j);

			if (i == weeks.size () - 1 & j == weeks.at (0).size () - 1) {
				for (int k = 1; k <= 3; k++)
					std::cout << weeks.at (i).at (j + k) + " ";
			}
		}
		std::cout << std::endl << "   ";
	}
}

std::vector< std::vector<std::string> > Calendar::get_weeks (Day day)
{
	std::vector<std::string> dates = get_dates (day);
	std::vector<std::vector<std::string>> buff;

	for (int i = 0; i < dates.size () / DAY_NUM; i++) {
		std::vector<std::string> temp;

		for (int j = 0; j < DAY_NUM; j++) {
			temp.push_back (dates.at (i * DAY_NUM + j));

			if (i == (dates.size () / DAY_NUM) - 1 & j == DAY_NUM - 1) {
				for (int k = 1; k <= dates.size () % DAY_NUM; k++) {
					temp.push_back (dates.at (i * DAY_NUM + j + k));
				}
			}
		}

		buff.push_back (temp);
	}

	return buff;
}

// Formats dates to be straight in column,
// converts them to string and returns dates string.
std::vector<std::string> Calendar::get_dates (Day day)
{
	// Number of days in prev. current and next months
	std::vector<int> months_sync = sync_months (day);

	// Vector for storing dates' numbers
	std::vector<std::string> dates;

	// Add days of current and next months
	for (int k = 0; k < months_sync.size (); k++) {
		for (int i = 0; i < months_sync.at (k); i++) {
			dates.push_back (std::to_string (i + 1));
		}
	}

	return dates;
}

std::vector<int> Calendar::sync_months (Day day)
{
	std::vector<int> months_sync;

	// Adding total days of 
	// prev.(current - 1) 
	// current(current + 0) 
	// next(current + 1) months
	for (int i = -1; i <= 1; i++) {
		Month month (day.month.month_n () + i, day.month.year ());
		month.print ();
		day.print ();

		months_sync.push_back (month.days ());
	}

	std::cout << "###################" << std::endl;

	return months_sync;
}
