#include "whatever.hpp"

// int main( void ) {
// 	int A = 1290129;
// 	int B = 3813789;

// 	std::cout << "\n";
// 	std::cout << "A: " << A << "\n";
// 	std::cout << "B: " << B << "\n\n";
	
// 	::swap( A, B );
// 	std::cout << "after swap: \n";
// 	std::cout << "A: " << A << "\n";
// 	std::cout << "B: " << B << "\n\n";

// 	std::cout << "\nmin test:\n"<< ::min(A, B); 
// 	std::cout << "\nmax test:\n"<< ::max(A, B);
// 	std::cout << "\n";
// 	return 0;
// }

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}