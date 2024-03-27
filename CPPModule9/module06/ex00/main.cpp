#include "ScalarConverter.hpp"


// /convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0

void ft_error(std::string msg){
    std::cerr << msg << "\n";
}

int main(int argc, char **argv){
    if (argc != 2){
        ft_error("argv must be 2\n");  
    }
    ScalarConverter test(argv[1]);
}