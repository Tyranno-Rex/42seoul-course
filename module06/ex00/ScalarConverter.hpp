#ifndef SCALARCONVERTER_hPP
#define SCALARCONVERTER_hPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

#define ERROR -42
#define EMPTY -1
#define SPEC_VALUE -2
#define CHAR -3
#define INT -4
#define FLOAT -5
#define DOUBLE -6

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

    int     WhatType(std::string target);
    void    convertall(std::string target);
    void    printAll();

    class WrongValue : public std::exception{
        public:
            const char *what() const throw(){
                return ("Invaild input\n");
            }
    };
};

#endif