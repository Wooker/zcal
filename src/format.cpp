#include "../headers/format.h"

Calendar::Calendar() {}

Calendar::~Calendar() {}

std::string Calendar::fmt(size_t margin, size_t width, std::string text)
{
    std::string result;
    while (!text.empty())   // while more text to move into result
    {
        result += std::string(margin, ' ');  // add margin for this line

        if (width >= text.size())  // rest of text can fit... nice and easy
            return (result += text) += '\n';

        size_t n = width - 1;  // start by assuming we can fit n characters
        while (n > width / 2 && isalnum(text[n]) && isalnum(text[n - 1]))
            --n; // between characters; 
		 // reduce n until word breaks or 1/2 width left

        // move n characters from text to result...
        (result += text.substr(0, n)) += '\n';
        text.erase(0, n);
    }
    return result;
}

std::string Calendar::show()
{
//	for (int i = 0; i < DAY_NUM; i++) 
//		std::cout << wkday_name[i] + " ";
//
//	std::cout << '\n';

	std::cout << fmt(4, 20, "Mo Tu We Th Fr Sa Su") << std::endl;

}

