#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Span
{
private:
    unsigned int        _size;
    std::vector<int>    _container;

public:
    Span(void);
    Span(unsigned int N);
    ~Span(void);

    void addNumber(int N);
    unsigned int printsize(void);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
};

Span::Span(void): _size(0) 
{
    std::cout << "Span is Generated\n";
}

Span::Span(unsigned int N): _size(N) 
{
    std::cout << "Span is Generated\n";
}

Span::~Span(void){
    std::cout << "Span is Destroyed\n";
}

void Span::addNumber(int N)
{
    if (this->_container.size() < this->_size){
        if (find(this->_container.begin(), this->_container.end(), N) == this->_container.end())
            this->_container.push_back(N);
        else    
            throw std::runtime_error("element is already in this container\n");
    }
    else
        throw std::runtime_error("Container is full");
}

unsigned int Span::shortestSpan(void){
    std::sort(this->_container.begin(), this->_container.end());
    unsigned int shortlen = INT_MAX;

    for (unsigned int i=0; i<this->_container.size()-1; i++){
        unsigned int tmp = this->_container.at(i+1)-this->_container.at(i);
        if (shortlen > tmp) shortlen = tmp;
    }
    return shortlen;
}

unsigned int Span::longestSpan(void){
    std::sort(this->_container.begin(), this->_container.end());
    return (this->_container.at(this->_container.size() - 1) - this->_container.at(0));
}


unsigned int Span::printsize(void)
{
    return this->_size; 
}

