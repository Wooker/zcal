#ifndef MONTH_H_
#define MONTH_H_

#include <string>

const short MONTH_NUM = 12;

class Month
{
	int year_num;

	int total_days;

	int month_num;
	std::string month_str;

public:
	Month ();
	Month (int, int);

	~Month ();

	int year ();
	int days ();
	int month_n ();
	std::string month_s ();

	void print ();
};

#endif // MONTH_H_
