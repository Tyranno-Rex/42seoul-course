#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){
	// std::cout <<  "btc Exchange is Generated\n";
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cp){
	// std::cout <<  "btc Exchange copy is Generated\n";
	*this = cp;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &cp){
	// std::cout <<  "btc Exchange copy is Generated\n";
	if (this != &cp)
		this->_data = cp._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void){
	// std::cout <<  "btc Exchange is Deleted\n";
}

void BitcoinExchange::push( std::string const date, std::string const price ) {
	this->_data.insert(std::pair< std::string, float >(date, atof(price.c_str()))); // this will only insert if the key doesn't exist
}

void BitcoinExchange::pop( std::string const date ) {
	this->_data.erase(date);
}

float BitcoinExchange::calculatePrice( std::string date, float amount ) {
	std::map< std::string, float >::iterator pair = this->_data.lower_bound(date);

	if (pair == this->_data.end()) {
		std::cerr << "Error: Wrong Value\n";
		return 0;
	}
	return (amount * pair->second);
}