#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include "./../get_next_line/get_next_line.h"
#include "./../ft_printf/ft_printf.h"
#include "./../libft/libft.h"

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

// 이번 프로젝트에서 사용하는 구조체들 
typedef struct s_map
{
	int character;
	int	star;
	int exit;
} t_map;

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
	void	*collec;
	void	*exit;

	int		px;
	int		py;
	char	player_side;
	int		moves_counter;
	int		nb_collec;
}	t_gameinfo;


/*main.c*/
static void	ft_run_solong(const char *map_path);
void 		ft_check_av(int ac, char **av);

/*map_can_clear.c*/
void		ft_check_can_clear(const char **map);
void		ft_flood_fill(char **map, int x, int y);

/*map_checker.c*/
void		ft_check_what(t_map *check, char element);
void		ft_check_border(const char **map);
void		ft_check_character(const char **map);
void		ft_check_character_2(t_map *check);
void		ft_check_element_init(t_map *check);

/*map_copy.c*/
char		**ft_copymap(const char **map);

/*map_info.c*/
int 		*ft_player_pos(const char **map);

/*map_read.c*/
char		**ft_read_map(const char *path);
int			ft_check_line_len(int fd, int len, char *map_return, char *line);
static char	*ft_static_strjoin(char *s1, char *s2);

/*map_utils*/
void 		ft_map_validator(const char **map);
int			ft_map_height(const char** map);

#endif
