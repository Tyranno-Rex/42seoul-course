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
    std::cout << "Time to process a range of " << deque_sort_algo.size() 
        << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << list_sort_algo.size() 
        << " elements with std::list container: " << time2 << " us" << std::endl;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return; 
    }
    std::deque<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::deque<int> right(arr.begin() + arr.size() / 2, arr.end());
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    arr.clear();
    std::deque<int>::iterator it1 = left.begin();
    std::deque<int>::iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 < *it2) {
            arr.push_back(*it1);
            ++it1;
        } else {
            arr.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != left.end()) {
        arr.push_back(*it1);
        ++it1;
    }

    while (it2 != right.end()) {
        arr.push_back(*it2);
        ++it2;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    if (arr.size() <= 1) {
        return; 
    }
    std::list<int> left, right;
    std::list<int>::iterator it = arr.begin();
    for (int i = 0; i < int(arr.size()) / 2; ++i) {
        left.push_back(*it);
        ++it;
    }
    while (it != arr.end()) {
        right.push_back(*it);
        ++it;
    }
    mergeInsertSortList(left);
    mergeInsertSortList(right);
    arr.clear();
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            arr.push_back(left.front());
            left.pop_front();
        } else {
            arr.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) {
        arr.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        arr.push_back(right.front());
        right.pop_front();
    }
}
