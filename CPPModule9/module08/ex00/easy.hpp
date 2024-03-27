#ifndef EASY_HPP
#define EASY_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>


template <typename T>
int easyfind(T& container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw std::runtime_error("value is not in this container");
    return std::distance(container.begin(), iter);
}

#endif