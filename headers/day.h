#ifndef DAY_H_
#define DAY_H_

#include "../headers/month.h"

#include <string>

const short DAY_NUM = 7;

static const char wkday_name[][4] = {
	"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
};

class Day
{
public:
	Day (int month, int wday, int day, int year);
	~Day ();

	enum week_day {Mo = 1, Tu, We, Th, Fr, Sa, Su};

	int year_num;

	std::string month_str;
	int month_num;

	std::string wday_str;
	int wday_num;

	int day_num;

	void print_day ();
};

#endif // DAY_H_
