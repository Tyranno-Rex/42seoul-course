#include <iostream>
#include <string>

/*
- 스트링의 메모리 주소
    : &로 변수의 메모리 주소에 접근
- `stringPTR`가 담은 메모리 주소
    : stringPTR은 자체가 메모리 주소
- `stringREF`가 담은 메모리 주소
    : &는 메모리 주소
- 스트링의 값
    : 변수 자체 출력
- `stringPTR`가 가리키는 주소의 값
    : 포인터의 *값은 값 자체의 접근 
- `stringREF`가 가리키는 주소의 값
    : 주소 자체에 존재함
*/

int	main(void)
{
    std::string Brain       = "HI THIS IS BRAIN";
    std::string *stringPTR  = &Brain;
    std::string &stringREF  = Brain; 

    std::cout << "String address(&Brain)    : " << &Brain << "\n";
    std::cout << "stringPTR(stringPTR)      : " << stringPTR << "\n";
    std::cout << "stringREF(&stringREF)     : " << &stringREF << "\n";

    std::cout << "String(Brain)             : " << Brain << "\n";
    std::cout << "stringPTR(*StringPTR)     : " << *stringPTR << "\n";
    std::cout << "stringREF(StringREF)      : " << stringREF << "\n";
    return (0);
}