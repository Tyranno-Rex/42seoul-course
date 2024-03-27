#include <iostream>
#include <string>

// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.

template<typename T> void iter(T *arr, int len, void (* f)(T const &)){
    for (int i  = 0; i < len; i++){
        f(arr[i]);
    }
}