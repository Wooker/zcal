#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <iostream>
#include <string>
#include "../headers/today.h"

struct Calendar 
{
	Calendar ();
	~Calendar ();

	void show (Today today);
	std::string fmt (size_t margin, 
			size_t t_width, std::string text);
	void sync (Today today);
};

#endif  // CALENDAR_H_
