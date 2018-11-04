#ifndef MONTH_H_
#define MONTH_H_

#include <string>

const short MONTH_NUM = 12;

class Month
{
public:
	Month (int, int);
	~Month ();

	void print ();

	int year_num;

	int total_weeks;

	int total_days;

	int month_num;
	std::string month_str;

};

#endif // MONTH_H_
