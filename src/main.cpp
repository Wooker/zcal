#include <iostream>
#include <time.h>
#include <string>

int main (int argc, char* argv[])
{
	if (argc == 1)
		std::cout << "Usage: ./main arg1" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << std::endl;
	}


	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "now it's %I:%M %p.", timeinfo);
	puts(buffer);

	return 0;
}
