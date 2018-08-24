#ifndef FORMAT_H_

#define FORMAT_H_

#include <iostream>
#include <string>

const short DAY_NUM = 7;
const short MONTH_NUM = 12;

struct Calendar 
{
	Calendar();
	~Calendar();
	std::string show();
	std::string fmt(size_t margin, size_t width, std::string text);
};

static const std::string wkday_name[DAY_NUM] {
	"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"
};

static const std::string month_name[MONTH_NUM] {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
    	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

#endif // FORMAT_H_
