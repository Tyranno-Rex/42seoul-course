// Now, time to move on more serious things. Let’s develop something weird.
// The std::stack container is very nice. 
// Unfortunately, it is one of the only STL Containers that is NOT iterable. 
// That’s too bad.
// But why would we accept this? 
// Especially if we can take the liberty of butchering the original stack to create missing features.
// To repair this injustice, you have to make the std::stack container iterable.
// Write a MutantStack class. 
// It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.
// Of course, you will write and turn in your own tests to ensure everything works as expected.
#pragma once

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack() : std::stack<T>()
        std::cout << "Default Constructor called" << std::endl;
    MutantStack(const MutantStack &src) : std::stack<T>(src)
        std::cout << "Copy Constructor called" << std::endl;
    ~MutantStack()
        std::cout << "Destructor called" << std::endl;
    MutantStack &operator=(const MutantStack &src)
    {
        if (this != &src)
            std::stack<T>::operator=(src);
        return (*this);
    }

    typename std::stack<T>::container_type::iterator begin()
        return this->c.begin();
    typename std::stack<T>::container_type::iterator end()
        return this->c.end();
};