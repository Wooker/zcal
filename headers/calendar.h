#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <iostream>
#include <string>

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show ();
	std::string fmt (size_t margin, 
			size_t t_width, std::string text);
	std::string as_str (const struct tm * date);
};

#endif  // CALENDAR_H_
