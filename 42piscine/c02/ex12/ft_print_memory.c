/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:38:30 by eunjeong          #+#    #+#             */
/*   Updated: 2022/05/25 11:38:32 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	func_hex_printer(long long addr)
{
	char	i;

	if (addr > 15)
	{
		func_hex_printer(addr / 16);
		i = "0123456789abcdef"[addr % 16];
		write(1, &i, 1);
	}
	else
	{
		i = "0123456789abcdef"[addr % 16];
		write(1, &i, 1);
	}
}

void	func_sixteen(long long addr)
{
	long long	the_num;
	int			the_zero;

	the_num = addr;
	the_zero = 0;
	while (the_num)
	{
		++the_zero;
		the_num /= 16;
	}
	the_num = 0;
	while (the_zero + the_num < 16)
	{
		write(1, "0", 1);
		the_num++;
	}
	func_hex_printer(addr);
}

void	func_string(unsigned char *addr, unsigned int the_num)
{
	unsigned int	i;

	i = 0;
	while (i < the_num)
	{
		if (31 < *(addr + i) && *(addr + i) < 127)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		++i;
	}
}

void	func_two_six(unsigned char *addr, unsigned int the_num)
{
	unsigned int	the_pos;
	char			i1;
	char			i2;

	the_pos = -1;
	while ((unsigned int)++the_pos < the_num)
	{
		if (the_pos % 2 == 0)
			write(1, " ", 1);
		i1 = "0123456789abcdef"[addr[the_pos] / 16];
		i2 = "0123456789abcdef"[addr[the_pos] % 16];
		write(1, &i1, 1);
		write(1, &i2, 1);
	}
	while (the_pos < 16)
	{
		if (the_pos % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		the_pos++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	the_num;
	int				i;

	i = 0;
	while (size > 0)
	{
		if (size / 16 > 0)
		{
			the_num = 16;
			size -= the_num;
		}
		else
		{
			the_num = size % 16;
			size -= the_num;
		}
		func_sixteen((long long)addr + i);
		write(1, ":", 2);
		func_two_six(addr + i, the_num);
		write(1, " ", 1);
		func_string(addr + i, the_num);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
