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

int ScalarConverter::WhatType(std::string target){

    // 비어있는 값 처리
    if (target.empty()){
        throw ScalarConverter::WrongValue();
        return EMPTY;
    }

    // 사이즈가 1개임
    if (target.length() == 1){
        if (std::isprint(target[0]))
            return CHAR;
        else
            return ERROR;
    }

    // 특이값 처리
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
        return SPEC_VALUE;
    }
    
    // int형
    // 숫자를 찾고 해당 문자열에 해당 되는 문자열이 따로 없으면 INT형을 반환
    if (target.find_first_not_of("+-0123456789") == std::string::npos){
        int pos_p = target.find('+');
        int pos_n = target.find('-');
        if (target.find('+') != std::string::npos && pos_p != 0){
            return ERROR;
        }
        if (target.find('-') != std::string::npos && pos_n != 0){
            return ERROR;
        }
        return INT;
    }

    // double 형
    if (target.find_first_not_of(".+-0123456789") == std::string::npos){
		if (target.find_first_of(".") != target.find_last_of(".") 
            || target.find_first_of(".") == 0 )
			return (ERROR);
		else
			return (DOUBLE);
    }

    // float형
    if (target.find_first_not_of(".f+-0123456789") == std::string::npos)
	{
		if (target.find_first_of("f") != target.find_last_of("f") 
            || target.find_first_of(".") != target.find_last_of(".") 
            || target.find_first_of(".") == 0 
            || target.find_first_of("f") != target.length() - 1
			|| target.find_first_of("f") - target.find_first_of(".") == 1) 
			return (ERROR);
		else
			return (FLOAT);
	}
    return (ERROR);
}

void ScalarConverter::convertall(std::string target){
    // You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
    
    int type = WhatType(target);
    if (type == ERROR) {
            std::cout << "input type is ERROR\n";
    }
    else{
        if (type == CHAR){
            std::cout << "input type is CHAR\n";
        }
        else if (type == INT){
            std::cout << "input type is INT\n";
        }
        else if (type == FLOAT){
            std::cout << "input type is FLOAT\n";
        }
        else if (type == DOUBLE){
            std::cout << "input type is DOUBLE\n";
        }

        this->_value_double = atof(target.c_str());
        // std::cout << this->_value_double << "\n";

        this->_value_char = static_cast<unsigned char>(this->_value_double);
        this->_value_int = static_cast<int>(this->_value_double);
        this->_value_double = static_cast<double>(this->_value_double);
        this->_value_float = static_cast<float>(this->_value_double);
    }
}

void ScalarConverter::printAll(){
    std::cout << "char      : " << this->_value_char << "\n";
    std::cout << "int       : " << this->_value_int << "\n";
    std::cout << "float     : " << this->_value_float << "\n";
    std::cout << "double    : " << this->_value_double << "\n";
}