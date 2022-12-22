#include "../include/ft_printf.h"

int main()
{
    int a;
    // printf("\n");
    ft_printf("c test result: %c\n", 'c');
    ft_printf("s test result: %s\n", "hello world");
    ft_printf("d test result: %d\n", 10);
    ft_printf("u plus test result: %u\n", 4294967295);
    ft_printf("u minus test result: %u\n", -100);
    ft_printf("p test result: %p\n", &a);
    return (0);
}