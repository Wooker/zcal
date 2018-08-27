#ifndef TODAY_H_
#define TODAY_H_

#include <string>

const short DAY_NUM = 7;
const short MONTH_NUM = 12;

static const char wkday_name[][4] = {
	"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
};

static const char month_name[][4] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

struct Today
{
	Today ();
	~Today ();

	tm * time_info;

	std::string year;
	std::string month_str;
	int month_num;         // range (0, 11)
	std::string day_str;
	int day_num;

	void print ();
};

#endif  // TODAY_H_
