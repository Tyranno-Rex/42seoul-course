#include "iter.hpp"


template <typename T> void HelloCPP(T len){
    for (int i = 0; i < len; i++){
        std::cout << "HelloCPP\n";
    }
    std::cout << "\n";
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    
    iter(arr, 5, HelloCPP);
}