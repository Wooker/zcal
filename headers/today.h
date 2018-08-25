#ifndef TODAY_H_
#define TODAY_H_

#include <string>
#include <ctime>

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

	struct tm * time_info;

	std::string year;
	std::string month;
	std::string day_str;
	std::string day_num;

	void print ();
	std::string as_str (struct tm *);
};

#endif  // TODAY_H_
