#include "../headers/calendar.h"

Calendar::Calendar () {}

Calendar::~Calendar () {}

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
        (result += text.substr (0, n)) += '\n';
        text.erase (0, n);
    }
    return result;
}

void Calendar::show ()
{
	std::cout << fmt (4, 20, "Mo Tu We Th Fr Sa Su");
}

std::string Calendar::as_str (const struct tm * date)
{
	static const char  wkday_name[][4] = {
		"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"
	};

	static const char month_name[][4] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};

	static char result[26];
	sprintf (result, "%.3s %.3s%3d %d\n",
		 wkday_name[date->tm_wday],
		 month_name[date->tm_mon],
		 date->tm_mday,
		 date->tm_year + 1900);

	return result;
}
/*
std::string Calendar::get_today()
{
	char currDate[10];
	time_t t = time(NULL);

	struct tm tm = *localtime(&t);
	sprintf(currDate, "%d-%d-%d",
			tm.tm_year + 1900,
			tm.tm_mon + 1,
			tm.tm_mday);
	
	return currDate;
}
*/