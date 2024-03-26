/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:15 by eunjeong          #+#    #+#             */
/*   Updated: 2023/03/31 14:08:06 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_characters(t_gameinfo *g_data)
{
	int	x;
	int	y;

	y = 0;
	while (g_data->map[y])
	{
		x = 0;
		while (g_data->map[y][x])
		{
			if (g_data->map[y][x] == '1')
				ft_put_image(g_data, g_data->wall, x * 64, y * 64);
			else if (g_data->map[y][x] == '0')
				ft_put_image(g_data, g_data->space, x * 64, y * 64);
			else if (g_data->map[y][x] == 'P')
				ft_put_image(g_data, g_data->player, x * 64, y * 64);
			else if (g_data->map[y][x] == 'C')
				ft_put_image(g_data, g_data->collec, x * 64, y * 64);
			else if (g_data->map[y][x] == 'E')
				ft_put_image(g_data, g_data->exit, x * 64, y * 64);
			else if (g_data->map[y][x] == 'D')
				ft_put_image(g_data, g_data->turtle, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_put_moves_onscreen(t_gameinfo *g_data)
{
	char	*moves;

	moves = ft_itoa(g_data->moves_counter);
	mlx_string_put(g_data->mlx_p, g_data->mlx_w, 2, 0, 16777215, "Moves: ");
	mlx_string_put(g_data->mlx_p, g_data->mlx_w, 66, 0, 16777215, moves);
	free(moves);
	moves = NULL;
}
