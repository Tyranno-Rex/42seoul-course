#include <iostream>
#include <string>
#include <stdint.h>
#include<cstdlib> 
#include<ctime> 


// Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.

// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".


// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer



class Base
{
private:
    uintptr_t *_A;
    uintptr_t *_B;
    uintptr_t *_C;

public:
    Base(void);
    Base(const Base &src);
    ~Base(void);

    Base *generate(void);
    void idenify(Base *p);
    void idenify(Base *&p);
};