#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cassert>

class PmergeMe
{
private:

public:
	PmergeMe(int ac, char **av);
	template <typename T>
	void display(const T& container);
	void mergeInsertSortDeque(std::deque<int>& arr);
	void mergeInsertSortList(std::list<int>& arr);
	void fordJohnson(std::deque<int>& arr1, std::deque<int>& arr2, std::deque<int>& result);
	void fordJohnson(std::list<int>& arr1, std::list<int>& arr2, std::list<int>& result);
	void PrintAll(std::deque<int> deque_sort_algo, std::list<int> list_sort_algo);
};