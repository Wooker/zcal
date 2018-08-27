#include "../headers/today.h"
#include "../headers/calendar.h"

Calendar::Calendar () {}

Calendar::~Calendar () {}

// Main format function for calendar
// It should combine in one string:
// 	week days
// 	days numbers
// 	months
// 	events
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

// Display function for calendar
void Calendar::show (Today today)
{
	std::cout << "\033[1;37m";
	std::cout << fmt (4, 20, "Mo Tu We Th Fr Sa Su")
		  << fmt (0, 24, today.month_str + "\033[0m" + " " +  
				 " 1  2  3  4  5  6  7")
		  << fmt (5, 20, "8  9 10 11 12 13 14");
}

// Synchronize calendar
void Calendar::sync (Today today)
{

	int month_now = today.time_info->tm_mon + 1;
	int month_before = month_now - 1;

	int days_now = 31;
	int days_before = 30;

	int year  = today.time_info->tm_year;
	bool leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month_now == 1)
	{
		month_before = 12;
		days_before = 31;
	}
	else if (month_now == 8)
		days_before = 31;

	else if (month_now == 4 || month_now == 6 || month_now == 9 || month_now == 11)
	{
		days_now = 30;
		days_before = 31;
	}
	else if (month_now == 2)
	{
		days_before = 31;
		if (leap_year)
			days_now = 28;
		else 
			days_now = 29;
	}
	else if (month_now == 3)
	{
		if (leap_year)
			days_before = 28;
		else 
			days_before = 29;
	}

	/*
	std::cout << "NOW:" << std::endl;
	std::cout << year + 1900 << std::endl;
	std::cout << month_now << std::endl;
	std::cout << days_now << std::endl;

	std::cout << "BEFORE:" << std::endl;
	std::cout << year + 1900 << std::endl;
	std::cout << month_before << std::endl;
	std::cout << days_before << std::endl;

	std::cout << "########################" << std::endl;
	*/
}
