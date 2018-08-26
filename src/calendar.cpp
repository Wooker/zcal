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
		  << "\033[0m"
		  << fmt (0, 24, today.month + " " +  " 1  2  3  4  5  6  7")
		  << fmt (5, 20, "8  9 10 11 12 13 14");
}
