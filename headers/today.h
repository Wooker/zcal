#ifndef TODAY_H_
#define TODAY_H_

#include "../headers/day.h"

#include <string>

struct Today : public Day
{
	Today ();
	~Today ();

	tm * time_info;

	void print ();
};

#endif  // TODAY_H_
