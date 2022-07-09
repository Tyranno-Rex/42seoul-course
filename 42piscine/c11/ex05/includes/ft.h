#ifndef FT_H
# define FT_H

#include <unistd.h>
long long func_multiply(char *num1, char *num2);
long long func_plus(char *num1, char *num2);
long long func_minus(char *num1, char *num2);
long long func_divide(char *num1, char *num2);
void	ft_putnbr(int the_num);
void	func_cal(int the_num);
void	func_printer(int the_num);
int     func_str_to_int(char *str);

#endif