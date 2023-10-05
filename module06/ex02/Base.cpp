#include "Base.hpp"

Base::Base(void)
{
    this->_A = 0;
    this->_B = 0;
    this->_C = 0;
    // std::cout << "Constructor is Generated\n";
}

Base::Base(const Base &src)
{
    // std::cout << "Copy Constructor is Generated\n";
    *this = src;
}

Base::~Base(void)
{
    // std::cout << "Constructor is Destroyed\n";
}


Base *Base::generate(void)
{
    Base* tmp = new Base;
    srand(time(NULL));

    int A = rand()%100000000;
    int B = rand()%100000000;
    int C = rand()%100000000;
    std::cout<<"A, B, C is generated: "<< A << ", "<< B << ", " << C << "\n";
    tmp->_A = reinterpret_cast<uintptr_t *>(A);
    tmp->_B = reinterpret_cast<uintptr_t *>(B);
    tmp->_C = reinterpret_cast<uintptr_t *>(C);
    std::cout<<"A, B, C is modifyed : "<< tmp->_A << ", "<< tmp->_B << ", " << tmp->_C << "\n";
    return tmp;
}


void Base::idenify(Base *p){
    int A, B, C;

    A = reinterpret_cast<int>(p->_A);
    std::cout << A << B << C << "\n";
}