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
	std::cout << std::right << std::setw(16) << day.month().year() << std::endl;
	std::cout << std::setw(25) << "Mo Tu We Th Fr Sa Su\n"
		  << std::left<< day.month().month_s () + "\033[0m";

	// Numbers
	std::vector< std::vector<std::string> > weeks = get_weeks (day);

	print_weeks (weeks, day);

}

void Calendar::print_weeks (std::vector< std::vector<std::string> > weeks, Day day)
{
	for (int i = 0; i < weeks.size (); i++) {
		for (int j = 0; j < weeks.at (i).size (); j++) {
			if (stoi (weeks.at (i).at (j)) < 10) {
				if (stoi (weeks.at (i).at (j)) == day.day ())
					weeks.at (i).at (j) = "\033[1;37m" + weeks.at (i).at (j) + "\033[0m";
				std::cout << "  " << weeks.at (i).at (j);
			}
			else {
				if (stoi (weeks.at (i).at (j)) == day.day ())
					weeks.at (i).at (j) = "\033[1;37m" + weeks.at (i).at (j) + "\033[0m";
				std::cout << " " << weeks.at (i).at (j);
			}

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
	std::vector<std::string> dates = get_month_dates (day);
	std::vector<std::vector<std::string>> buff;

	// (<=) because last weeks has less than 7 days
	for (int i = 0; i <= dates.size () / DAY_NUM; i++) {
		std::vector<std::string> temp;

		for (int j = 0; j < DAY_NUM; j++) {
			if (i * DAY_NUM + j < dates.size())
				temp.push_back (dates.at (i * DAY_NUM + j));
		}

		buff.push_back (temp);
	}

	return buff;
}

// Return vector of strings with all days of three months
std::vector<std::string> Calendar::get_month_dates (Day day)
{
	// Number of days in prev. current and next months
	std::vector<int> months_sync = get_month_total_days (day.month());

	// Vector for storing dates' numbers
	std::vector<std::string> dates;

	// Count days to add from previous month
	int days_to_add = DAY_NUM - ((day.day() - day.wday_n() + DAY_NUM) % DAY_NUM) - 1;

	int k = 0;
	if (day.wday_n() - (day.day() / DAY_NUM) == Mo)
		k = 1;

	// Add days of current and next months
	for (k; k < months_sync.size (); k++) {
		if (k == 0) {
			for (int i = days_to_add; i >= 0; i--)
				dates.push_back (std::to_string (months_sync.at (k) - i));
		} else {
			for (int i = 0; i < months_sync.at (k); i++) {
				dates.push_back (std::to_string (i + 1));
			}
		}
	}

	return dates;
}

std::vector<int> Calendar::get_month_total_days (Month month)
{
	std::vector<int> months_sync;

	// Adding total days of 
	// prev.(current - 1) 
	// current(current + 0) 
	// next(current + 1) months
	for (int i = -1; i <= 1; i++) {
		Month month_new (month.month_n() + i, month.year());

		months_sync.push_back (month_new.days());
	}

	return months_sync;
}
