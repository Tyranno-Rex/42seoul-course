#include "karen.hpp"

Karen::Karen(void)
{}

Karen::~Karen(void)
{}

void Karen::DEBUG(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Karen::INFO(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Karen::WARNING(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"; 
}

void Karen::ERROR(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n"; 
}

void Karen::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*f[4])(void) = {&Karen::DEBUG, &Karen::INFO, &Karen::WARNING, &Karen::ERROR};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level) 
            (this->*f[i])();
    }
}