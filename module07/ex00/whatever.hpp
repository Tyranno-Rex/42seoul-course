#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>


// • swap: Swaps the values of two given arguments. Does not return anything.

// • min: Compares the two values passed in its arguments and returns the smallest one. 
//         If the two of them are equal, then it returns the second one.

// • max: Compares the two values passed in its arguments and returns the greatest one.
//         If the two of them are equal, then it returns the second one.

template<typename T>
void swap(T &a, T &b){
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T &min(T &a, T &b){
    if (a >= b)
        return b;
    else
        return a;
}

template<typename T>
T &max(T &a, T &b){
    if (a <= b)
        return b;
    else
        return a;
}

#endif // !WHATEVER_HPP