/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:11:44 by eunjeong          #+#    #+#             */
/*   Updated: 2023/02/02 18:49:52 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# define KEYPRESS 2
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_UP 126

# define T "so_long"

typedef struct s_gameinfo
{
	char	**map;
	int		map_w;
	int		map_h;
	int		wh;

	void	*mlx_p;
	void	*mlx_w;

	void	*wall;
	void	*space;
	void	*player;
	void	*turtle;
	void	*collec;
	void	*exit;

	int		px;
	int		py;
	char	aspect;
	int		moves_counter;
	int		nb_collec;
	int		attacked;
}	t_gameinfo;

/*drawer.c*/
void	ft_draw_characters(t_gameinfo *g_data);
int		ft_render_enemy(t_gameinfo *g_data);
void	ft_put_moves_onscreen(t_gameinfo *g_data);

/*engine.c*/
void	ft_move_player(int keycode, t_gameinfo *g_data);

/*helper_func.c*/
int		ft_search_tab(const char **tab, char c);
int		ft_tab_size(const char **tab);
void	ft_show_error(const char *msg);
void	ft_struct_initializer(t_gameinfo *game_data);

/*map_checker.c*/
void	ft_map_validator(const char **map);

/*map_reader.c*/
char	**ft_read_map(const char *path);

/*mlx_func.c*/
int		ft_put_image(t_gameinfo *g_data, void *img, int x, int y);
void	*ft_xpm2image(void *mlx_p, char *xpm);
void	*ft_new_window(t_gameinfo *g_data);

/*solong_utils.c*/
int		ft_count_collect(const char **map);
void	ft_destroy_images(t_gameinfo *g_data);
void	ft_load_images(t_gameinfo *g_data);
void	ft_collect(t_gameinfo *g_data);
void	ft_finish_game(t_gameinfo *g_data);

/*vaild_path.c*/
int		*ft_choose_xy(const char **map);
char	**ft_create_fakemap(const char **map);
void	fill_flood(char **map, int x, int y);
void	ft_check_validpath(const char **map);

#endif