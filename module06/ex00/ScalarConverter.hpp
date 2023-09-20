#include <iostream>
#include <string>
#include <stdlib.h>

class ScalarConverter
{
private:
    char    _value_char;
    int     _value_int;
    float   _value_float;
    double  _value_double;

    void    convert(std::string target);
public:
    ScalarConverter(std::string target);
    ScalarConverter(const ScalarConverter &ref);
    ~ScalarConverter(void);
   
    char    getChar();
    int     getInt();
    float   getFloat();
    double  getDouble();

    void    convertall(std::string target);
    void    printAll();
};


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

void ScalarConverter::convertall(std::string target){
    if (target.length() != 1){
        throw "error";
    }
    // double로 저장하고 나머지 처리
    this->_value_double = atof(target.c_str());
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