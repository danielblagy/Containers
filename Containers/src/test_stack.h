#pragma once

#include "stack.h"
#include <string>


void test_stack()
{
	Stack<float> s;
	std::string e = " ";
	while (e[0] != 'q')
	{
		std::cin >> e;
		
		if (e == "pop")
			s.pop();
		else
			s.push(std::stof(e));

		std::cout << "top " << s.top() << std::endl;
	}
}