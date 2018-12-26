#ifndef DAY_H_
#define DAY_H_

#include "../headers/month.h"

#include <string>

const short DAY_NUM = 7;

enum {Mo = 1, Tu, We, Th, Fr, Sa, Su = 0};

class Day
{
	Month m_month;

	int day_num;

	int wday_num;
	std::string wday_str;

public:
	Day ();
	Day (Month, int, int);
	~Day ();

	int day ();
	int wday_n ();
	std::string wday_s();
	Month month ();

	void print ();
	void print_asctime (tm *time_info);
};

#endif // DAY_H_
