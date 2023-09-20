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
    if (target.length() != 1){

        throw "error";
    }
    char *cstr = new char[target.length() + 1];
    strcpy(cstr, target.c_str());
    // double로 저장하고 나머지 처리
    // convert string to double
    this->_value_double = atof(cstr);
    std::cout << "check double\n" << "\n";
    std::cout << this->_value_double << "\n";
    
    // this->_value_char = static_cast<unsigned char>();
    // this->_value_int = static_cast<int>(this->getChar());
    // this->_value_double = static_cast<double>(this->getChar());
    // this->_value_float = static_cast<float>(this->getChar());
}

void ScalarConverter::printAll(){
    std::cout << "char value    : " << this->_value_char << "\n";
    std::cout << "int value     : " << this->_value_int << "\n";
    std::cout << "float value   : " << this->_value_float << "\n";
    std::cout << "double value  : " << this->_value_double << "\n";
}