#include "ScalarConverter.hpp"

void ft_error(std::string msg){
    std::cout << msg << "\n";
}

int main(int argc, char **argv){
    if (argc != 2){
        ft_error("argv must be 2\n");  
    }
    /*
        • char
        • int
        • float
        • double
    */
   ScalarConverter test(argv[1]);

}