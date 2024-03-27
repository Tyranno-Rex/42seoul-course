#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include <ctime>
#include <cstdlib>

// • Construction with no parameter: Creates an empty array.

// • Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
//     Tip: Try to compile int * a = new int(); then display *a.

// • Construction by copy and assignment operator. In both cases, modifying either the
//     original array or its copy after copying musn’t affect the other array.

// • You MUST use the operator new[] to allocate memory.
//      Preventive allocation (allocating memory in advance) is forbidden. 
//      Your program must never access nonallocated memory.

// • Elements can be accessed through the subscript operator: [ ].

// • When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.

// • A member function size() that returns the number of elements in the array. This
//     member function takes no parameter and musn’t modify the current instance.


template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    Array(void);
    Array(unsigned int size);
    Array(const Array &src);
    ~Array(void);
    
    Array &operator=(const Array &src);
    T& operator [](unsigned int i);
    
    unsigned int size();
    void printAll(void);
};

template <typename T>
Array<T>::Array(void){
    this->_array = new T[0];
    this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size){
    this->_array = new T[size];
    this->_size = size;
}

template <typename T>
Array<T>::Array(const Array &src){
    this->_size = src._size;
    this->_array = new T[this.size()];
    for (int i=0; i<src._size; i++){
        this->_array[i] = src._array[i];
    }
    *this = src;
}

template <typename T>
Array<T>::~Array(void){
    if (_array != NULL)
        delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src){
    this->_size = src._size;
    this->_array = new T[this->_size];
    for (unsigned int i=0; i<src._size; i++){
        this->_array[i] = src._array[i];
    }
    return (*this);
}

template <typename T>
// • When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
T& Array<T>::operator[](unsigned int i){
    if (i >= (this->_size)){
        throw std::out_of_range("index is out of range\n");
    }
    return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size(){
    return (this->_size);
}

template <typename T>
void Array<T>::printAll(void){
    for (unsigned int i=0; i<this->_size; i++){
        std::cout << this->_array[i] << " ";
    }
}