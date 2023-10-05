#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib> 
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <cstring>


// Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.

// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".

// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer

class Base
{
public:
    virtual ~Base() {}
    virtual void someVirtualFunction() {} // 가상 함수 추가
};


class A : public Base
{
public:
    A(void) {}
    virtual ~A(){};
};

class B : public Base
{
public:
    B(void) {}
    virtual ~B() {};
};

class C : public Base
{
public:
    C(void) {}
    virtual ~C() {};
};


Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // !BASE_HPP