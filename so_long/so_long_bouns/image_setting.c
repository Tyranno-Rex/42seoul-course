/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:38 by eunjeong          #+#    #+#             */
/*   Updated: 2023/03/31 13:28:41 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collect(const char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_destroy_images(t_gameinfo *g_data)
{
	mlx_destroy_image(g_data->mlx_p, g_data->wall);
	mlx_destroy_image(g_data->mlx_p, g_data->space);
	mlx_destroy_image(g_data->mlx_p, g_data->player);
	mlx_destroy_image(g_data->mlx_p, g_data->collec);
	mlx_destroy_image(g_data->mlx_p, g_data->exit);
	mlx_destroy_image(g_data->mlx_p, g_data->turtle);
}

void	ft_load_images(t_gameinfo *g_data)
{
	g_data->wall = ft_xpm2image(g_data->mlx_p, "textures/brick.xpm");
	g_data->space = ft_xpm2image(g_data->mlx_p, "textures/grass.xpm");
	if (g_data->aspect == 'L')
		g_data->player = ft_xpm2image(g_data->mlx_p,
				"textures/mario_left.xpm");
	else if (g_data->aspect == 'R')
		g_data->player = ft_xpm2image(g_data->mlx_p,
				"textures/mario_right.xpm");
	else if (g_data->aspect == 'F')
		g_data->player = ft_xpm2image(g_data->mlx_p,
				"textures/mario_front.xpm");
	else if (g_data->aspect == 'B')
		g_data->player = ft_xpm2image(g_data->mlx_p,
				"textures/mario_back.xpm");
	g_data->turtle = ft_xpm2image(g_data->mlx_p, "textures/turtle.xpm");
	g_data->collec = ft_xpm2image(g_data->mlx_p, "textures/star.xpm");
	g_data->exit = ft_xpm2image(g_data->mlx_p, "textures/pipe.xpm");
}

void	ft_collect(t_gameinfo *g_data)
{
	g_data->nb_collec--;
	g_data->moves_counter++;
	ft_printf("Collected!\n");
}

void	ft_finish_game(t_gameinfo *g_data)
{
	if (g_data->nb_collec == 0 || g_data->attacked == 1)
	{
		mlx_destroy_window(g_data->mlx_p, g_data->mlx_w);
		if (g_data->attacked == 0)
			ft_printf("The game is finished, you win!");
		else
			ft_printf("Game over!");
		exit(0);
	}
}
