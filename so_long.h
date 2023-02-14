#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

// 이번 프로젝트에서 사용하는 구조체들 
typedef struct s_map
{
	int character;
	int character_x;
	int character_y;
	int	star;
	int exit;
} t_map;

typedef struct s_data
{
	void	*mario;
	void	*star;
	void	*pipe;
	void	*brick;
	void	*grass;
	void	*mlx_p;
	void	*mlx_w;

	char	**map;
	char	aspect;

	int		map_w;
	int		map_h;
	int		wh;
	int		px;
	int		py;
	int		moves_counter;
	int		nb_collec;
}	t_data;

/*image_render*/
void		ft_destory_images(t_data *data);
int			ft_put_image(t_data *data, void *img, int x, int y);
void		*ft_xpm2image(void *mlx_p, char *xpm);
void		*ft_new_window(t_data *data);

/*image_setting*/
void		ft_load_images(t_data *data);
void		ft_draw_characters(t_data *data);

/*main*/
void 		ft_check_av(int ac, char **av);

/*map_checker*/
void		ft_map_validator(const char **map, t_map *t_data);

/*map is clear*/
int			*ft_choose_xy(const char **map);
char		**ft_copymap(const char **map);
void		ft_flood_fill(char **map, int x, int y);
void		ft_check_validpath(const char **map);

/*map_reader*/
char		**ft_read_map(const char *path);


/*map_utils*/
int			ft_count_collect(const char **map);
void		ft_collect(t_data *data);
int			ft_search_tab(const char **tab, char c);
int			ft_tab_size(const char **tab);

/*player_controller*/
void		ft_move_player(int keycode, t_data *data);

/*so_long_utils*/
int			ft_strlen_n(const char *str, char c);
void		ft_show_error(const char *msg);
void		ft_finish_game(t_data *data);

/*struct_init*/
void		ft_struct_initializer(t_data *data);
void		ft_struct_initializer_2(t_map *m_data);

#endif
