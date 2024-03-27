#include "serialization.hpp"
// lack  : \033[0;30m
// Red    : \033[0;31m
// Green  : \033[0;32m
// Yellow : \033[0;33m
// Blue   : \033[0;34m
// Purple : \033[0;35m
// Cyan   : \033[0;36m
// White  : \033[0;37m

int main(){
    serialization serial;
    Data            data;

    data.data = "test comment";

    std::cout                   << "Data:                   \033[0;33m"<< data.data << "\n";
    
    uintptr_t serial_data =  serial.serialize(&data);

    std::cout << "\033[0;37m"   << "Data serialize:         \033[0;32m" << serial_data << "\n";

	Data *data2 = serial.deserialize(serial.serialize(&data));
    std::cout << "\033[0;37m"   << "reserialize Data:       \033[0;33m" << data2->data << "\n";
    return 0;
}