#include "Base.hpp"


Base *generate(void)
{
    int randomValue = std::rand() % 3;
    if (randomValue == 0) {
        return new A();
    } else if (randomValue == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base *p){
    Base *base;

    if (p == NULL){
        std::cerr << "wrong input in identify func\n";
    }
    base = dynamic_cast<A *>(p);
    if (base != NULL){
        std::cout << "A: " << p << "\n";
    }
    base = dynamic_cast<B *>(p);
    if (base != NULL){
        std::cout << "B: " << p << "\n";
    }
    base = dynamic_cast<C *>(p);
    if (base != NULL){
        std::cout << "C: " << p << "\n";
    }
}

void identify(Base& p)
{
	try
	{
		A& AIdentifier = dynamic_cast<A &>(p);
		std::cout << &AIdentifier << " is A\n";
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& BIdentifier = dynamic_cast<B &>(p);
		std::cout << &BIdentifier << " is B\n";
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& CIdentifier = dynamic_cast<C&>(p);
		std::cout << &CIdentifier << " is C\n";
	}
	catch(const std::exception& e)
	{
	}
}
