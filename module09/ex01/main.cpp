#include "RPN.hpp"

int main( int ac, char **av ) {
	if (ac != 2) {
		std::cerr << "Usage: ./RPN '... input ...'" << std::endl;
		return 1;
	}

	RPN calculator;
	int result = calculator.calculate(av[1]);
	std::cout << result << "\n";
	if (result == -1){
		std::cerr <<  "ERROR\n";
		return 1;
	}
	return 0;
}