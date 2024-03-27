#include "RPN.hpp"

RPN::RPN(void){
	// std::cout << "RPN is Generated\n";
}

RPN::RPN(RPN const &cp){
	// std::cout << "RPN Copy is Generated\n";
	*this = cp;
}

RPN &RPN::operator=(RPN const &cp) {
	// std::cout << "RPN Operation is Generated\n";
	if (this != &cp)
		_stack = cp._stack;
	return *this;
}

RPN::~RPN(void){
	// std::cout << "RPN is destroyed\n";
}

int RPN::calculate(std::string const &argv){
	std::stringstream	str(argv);
	std::string			rpn;

	int number1 = 0, number2 = 0;
	while (std::getline(str, rpn, ' ')) {
		
		
		if (rpn == "+" || rpn == "-"
			|| rpn == "*" || rpn == "/"){
				if (_stack.size() < 2){
					std::cerr << "Wrong Format string\n";
					return -1;
				}	
				
				try{
					number2 = _stack.top();
					_stack.pop();
					number1 = _stack.top();
					_stack.pop();
				}
				catch (const std::exception &e){
					std::cerr << e.what() << '\n';
				}
				// std::cout << "rpn: " << rpn << "\n";
				if (rpn == "+"){
					_stack.push(number1+number2);
				}
				else if (rpn == "-"){
					_stack.push(number1-number2);
				}
				else if (rpn == "*"){
					_stack.push(number1*number2);
				}
				else if (rpn == "/"){
					if (number2 == 0){
						std::cerr << "ERROR: Wrong format input(Divide by 0)\n";
						return -1;
					}
					_stack.push(number1/number2);
				}
				else{
					std::cerr << "ERROR: Wrong format input\n";
					return -1;
				}

			}
		else
			_stack.push(atof(rpn.c_str()));
	}
	if (_stack.size() != 1){
		std::cerr << "ERROR: Wrong Calculation\n";
		return -1;
	}
	return _stack.top();
}
