#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
    std::string     st;
    std::fstream    fs;

    if (argc < 2){
        std::cerr << "argc must be 2\n";
        return 0;
    }
    fs.open(argv[1], std::ios::in);
    int i = 0;
    while (!fs.eof()){
        std::getline(fs, st, ',');
        std::cout << st;
        if (i%2==1)
            std::cout << " | ";  
        else
            std::cout << "\n"; 
        i++;
    }
    fs.close();
    return 0;    
}