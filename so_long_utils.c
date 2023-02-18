/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:39:15 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/18 12:39:16 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_pro(const char *str, char c)
{
	int		the_num;

	the_num = 0;
	if (c == '\n')
	{
		while (*str != '\n' && *str)
		{
			the_num++;
			str++;
		}
	}
	if (c == '\0')
	{
		while (*str != '\0')
		{
			the_num++;
			str++;
		}
	}
	return (the_num);
}

void	ft_show_error(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_finish_game(t_data *data)
{
	if (data->nb_collec == 0)
	{
		mlx_destroy_window(data->mlx_p, data->mlx_w);
		ft_printf("The game is finished, you win!");
		exit(EXIT_SUCCESS);
	}
}
