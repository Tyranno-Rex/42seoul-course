#include "easy.hpp"

int main(){
    std::vector<int> _vector;
    std::list<int>   _list;
    std::deque<int>  _deque;

    for (int i =0; i<10; i++){
        _vector.push_back(i);
        _list.push_back(i);
        _deque.push_back(i);
    }

    int n_vector = easyfind(_vector, 1);
    int n_list = easyfind(_list, 4);
    int n_deque = easyfind(_deque, 6);
    std::cout << "is in container\n";
    std::cout << "vector location: " <<  n_vector << "\n";
    std::cout << "list   location: " <<  n_list << "\n";
    std::cout << "deque  location: " <<  n_deque << "\n";

    n_vector = easyfind(_vector, 111);
    n_list = easyfind(_list, 20);
    n_deque = easyfind(_deque, 31);

    std::cout << "isn't in container\n";
    n_vector = easyfind(_vector, 1);
    n_list = easyfind(_list, 1);
    n_deque = easyfind(_deque, 1);
    std::cout << "isn't in container\n";
    std::cout << "vector location: " <<  n_vector << "\n";
    std::cout << "list   location: " <<  n_list << "\n";
    std::cout << "deque  location: " <<  n_deque << "\n";
}
