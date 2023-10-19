#include "BitcoinExchange.hpp"

int check_date_and_price(std::string const date, std::string const price){
	int 	year 	= atoi(date.substr(0, 4).c_str());
	int 	month	= atoi(date.substr(5, 2).c_str());
	int 	day 	= atoi(date.substr(8, 2).c_str());
	float 	num 	= 0;
	

	if (date.length() != 10) {
		std::cerr << "ERROR : date format is wrong\n";
		return 0;
	}

	if (!(2009 <= year  && year  <= 2022 
		&&   1 <= month && month <= 12 
		&&   1 <= day   && day   <= 31)) {
		std::cerr << "ERROR: date's data is wrong\n";
		return 0;
	}

	try
	{
		num = std::strtof(price.c_str(), NULL);
	}
	catch (std::out_of_range const &e)
	{
		std::cerr << "ERROR: price cann't be changed to number" << std::endl;
		return 0;
	}
	
	if (num < 0) {
		std::cerr << "Error: Negative value" << std::endl;
		return 0;
	}

	if (num > 1000) {
		std::cerr << "Error: Value too large" << std::endl;
		return 0;
	}

	return 1;

}


void read_data(std::fstream &file, BitcoinExchange &btc, int version){
	std::string date;
	std::string value;
	std::string line;
	float		price;
	
	std::getline(file, line);
	while (std::getline(file, line)) {
		date = line.substr(0, 10);
		try{
			if (version	== 1)
				value = line.substr(line.find(',') + 1);
			else if (version == 2)
				value = line.substr(line.find('|') + 1);
		}
		catch ( std::out_of_range const &e ){
			std::cerr << "Error: no value" << std::endl;
			continue ;
		}
		if (version == 1)
			btc.push(date, value);
		else
			if (check_date_and_price(date, value)){
				price = btc.calculatePrice(date, atof(value.c_str()));
				std::cout << date << " =>" << value << " = " << price << std::endl;
			}
	}
}

int main( int ac, char **av ) {
	BitcoinExchange btc;

	if (ac != 2) {
		std::cerr << "ERROR : ac is must be 2\n";
		return 1;
	}
	std::fstream file;
	file.open("data.csv", std::fstream::in);
	read_data(file, btc, 1);
	file.close();

	file.open(av[1], std::fstream::in);
	read_data(file, btc, 2);
	file.close();
	return 0;
}