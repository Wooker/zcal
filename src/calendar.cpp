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
void Calendar::show (Today today)
{
	// Titles
	std::cout << "\033[1;37m";
	std::cout << std::setw(25) << "Mo Tu We Th Fr Sa Su\n"
		  << std::left<< today.month_str + "\033[0m";

	// Numbers
	std::vector< std::vector<std::string> > weeks = get_weeks (today);

	print_weeks (weeks);

}

std::string Calendar::fmt (size_t margin, size_t t_width, std::string text)
{
    std::string result;
    while (!text.empty ())   // while more text to move into result
    {
        result += std::string(margin, ' ');  // add margin for this line

        if (t_width >= text.size ())  // rest of text can fit... nice and easy
            return (result += text) += '\n';

        size_t n = t_width - 1;  // start by assuming we can fit n characters
        while (n > t_width / 2 && isalnum (text[n]) && isalnum (text[n - 1]))
            --n; // between characters; reduce n until word breaks 
		 // or 1/2 t_width left

        // move n characters from text to result...
        (result += text.substr (0, n)) ;
        text.erase (0, n);
    }
    return result;
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

std::vector< std::vector<std::string> > Calendar::get_weeks (Today today)
{
	std::vector<std::string> dates = get_dates (today);
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
std::vector<std::string> Calendar::get_dates (Today today)
{
	// Number of days in prev. current and next months
	std::vector<int> months_sync = sync_months (today);

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

std::vector<int> Calendar::sync_months (Today today)
{
	std::vector<int> months_sync;

	// Adding total days of 
	// prev.(current - 1) 
	// current(current + 0) 
	// next(current + 1) months
	for (int i = -1; i <= 1; i++) {
		Month month (today.month_num + i, today.year_num);

		months_sync.push_back (month.total_days);
	}

	return months_sync;
}
