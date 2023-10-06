#include "array.hpp"


#define lack    "\033[0;30m"
#define Red     "\033[0;31m"
#define Green   " \033[0;32m"
#define Yellow  " \033[0;33m"
#define Blue    " \033[0;34m"
#define Purple  " \033[0;35m"
#define Cyan    " \033[0;36m"
#define White   "\033[0;37m"

int main(){
    Array<char> Array_Char(10);
    Array<int> Array_Int(10);
    Array<double> Array_Double(10);
    Array<std::string> Array_String(10);

    srand(time(NULL));
    for (unsigned int i=0; i<Array_Char.size(); i++){
        int char_var = rand()%89 + 33;
        int int_var = rand()%INT_MAX;
        double double_var = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        
        Array_Char[i] = char_var;
        Array_Int[i] = int_var;
        Array_Double[i] = double_var;
    }

    std::cout << Red << "ARRAY CHAR: " << White;
    Array_Char.printAll();
    std::cout << "\n\n";
    
    std::cout << Red << "ARRAY INT: " << White;
    Array_Int.printAll();
    std::cout << "\n\n";

    std::cout << Red << "ARRAY DOUBLE: " << White;
    Array_Double.printAll();
    std::cout << "\n\n";

    Array<int> tmp_int_Array[10];
    *tmp_int_Array=Array_Int;

    std::cout << Red << "ARRAY COPY: " << White;
    tmp_int_Array->printAll();
    std::cout << "\n\n";

}