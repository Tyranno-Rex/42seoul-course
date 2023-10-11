#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "argc must be 2\n";
        return 0;
    }
    
    std::map<std::string, double> btc_db;
    
    std::string     st_buf;
    std::fstream    fs_data_csv;
    fs_data_csv.open("data.csv", std::ios::in);
    int i = 0;
    while (!fs_data_csv.eof()){
        std::getline(fs_data_csv, st_buf, '\n');
        unsigned int date_loc = st_buf.find(",", 0);
        
        // checkformat
        if (i == 0){
            // check_format( ) <- check first line is right format
            i = 1;
        }else{ // make map
            std::string btc_date = st_buf.substr(0, date_loc-1);
            std::string btc_value_str = st_buf.substr(date_loc+1, st_buf.length());
            const char *_string = btc_value_str.c_str();
            double btc_value = atof(_string);
            btc_db.insert(std::pair<std::string, double>(btc_date, btc_value));
        }
    }
    fs_data_csv.close();

    // input.txt 정리
    std::string line;
    std::ifstream file_input(argv[1]);
    std::map<std::string, double> input_db;
    i = 1;
    if (file_input.is_open()){
        while (!file_input.eof()){
            std::getline(file_input, st_buf, '\n');
            unsigned int date_loc = st_buf.find("|", 0);
            
            // checkformat
            if (i == 1){
                // check_format( ) <- check first line is right format
                i = 0;
            }else{ // make map
                std::string btc_date_target = st_buf.substr(0, date_loc-1);
                std::string btc_value_str_target = st_buf.substr(date_loc+1, st_buf.length());
                const char *_string_target = btc_value_str_target.c_str();
                double ex_value = atof(_string_target);
                input_db.insert(std::pair<std::string, double>(btc_date_target, ex_value));
                // std::cout <<  "date: " << btc_date_target << " ";
                // std::cout << "\nexchange Rate: " <<  ex_value << "\n\n\n\n";
            }
        }
        file_input.close();
    }else{
        std::cout << "Error file cannot opened\n";
        return 1;
    }

    std::map<std::string, double>::iterator it = input_db.begin();
    while (it != input_db.end())
    {
        std::string target_date = it->first;
        std::cout << target_date << "\n";
        ++it;
    }





    return 0;    
}
