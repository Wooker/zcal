#ifndef MONTH_H_
#define MONTH_H_

#include "../headers/day.h"

#include <string>

const short MONTH_NUM = 12;

static const char month_name[][4] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

struct Month
{
	Month (int month_num, int year_number);
	~Month ();

	int year_num;


	int total_weeks;

	int total_days;

	int month_num;
	std::string month_str;

	void print ();
};

#endif // MONTH_H_
