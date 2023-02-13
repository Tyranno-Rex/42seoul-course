#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include "./../lib/libft.h"

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
	char	**map;
	char	player_aspect;

	int		wh;
	int		px;
	int		py;
	int		map_w;
	int		map_h;
	int		star_total;
	int		moves_counter;

	void	*star;
	void	*mlx_p;
	void	*mlx_w;
	void	*brick;
	void	*grass;
	void	*player;
	void	*chimney;

}	t_data;

/*image.c*/
void		ft_img_setting(t_data *data);
void		ft_destroy_image(t_data *data);

/*main.c*/
static int	ft_end_game(t_data *data);
static int 	ft_player_controller(int wasd, t_data *data);
static void	ft_run_solong(const char *map_path);
void 		ft_check_av(int ac, char **av);

/*map_can_clear.c*/
void		ft_flood_fill(char **map, int x, int y);
void		ft_check_can_clear(char **map);
void		ft_check_map_clear(char **map, int x, int y);

/*map_checker.c*/
void		ft_check_border(const char **map);
void		ft_check_what(t_map *check, char element);
void		ft_check_character_2(t_map *check);
void		ft_check_element_init(t_map *check);
void		ft_check_character(const char **map, t_map *g_elementx);

/*map_copy.c*/
char		**ft_copymap(const char **map);

/*map_info.c*/
int 		*ft_player_pos(const char **map);

/*map_read.c*/
static char	*ft_static_strjoin(char *s1, char *s2);
void		ft_check_line_len(char *line, int len);
char		**ft_read_map(const char *path);

/*map_utils.c*/
void 		ft_map_validator(const char **map, t_map *g_element);
int			ft_map_height(const char **map);

/*player_controller.c*/
static void	ft_player_front(t_data *data);
static void	ft_player_left(t_data *data);
static void	ft_player_down(t_data *data);
static void	ft_player_right(t_data *data);
void		ft_player_update(int keycode, t_data *data);

/*player_state.c*/
void		ft_star_collect(t_data *data);
void		ft_check_finish(t_data *data);

/*struct_init.c*/
void		ft_struct_init(t_data *data, t_map *g_element);

/*window_create.c*/
void		*ft_create_window(t_data *data);

/*window_draw.c*/
int			ft_put_img(t_data *data, void *img, int x, int y);
void		ft_draw_window(t_data *data);

#endif
