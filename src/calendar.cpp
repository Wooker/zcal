#include <iostream>
#include "../headers/calendar.h"

#define SPACE 4;


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
		  << fmt (0, 24, today.month_str + "\033[0m") << std::endl;

	
}

void Calendar::show_dates (std::vector<std::string> days_vec)
{

	for (int i = 0; i < days_vec.size (); i++)
		if (i < 9)
			std::cout << "  " + std::to_string (i + 1);
		else if ((i) % 9 == 0)
			std::cout << std::endl << " " + std::to_string (i + 1);
		else
			std::cout << " " + std::to_string (i + 1);
		
	std::cout << std::endl;
}

// Synchronize calendar
int Calendar::sync_days_now (Today today)
{

	int month_now = today.time_info->tm_mon + 1;
	int month_before = month_now - 1;

	int days_now = 31;

	int year  = today.time_info->tm_year;
	bool leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month_now == 4 || month_now == 6 || month_now == 9 || month_now == 11)
	{
		days_now = 30;
	}
	else if (month_now == 2)
	{
		if (leap_year)
			days_now = 28;
		else 
			days_now = 29;
	}

	return days_now;
}

int Calendar::sync_days_before (Today today)
{

	int month_now = today.time_info->tm_mon + 1;
	int month_before = month_now - 1;

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
		days_before = 31;
	}
	else if (month_now == 2)
		days_before = 31;
	else if (month_now == 3)
	{
		if (leap_year)
			days_before = 28;
		else 
			days_before = 29;
	}

	return days_before;
}

std::vector<std::string> Calendar::combine_days (int days)
{
	// Adding day strings to vector
	std::vector<std::string> days_vec;

	for (int i = 0; i < days; i++)
		days_vec.push_back(std::to_string(i + 1));

	return days_vec;
}
