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

	print_weeks (weeks);

}

void Calendar::print_weeks (std::vector< std::vector<std::string> > weeks)
{
	for (int i = 0; i < weeks.size (); i++) {
		for (int j = 0; j < weeks.at (i).size (); j++) {
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

// Returns vector of string vectors
std::vector< std::vector<std::string> > Calendar::get_weeks (Day day)
{
	std::vector<std::string> dates = get_month_dates (day);
	std::vector< std::vector<std::string> > buff;

	for (int k = 0; k < dates.size(); k++)
		std::cout << dates.at(k) << " ";

	std::cout << std::endl;

	int days_with_space = DAY_NUM + 1;

	// (<=) because last weeks has less than 7 days
	for (int i = 0; i <= dates.size () / days_with_space; i++) {
		std::vector<std::string> temp;

		/*
		 * SOMETHING THERE
		 */
		for (int j = 0; j < days_with_space; j++) {
			if (i * days_with_space + j < dates.size())
				temp.push_back (dates.at (i * days_with_space + j));
		}

		buff.push_back (temp);
	}

	return buff;
}

// Return vector of strings with all days of three months
std::vector<std::string> Calendar::get_month_dates (Day day)
{
	// Number of days in prev. current and next months
	std::vector<std::string> months_sync = get_month_total_days (day.month());

	// Vector for storing dates' numbers
	std::vector<std::string> dates;

	// Count days to add from previous month
	int days_to_add = DAY_NUM - ((day.day() - day.wday_n() + DAY_NUM) % DAY_NUM) - 1;

	std::string blank = "   ";

	// if month starts at monday, k = 3, no need to iterate through prev. month,
	// else k = 1, add last days from prev. month
	int k = 1;
	if (day.wday_n() - (day.day() / DAY_NUM) == Mo)
		k = 3;

	// Add days of current and next months
	// k points on numbers in months_sync vector
	for (k; k < months_sync.size(); k += 2) {
		if (k == 1) {
			dates.push_back (months_sync.at (k + 1));
			for (int i = days_to_add; i >= 0; i--)
				dates.push_back (std::to_string(stoi(months_sync.at (k)) - i));
		} else {
			for (int i = 0; i < stoi(months_sync.at (k)); i++) {
				if (i == 0 & (day.wday_n() == Mo | k == 5))
					dates.push_back (months_sync.at (k - 1));
				dates.push_back (std::to_string(i + 1));
			}
		}
	}

	return dates;
}

std::vector<std::string> Calendar::get_month_total_days (Month month)
{
	std::vector<std::string> months_sync;

	// Adding total days of 
	// prev.(current - 1) 
	// current(current + 0) 
	// next(current + 1) months
	for (int i = -1; i <= 1; i++) {
		Month month_new (month.month_n() + i, month.year());

		months_sync.push_back (month_new.month_s());
		months_sync.push_back (std::to_string(month_new.days()));
	}

	return months_sync;
}
