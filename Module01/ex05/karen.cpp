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
    // Karen 클래스의 complain 함수입니다.
    // 이 함수는 문자열 level을 매개변수로 받으며, 해당하는 레벨의 함수를 호출합니다.

    // levels 배열은 각 레벨을 문자열로 저장합니다.
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // 함수 포인터 배열 f는 complain 함수에서 각 레벨에 해당하는 함수를 가리킵니다.
    void (Karen::*f[4])(void) = { &Karen::DEBUG, &Karen::INFO, &Karen::WARNING, &Karen::ERROR };

    // levels 배열과 매개변수로 받은 level을 비교하여 해당하는 레벨의 함수를 호출합니다.
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            // 함수 포인터를 사용하여 해당 레벨에 해당하는 함수를 호출합니다.
            (this->*f[i])();
            // 위의 코드는 (*this.*f[i])(); 와 동일한 역할을 합니다.
            // complain 함수가 Karen 객체 내부에서 실행되기 때문에 this를 사용하여 객체 자신을 참조합니다.
            // 함수 포인터는 객체의 멤버 함수를 가리키므로 ->* 연산자를 사용하여 해당하는 멤버 함수를 호출합니다.
        }
    }
}