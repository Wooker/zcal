#ifndef DAY_H_
#define DAY_H_

#include "../headers/month.h"

#include <string>

const short DAY_NUM = 7;

class Day : public Month
{
public:
	Day (Month, int, int);
	~Day ();

	int year_num;

	std::string wday_str;
	int wday_num;

	int day_num;

	void print ();
	void print_asctime (tm *time_info);
};

#endif // DAY_H_
