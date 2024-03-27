#include <type_traits>
template <typename T>
void PmergeMe::fordJohnson(T &arr1, T &arr2, T &result)
{
    if (std::is_same<T, std::deque<typename T::value_type, typename T::allocator_type>>::value) {
        mergeInsertSortDeque(arr1);
        mergeInsertSortDeque(arr2);
        std::deque<int>::iterator it1 = arr1.begin();
        std::deque<int>::iterator it2 = arr2.begin();

    } else if (std::is_same<T, std::list<typename T::value_type, typename T::allocator_type>>::value) {
        mergeInsertSortList(arr1);
        mergeInsertSortList(arr2);
        std::list<int>::iterator it1 = arr1.begin();
        std::list<int>::iterator it2 = arr2.begin();
    } 
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