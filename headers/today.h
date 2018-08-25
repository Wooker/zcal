#ifndef TODAY_H_
#define TODAY_H_

#include <string>
#include <ctime>

struct Today
{
	Today();
	~Today();

	struct tm * time_info;

	std::string year;
	std::string month;
	std::string day;

	void print();
};

#endif  // TODAY_H_
