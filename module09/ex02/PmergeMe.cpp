#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int ac, char** av) {
    std::deque<int> deque_sort_algo;
    std::list<int>  list_sort_algo;
    for (int i = 1; i < ac; ++i) {
        int value = std::atoi(av[i]);
        assert(value > 0);
        deque_sort_algo.push_back(value);
        list_sort_algo.push_back(value);
    }
    PrintAll(deque_sort_algo, list_sort_algo);
}

void PmergeMe::PrintAll(std::deque<int> deque_sort_algo, std::list<int> list_sort_algo){
    std::cout << "Before: ";
    display(deque_sort_algo);

    clock_t start_time = clock();
    mergeInsertSortDeque(deque_sort_algo);
    clock_t end_time = clock();
    double time1 = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;

    start_time = clock();
    mergeInsertSortList(list_sort_algo);
    end_time = clock();
    double time2 = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(deque_sort_algo);
    std::cout << "Time to process a range of " << deque_sort_algo.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << list_sort_algo.size() << " elements with std::list container: " << time2 << " us" << std::endl;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(it2-1) > temp)
        {
            *it2 = *(it2-1);
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::fordJohnson(std::deque<int>& arr1, std::deque<int>& arr2, std::deque<int>& result)
{
    mergeInsertSortDeque(arr1);
    mergeInsertSortDeque(arr2);

    std::deque<int>::iterator it1 = arr1.begin();
    std::deque<int>::iterator it2 = arr2.begin();

    while (it1 != arr1.end() && it2 != arr2.end())
    {
        if (*it1 < *it2)
        {
            result.push_back(*it1);
            ++it1;
        }
        else
        {
            result.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != arr1.end())
    {
        result.push_back(*it1);
        ++it1;
    }

    while (it2 != arr2.end())
    {
        result.push_back(*it2);
        ++it2;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(--it2) > temp)
        {
            std::list<int>::iterator prev_it = it2;
            std::list<int>::iterator next_it = prev_it;
            ++next_it;
            *next_it = *prev_it;
        }
        std::list<int>::iterator next_it = it2;
        ++next_it;
        *next_it = temp;
    }
}

void PmergeMe::fordJohnson(std::list<int>& arr1, std::list<int>& arr2, std::list<int>& result)
{
    mergeInsertSortList(arr1);
    mergeInsertSortList(arr2);

    std::list<int>::iterator it1 = arr1.begin();
    std::list<int>::iterator it2 = arr2.begin();

    while (it1 != arr1.end() && it2 != arr2.end())
    {
        if (*it1 < *it2)
        {
            result.push_back(*it1);
            ++it1;
        }
        else
        {
            result.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != arr1.end())
    {
        result.push_back(*it1);
        ++it1;
    }

    while (it2 != arr2.end())
    {
        result.push_back(*it2);
        ++it2;
    }
}