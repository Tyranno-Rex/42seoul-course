#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string target){
    try{
        convertall(target);
    }
    catch(...){
    }
}

ScalarConverter::ScalarConverter(std::string target)
{
    std::cout << "Constructor is Generated\n";
    ScalarConverter::convert(target);
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor is Generated\n";
}

char ScalarConverter::getChar(){
   return this->_value_char; 
}

int ScalarConverter::getInt(){
    return this->_value_int;
}

double ScalarConverter::getDouble(){
    return this->_value_double;
}

float ScalarConverter::getFloat(){
    return this->_value_float;
}

#include <stdlib.h>
#include <cstring>

void ScalarConverter::convertall(std::string target){
    // You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
    if (!target.compare("+inf") || !target.compare("-inf") 
        || !target.compare("inf") || !target.compare("inff")
        || !target.compare("nan"))
		{
            std::string CharInt = "Impossible"; 
            std::string FloatDouble;
			if (!target.compare("nan"))
				FloatDouble = "nan";
			else if (!target.compare("+inf") || !target.compare("inf") 
                    || !target.compare("+inff"))
				FloatDouble = "inf";
			else if (!target.compare("-inf"))
				FloatDouble = "-inf";
			std::cout << "char:     " << CharInt << "\n";
			std::cout << "int:      " << CharInt << "\n";
			std::cout << "float:    " << FloatDouble << 'f' << "\n";
			std::cout << "double:   " << FloatDouble << "\n";
			return ;
		}
    
    this->_value_double = atof(target.c_str());
    std::cout << "check double\n" << "\n";
    std::cout << this->_value_double << "\n";
    this->_value_char = static_cast<unsigned char>(this->_value_double);
    this->_value_int = static_cast<int>(this->_value_double);
    this->_value_double = static_cast<double>(this->_value_double);
    this->_value_float = static_cast<float>(this->_value_double);
}

void ScalarConverter::printAll(){
    std::cout << "char      : " << this->_value_char << "\n";
    std::cout << "int       : " << this->_value_int << "\n";
    std::cout << "float     : " << this->_value_float << "\n";
    std::cout << "double    : " << this->_value_double << "\n";
}