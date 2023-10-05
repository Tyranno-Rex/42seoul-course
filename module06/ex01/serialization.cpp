#include "serialization.hpp"

serialization::serialization(void)
{
    // std::cout << "serialization is Generated\n";
}

serialization::serialization(const serialization &src)
{
    // std::cout << "Copy serialization is Generated\n";
    *this= src;
}

serialization::~serialization(void)
{
    // std::cout << "serialization is Destroyed\n";
}

// reinterpret_cast<new_type>(expression)
// reinterpret_cast<바꿀 타입>(대상)

uintptr_t	serialization::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}