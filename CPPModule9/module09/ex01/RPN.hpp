#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stack>

class RPN {
private:
	std::stack<int> _stack;
public:
	RPN(void);
	RPN(RPN const &cp);
	~RPN(void);
	RPN &operator=(RPN const &cp);

	int calculate(std::string const &argv);
};