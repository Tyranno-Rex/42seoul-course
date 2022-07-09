#include "includes/ft.h"

long long func_plus(char *num1, char *num2)
{
    int number1;
    int number2;

    number1 = func_str_to_int(num1);
    number2 = func_str_to_int(num2);
	return (number1 + number2);
}

long long func_minus(char *num1, char *num2)
{
    int number1;
    int number2;

    number1 = func_str_to_int(num1);
    number2 = func_str_to_int(num2);
	return (number1 - number2);
}

long long func_divide(char *num1, char *num2)
{
    int number1;
    int number2;

    number1 = func_str_to_int(num1);
    number2 = func_str_to_int(num2);
	return (number1 / number2);
}

long long func_multiply(char *num1, char *num2)
{
    int number1;
    int number2;

    number1 = func_str_to_int(num1);
    number2 = func_str_to_int(num2);
	return (number1 * number2);
}