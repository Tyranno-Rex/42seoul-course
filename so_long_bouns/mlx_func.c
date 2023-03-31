/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:17 by eunjeong          #+#    #+#             */
/*   Updated: 2023/03/31 12:44:17 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_image(t_gameinfo *g_data, void *img, int x, int y)
{
	void	*mp;
	void	*wp;

	mp = g_data->mlx_p;
	wp = g_data->mlx_w;
	return (mlx_put_image_to_window(mp, wp, img, x, y));
}

void	*ft_xpm2image(void *mlx_p, char *xpm)
{
	int		wh;
	void	*ptr;

	wh = 64;
	ptr = mlx_xpm_file_to_image(mlx_p, xpm, &wh, &wh);
	if (!ptr)
		ft_show_error("mlx_xpm_file_to_image function fails!");
	return (ptr);
}

void	*ft_new_window(t_gameinfo *g_data)
{
	int		w;
	int		h;
	void	*ptr;

	w = g_data->map_w;
	h = g_data->map_h;
	ptr = mlx_new_window(g_data->mlx_p, w, h, T);
	if (!ptr)
		ft_show_error("mlx_new_window function fails!");
	return (ptr);
}
