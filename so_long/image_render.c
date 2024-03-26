/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:36:46 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/18 12:36:51 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_destory_images(t_data *data)
{
	mlx_destroy_image(data->mlx_p, data->mario);
	mlx_destroy_image(data->mlx_p, data->star);
	mlx_destroy_image(data->mlx_p, data->pipe);
	mlx_destroy_image(data->mlx_p, data->brick);
	mlx_destroy_image(data->mlx_p, data->grass);
}

int	ft_put_image(t_data *data, void *img, int x, int y)
{
	void	*mp;
	void	*wp;

	mp = data->mlx_p;
	wp = data->mlx_w;
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

void	*ft_new_window(t_data *data)
{
	int		w;
	int		h;
	void	*ptr;

	w = data->map_w;
	h = data->map_h;
	ptr = mlx_new_window(data->mlx_p, w, h, "so_long");
	if (!ptr)
		ft_show_error("mlx_new_window function fails!");
	return (ptr);
}
